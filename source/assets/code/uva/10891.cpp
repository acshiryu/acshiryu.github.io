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

int dp[105][105];
int a[105];
int sum[105];
int f[105][105];
int g[105][105];
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int i,j,k;
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}

		for(i=1;i<=n;i++)
		{
			dp[i][i]=a[i];
			f[i][i]=a[i];
			g[i][i]=a[i];
		}

		for(i=n-1;i>=1;i--)
		{
			for(j=1;i+j<=n;j++)
			{
				int suma=sum[i+j]-sum[i-1];
				dp[i][i+j]=suma-min(0,min(f[i+1][i+j],g[i][i+j-1]));
				f[i][i+j]=min(dp[i][i+j],f[i+1][i+j]);
				g[i][i+j]=min(dp[i][i+j],g[i][i+j-1]);
			}
		}
		printf("%d\n",2*dp[1][n]-sum[n]);
	}
    return 0;
}