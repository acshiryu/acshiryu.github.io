#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct prog{
	int b,j;
}a[1005];
bool cmp(prog a,prog b)
{
	if(a.j==b.j)
		return a.b>b.b;
	return a.j>b.j;
}
int main()
{
	int n,cnt=1;;
	while(scanf("%d",&n),n)
	{
		int i,j,k;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].b,&a[i].j);
		}
		sort(a,a+n,cmp);

		int ans=0;
		int tmp=0;
		for(i=0;i<n;i++)
		{
			ans=max(ans,tmp+a[i].b+a[i].j);
			tmp+=a[i].b;
		}
		printf("Case %d: %d\n",cnt++,ans);
	}
	return 0;
}