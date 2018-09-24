#include<iostream>
 #include<cstdlib>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 using namespace std;
 double q[105];
 int m[105];
 double dp[10005];
 int main()
 {
     int t ;
     cin >> t ;
     while ( t -- )
     {
         double p ;
         int n ;
         cin >> p >> n ;
         int i , j ;
         int sum = 0 ;
         for ( i = 0 ; i < n ; i ++ )
             cin >> m[i] >> q[i] , sum += m[i] ;
         memset ( dp , 0 , sizeof ( dp ) ) ;
         dp[0] = 1.0 ;
         for ( i = 0 ; i < n ; i ++ )
         {
             for ( j = sum ; j >= m[i] ; j -- )
             {
                 dp[j] = max ( dp [j] , dp [j-m[i]] * ( 1 - q[i] ) ) ;
             }
         }
         for ( j = sum ;  j >= 0 ; j -- )
             if ( dp [j] >= 1 - p )
             {
                 cout << j << endl;
                 break;
             }
     }
     return 0;
 }