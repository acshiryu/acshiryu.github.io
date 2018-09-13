#include "iostream"
#include "cstdio"
#include "cstdlib"
using namespace std;
#define zero(x) 	(memset(x,0,sizeof(x)))
int sum[15005];
int main()
{
	int n,i,j,k,s,t,ans,maxx,minx;
	//Code
	while(~scanf("%d",&n))
	{
		zero(sum);
		int a,b,c;
		while(scanf("%d%d%d",&a,&b,&c),a!=-1&&b!=-1&&c!=-1)
		{
			sum[a]+=c;
			sum[b+1]-=c;//注意是第b+1减，因为第b个点也受到炸弹的影响，详见题目原文
		}
		int ans=0;
		int maxx=-inf;
		s=t=0;
		for(i=0;i<=n;i++)
		{
			ans+=sum[i];
			sum[i]=ans;
			if(maxx<ans)
			{
				maxx=ans;
				s=t=i;
			}
			else if(maxx==ans)
				t=i;
		}
		printf("%d %dn",s,t);
	}
	return 0;
}