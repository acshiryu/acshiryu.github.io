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

int dp[105];
struct prog{
	int x;int y;int w;
}lj,old_lj,lj0;
int juli(prog i,prog j)
{
	return abs(i.x-j.x)+abs(i.y-j.y);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int C,n,i,j,k;
		scanf("%d",&C);
		scanf("%d",&n);
		memset(dp,0x7f,sizeof(dp));
		dp[0]=0;
		old_lj.x=0;
		old_lj.y=0;
		old_lj.w=0;
		lj0=old_lj;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&lj.x,&lj.y,&lj.w);
			int jl0=juli(lj,lj0);
			int tmp=dp[0]+jl0;
			dp[0]=tmp+jl0;;
			int jl=juli(lj,old_lj);
			for(j=C;j>=lj.w+old_lj.w;j--)
			{
				dp[j]=dp[j-lj.w]+jl;
				dp[0]=min(dp[0],dp[j]+jl0);
			}
			while(j>0)
			{
				dp[j]=0x7f7f7f7f;
				j--;
			}
			dp[lj.w]=min(dp[lj.w],tmp);
			old_lj=lj;
		}
		printf("%d\n",dp[0]);
		if(T)
			printf("\n");
	}
    return 0;
}