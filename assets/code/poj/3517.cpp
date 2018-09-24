#include<cstdio>
int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&k,&m),n||m||k)
	{
		int i;
		int ans=0;
		for(i=2;i<=n;i++)
			ans=(ans+k)%i;
		ans=(ans+m-k+1)%n;
		while(ans<=0)
			ans+=n;
		printf("%d\n",ans);
	}
}