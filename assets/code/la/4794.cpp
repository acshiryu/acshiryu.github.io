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

int sum[40000];
int cnt[40000];
int dp[105][40000];
int ans[20];
int all;
bool DFS(int r,int s)
{
	if(dp[r][s]!=-1)
		return dp[r][s];
	int &rs =dp[r][s];
	if(cnt[s]==1)
		return rs=1;
	int c=sum[s]/r;
	for(int sx=(s-1)&s;sx;sx=(sx-1)&s)
	{
		int sy=s-sx;
		if(sum[sx]%r==0&&DFS(min(r,sum[sx]/r),sx)==1&&DFS(min(r,sum[sy]/r),sy)==1)
			return rs=1;
		if(sum[sx]%c==0&&DFS(min(c,sum[sx]/c),sx)==1&&DFS(min(c,sum[sy]/c),sy)==1)
			return rs=1;
	}
	return rs=0;
}
int main()
{
	int n,cas=1;
	while(scanf("%d",&n),n)
	{
		all=(1<<n)-1;
		int x;int y;
		scanf("%d%d",&x,&y);
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%d",&ans[i]);
		zero(sum);
		fone(dp);
		zero(cnt);
		for(i=1;i<=all;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					sum[i]+=ans[j];
					cnt[i]++;
				}
			}
		}

		if(sum[all]!=x*y||sum[all]%x!=0||DFS(min(x,y),all)==0)
			printf("Case %d: No\n",cas++);
		else
			printf("Case %d: Yes\n",cas++);
	}
    return 0;
}