#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105][105];
int sum[105];
int dp[105];
int main()
{
    int n ;
    while ( cin >> n )
    {
        int i , j , k , t;
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
                cin >> a[i][j] ;
        int sumall = - (1 << 30 );
        for ( i = 0 ; i < n  ; i ++ )
        {
            int sumdp;    
            for ( t = i + 1 ; t <= n ; t ++ )
            {
                for ( j = 0 ; j < n ; j ++ )
                {
                    int sumi = 0 ;
                    for ( k = i ; k < t ; k ++ )
                    {
                        sumi += a[k][j] ;
                    }
                     sum[j] = sumi ;
                    if ( j )
                        sumall = max ( sumall , sumdp = max ( sumdp + sum[j] , sum[j] ) ) ;
                    else
                       sumall = max ( sumall , sumdp = sum[j] ) ;
                }
            }
        }
        cout << sumall << endl ; 
    }
    return 0 ;
}