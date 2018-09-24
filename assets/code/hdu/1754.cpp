#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int num [ 2000200 ] ;
struct prig{
    int x ;        //起点
    int y ;        //终点
    int max ;    //从x到y的最大值（包括x和y）
} sum [ 4000400 ] ;
int build ( int k ,int x , int y )
{
    sum [ k ] . x = x ;
    sum [ k ] . y = y ;
    if( y == x )
    {
        sum [ k ] . max = num [ x-1 ] ;
        return num [ x-1 ] ;
    }

    int mid = ( x + y  ) / 2 ;
    int maxnum = max ( build ( 2 * k , x , mid  ) , build ( 2 * k + 1 ,mid + 1 , y ) ) ;
    sum [ k ] . max = maxnum ;
    return maxnum ;
}

int found ( int k ,int x , int y )
{
    if ( sum [ k ] . y < x )
        return 0 ;
    if ( sum [ k ] . x > y )
        return 0 ;
    if ( sum [ k ] . x >= x && sum [ k ] . y <= y )
        return  sum [ k ] . max ;
    return max ( found ( 2 * k , x , y ) , found ( 2 * k + 1 , x , y ) );
}

int updata ( int k ,int x , int y )
{
    if( sum [ k ] . x <= x && sum [ k ] . y >= x )
    {
        if ( sum [ k ] . x == x && sum [ k ] . y == x )
        {
            sum [ k ] . max = y;
            return y ;
        }
        sum [ k ] . max = max ( updata ( k * 2 , x , y ) , updata ( k * 2 + 1 , x ,y ) ) ;
    }
    return sum [ k ] . max ;
}

int main()
{
    int n , m;
    while ( cin >> n >> m )
    {
        int i ;
        for ( i = 0 ; i < n ; i ++ )
        {
            scanf ( "%d" , & num[i] );
        }

        build ( 1 , 1 , n );

        while ( m -- )
        {
            char op[10];
            int x , y ;
            scanf ( "%s%d%d" , op , & x , & y ) ;

            if ( strcmp ( op , "Q" ) == 0 )
            {
                printf ( "%d\n" , found ( 1 , x , y ) ) ;
            }
            else
            {
                num [ x - 1 ] = y ;
                updata ( 1 , x , y ) ;
            }
        }
    }
    return 0;
}