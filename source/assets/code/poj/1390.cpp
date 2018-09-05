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

struct prog{
	int k;
	int num;
	int p;
}ans[205];
int dp[205][205][205];
int main()
{
	int T,TT=1;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int i,j,k;
		i=-1,k=-1;
		zero(ans);
		while(N--)
		{
			int a;
			scanf("%d",&a);
			if(a!=k)
				i++;
			ans[i].k=a;
			ans[i].num++;
			k=a;
		}
		int n=i+1;
		for(i=0;i<n;i++)
		{
			for(j=i-1;j>=0;j--)
			{
				if(ans[i].k==ans[j].k)
					break;
			}
			ans[i].p=j;
		}
		zero(dp);
		for(i=0;i<n;i++)
			for(j=0;j<200;j++)
				dp[i][i][j]=(ans[i].num+j)*(ans[i].num+j);
		for(j=1;j<n;j++)
		{
			for(i=0;i+j<n;i++)
			{
				for(k=0;k<200;k++)
				{
					dp[i][i+j][k]=dp[i][i+j-1][0]+(ans[i+j].num+k)*(ans[i+j].num+k);
					int p=ans[i+j].p;
					while(p>=i&&ans[i+j].num+k<200)
					{
						dp[i][i+j][k]=max(dp[i][i+j][k],dp[i][p][ans[i+j].num+k]+dp[p+1][i+j-1][0]);
						p=ans[p].p;
					}
				}
			}
		}
		printf("Case %d: %d\n",TT++,dp[0][n-1][0]);
	}
	return 0;
}