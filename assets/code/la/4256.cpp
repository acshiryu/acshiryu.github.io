#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define setmax(a) memset(a,0x7f,sizeof(a))

vector<int>v[105];
int dp[205][105];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i,j;
		for(i=1;i<=n;i++)
			v[i].clear();
		for(i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int p;
		scanf("%d",&p);
		setmax(dp);
		for(i=0;i<=n;i++)
			dp[0][i]=0;
		for(i=1;i<=p;i++)
		{
			int k;
			scanf("%d",&k);
			for(j=1;j<=n;j++)
			{
				int bl=0;
				if(j==k)
					bl=0;
				else
					bl=1;
				dp[i][j]=dp[i-1][j]+bl;
				for(int d=0;d<v[j].size();d++)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][v[j][d]]+bl);
				}
			}
		}
		int ans=1000000000;
		for(i=1;i<=n;i++)
		{
			ans=min(dp[p][i],ans);
		}
		printf("%d\n",ans);
	}
    return 0;
}