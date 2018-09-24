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

int a[10][10];
int sum[10][10];
long double dp[20][10][10][10][10];
long double count(int x,int y,int m,int n)
{
	long double ans= __int64(sum[m][n]-sum[m][y]-sum[x][n]+sum[x][y]);
	return ans*ans;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i,j,k;
		zero(sum);
		int num=0;
		for(i=1;i<=8;i++)
		{
			for(j=1;j<=8;j++)
			{
				scanf("%d",&a[i][j]);
				sum[i][j]=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1]+a[i][j];
				num+=a[i][j];
			}
		}
		int x,y;
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				for(x=i;x<=8;x++)
					for(y=j;y<=8;y++)
						dp[0][i][j][x][y]=count(i-1,j-1,x,y);	
		for(k=1;k<n;k++)
		{
			for(i=0;i<=8;i++)
			{
				for(j=0;j<=8;j++)
				{
					for(x=1;x+i<=8;x++)
					{
						for(y=1;y+j<=8;y++)
						{

							int t;
							dp[k][x][y][x+i][y+j]=long double((1)<<30);
							for(t=x;t<x+i;t++)
							{
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][t+1][y][x+i][y+j]+dp[0][x][y][t][y+j]);
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][x][y][t][y+j]+dp[0][t+1][y][x+i][y+j]);
							}
							for(t=y;t<y+j;t++)
							{
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][x][y][x+i][t]+dp[0][x][t+1][x+i][y+j]);
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][x][t+1][x+i][y+j]+dp[0][x][y][x+i][t]);
							}
						}
					}
				}
			}
		}
		long double ans=1.0*dp[n-1][1][1][8][8]/n-long double(1.0*num/n)*long double(1.0*num/n);
		printf("%.3lf\n",sqrt(ans));
	}
    return 0;
}