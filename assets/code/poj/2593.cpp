#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005];
int dp[100005][2];
int i ;
int main()
{
    int n ;
    while ( scanf("%d",&n) , n )
    {

        int sum=0;
        for ( i = 0 ; i < n ; i ++ )
        {
            scanf ("%d", &a[i]) ;
            if (  i )
            {
                sum = max(sum+a[i],a[i]);
                dp[i][0]=max(sum,dp[i-1][0]);
            }
            else
                dp[i][0]=sum=a[i];
        }
        for ( i = n -1 ; i>=0 ; i -- )
        {
            if ( i != ( n - 1 ) )
            {
                sum = max(sum + a[i] , a[i]);
                dp[i][1]=max(sum,dp[i+1][1]);
            }
            else
                dp[i][1]=sum=a[i];
        }
        sum = -(1<<30) ;
        for ( i = 0 ; i < n - 1 ; i ++ )
            sum = max ( sum , dp[i][0]+dp[i+1][1] );
        printf("%d\n",sum);
    }
    return 0;
}