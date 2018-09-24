#include <cstdio>
#define zero(a) memset(a,0,sizeof(a))
int dp[630000],mp[630000];
void erfen(int l,int r,int k)
{
	while(l<r)
	{
		int m=(l+r)/2;
		if(dp[m]<k) l=m+1;
		else r=m;
	}
	dp[l]=k;
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int n,p,q,i,j,k;
		scanf("%d%d%d",&n,&p,&q);
		zero(mp);
		for(i=0;i<=p;i++)
		{
			scanf("%d",&k);
			mp[k]=i+1;
		}
		zero(dp);
		j=0;
		for(i=1;i<=q+1;i++)
		{
			scanf("%d",&k);
			k=mp[k];
			if(k>dp[j])
			{
				dp[j+1]=k;
				j++;
			}
			else if(k!=0)
			{
				erfen(0,j,k);
			}
		}
		printf("Case %d: %d\n",cas++,j);
	}
    return 0;
}