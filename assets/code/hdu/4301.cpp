#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

int dp[2][1005][2010];
const int mod = 100000007;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,i,j;
        scanf("%d%d",&n,&k);
        zero(dp);
        for(i=1;i<=n;i++)
            dp[0][i][1]=1,dp[1][i][1]=0;
        dp[1][1][2]=1;
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=2*i&&j<=k;j++)
            {
                dp[0][i][j]=( dp[0][i-1][j-1] + dp[0][i-1][j] + dp[1][i-1][j-1] + dp[1][i-1][j]*2 ) % mod;
                dp[1][i][j]=( dp[0][i-1][j-1]*2 +dp[0][i-1][j-2]+ dp[1][i-1][j-1]*2 + dp[1][i-1][j] + dp[1][i-1][j-2]) % mod;
            }
        }
        printf("%d\n",(dp[0][n][k]+dp[1][n][k])%mod);
    }
    return 0;
}