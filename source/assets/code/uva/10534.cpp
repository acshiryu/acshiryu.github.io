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

int a[10005];
int t[10005];
int dp[10005];
int dp2[10005];
const int maxn=0x7fffffff;
int erfen(int i,int j,int k)
{
	while(i<j)
	{
		int m=(i+j)/2+1;
		if(t[m]>=k)
			j=m-1;
		else
			i=m;
	}
	return i;
}
int main()
{
	int n;
	while(~scanf("%d",&amp;n))
	{
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%d",&amp;a[i]);

		zero(dp);
		zero(dp2);
		zero(t);

		j=0;
		t[0]=-maxn;
		for(i=1;i<=n;i++)
		{
			if(a[i]>t[j])
			{
				j++;
				t[j]=a[i];
				dp[i]=j;
			}
			else
			{
				int k=erfen(0,j,a[i]);
				dp[i]=k+1;
				t[k+1]=a[i];
			}
		}

		zero(t);
		j=0;
		t[j]=-maxn;
		for(i=n;i>0;i--)
		{
			if(a[i]>t[j])
			{
				j++;
				t[j]=a[i];
				dp2[i]=j;
			}
			else
			{
				int k=erfen(0,j,a[i]);
				dp2[i]=k+1;
				t[k+1]=a[i];
			}
		}

		int ans=0;
		for(i=1;i<=n;i++)
			ans=max(ans,2*min(dp[i],dp2[i])-1);
		printf("%d\n",ans);
	}
    return 0;
}