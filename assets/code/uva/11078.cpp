#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int maxn=-150000;
		int ans=-300000;
		scanf("%d",&n);
		while(n--)
		{
			int k;
			scanf("%d",&k);
			ans=max(ans,maxn-k);
			maxn=max(maxn,k);
		}
		printf("%d\n",ans);
	}
}