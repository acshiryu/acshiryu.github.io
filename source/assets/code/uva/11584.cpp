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
#define setmax(a) memset(a,0x7f,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

const int maxn=1005;
char s[maxn];
int dp[maxn];
int hw[maxn];
int hw2[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		int i,j;
		for(i=1;i<=l;i++)
		{
			hw[i]=hw2[i]=0;
			for(j=0;i+j<=l&&i-j>0;j++)
			{
				if(s[i+j]==s[i-j])
					hw[i]++;
				else
					break;
			}
			for(j=0;i+j+1<=l&&i-j>0;j++)
			{
				if(s[i+j+1]==s[i-j])
					hw2[i]++;
				else
					break;
			}
		}
		zero(dp);
		for(i=1;i<=l;i++)
		{
			dp[i]=dp[i-1]+1;
			for(j=1;j<i;j++)
			{
				if(hw[j]+j-1>=i)
					dp[i]=min(dp[i],dp[2*j-i-1]+1);
				if(hw2[j]+j>=i)
					dp[i]=min(dp[i],dp[2*j-i]+1);
			}
		}
		printf("%d\n",dp[l]);
	}
    return 0;
}