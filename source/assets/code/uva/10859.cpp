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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

vector<int>d[1005];
bool vis[1005][2];
int dp[1005][2];
const int bs=2000;
int DFS(int i,int j,int f)
{
	if(vis[i][j]==1)
		return dp[i][j];
	vis[i][j]=1;
	int k;
	int ans1,ans2;
	ans1=bs;
	for(k=0;k<d[i].size();k++)
	{
		if(d[i][k]!=f)
		{
			ans1+=DFS(d[i][k],1,i);
		}
	}
	if(f>=0&&(!j))
		ans1++;
	dp[i][j]=ans1;
	ans2=0;
	if(j||f<0)
	{
		for(k=0;k<d[i].size();k++)
		{
			if(d[i][k]!=f)
			{
				ans2+=DFS(d[i][k],0,i);
			}
		}
		if(f>=0)
			ans2++;
		dp[i][j]=min(ans1,ans2);
	}
	return dp[i][j];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		for(i=0;i<1005;i++)
			d[i].clear();
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			d[a].push_back(b);
			d[b].push_back(a);
		}
		zero(vis);
		zero(dp);
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(!vis[i][0])
				ans+=DFS(i,0,-1);
		}
		printf("%d %d %d\n",ans/bs,m-ans%bs,ans%bs);
	}
    return 0;
}