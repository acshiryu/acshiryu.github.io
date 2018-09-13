/*
ID:shiryuw1
PROG:stamps
LANG:C++
*/
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

int dp[2000005];
int a[55];
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	int k,n,i,j,maxn=-1;;
	scanf("%d%d",&k,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}

	maxn*=k;
	for(i=1;i<=maxn;i++)
		dp[i]=(1<<25);
	dp[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=a[i];j<=maxn;j++)
		{
			dp[j]=min(dp[j-a[i]]+1,dp[j]);
		}
	}

	for(i=1;i<=maxn;i++)
		if(dp[i]>k)
			break;
	printf("%d\n",i-1);
    return 0;
}