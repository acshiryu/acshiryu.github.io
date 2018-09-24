#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct prog{
	int num;
	int to;
}a[1000006],ans[1000006];
bool cmp(prog a,prog b)
{
	return a.num<b.num;
}
bool cmpto(prog a,prog b)
{
	return a.to<b.to;
}
int main()
{
	int cas=1;
	int n,s,t;
	while(scanf("%d%d%d",&n,&s,&t),n)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].num);
			a[i].to=i;
		}
		stable_sort(a,a+n,cmp);//stable_sort 稳定排序
		printf("Case %d\n",cas++);
		memcpy(ans,a,s*sizeof(ans[0]));
		stable_sort(ans,ans+s,cmpto);
		for(i=0;i<s;i++)
		{
			if(i)
				printf(" ");
			printf("%d",ans[i].to+1);
		}
		printf("\n");
		memcpy(ans,a+n-t,t*sizeof(ans[0]));
		stable_sort(ans,ans+t,cmpto);
		for(i=t-1;i>=0;i--)
		{
			printf("%d",ans[i].to+1);
			if(i)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}