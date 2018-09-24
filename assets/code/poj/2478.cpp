#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
usingnamespace std;
int phi[1000005];
int main()
{
    int i , j ;
    memset ( phi , 0 ,sizeof ( phi ) ) ;
    for ( i =2 ; i <=1000000 ; i ++ )
    {//筛选求phi
if ( ! phi [i] )
        {
            for ( j = i ; j <=1000000 ; j += i )
            {
                if ( ! phi [j] )
                    phi [j ] = j ;
                phi [j] = phi [j] / i * ( i -1 ) ;
            }
        }
    }
    int n ;
    while ( cin >> n  , n )
    {
        __int64 sum =0 ;
        for ( i =2 ; i <= n ; i ++ )
            sum += phi [i] ;
        cout<<sum<<endl;
    }
    return0;
}