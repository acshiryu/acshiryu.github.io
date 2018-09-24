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

int p[20];
int dp[70000];
int c[70000];
int main()
{
	int n,cas=1;
	while(scanf("%d",&n),n)
	{
		int maxn=(1<<n)-1;
		int i,j,k;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			p[i]=1<<i;
			while(j--)
			{
				scanf("%d",&k);
				p[i]=p[i]|(1<<k);
			}
		}
		for(int s=0;s<=maxn;s++)
		{
			c[s]=0;
			for(i=0;i<n;i++)
			{
				if(s&(1<<i))
					c[s]=c[s]|p[i];
			}
		}

		zero(dp);
		for(int s=1;s<=maxn;s++)
		{
			//枚举集合s的子集s0，原来还可以这样！！！
			for(int s0=s;s0;s0=(s0-1)&s)
			{
				if(c[s0]==maxn)
				{
					dp[s]=max(dp[s],dp[s^s0]+1);
				}
			}
		}
		printf("Case %d: %d\n",cas++,dp[maxn]);
	}
    return 0;
}