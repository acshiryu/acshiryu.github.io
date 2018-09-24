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

struct prog{
	int k;
	double high;
}ans[1005];
bool cmp(prog a,prog b)
{
	if(a.high==b.high)
		return a.k<b.k;
	return a.high>b.high;
}
int main()
{

	int n,t1,t2,k;
	while(~scanf("%d%d%d%d",&n,&t1,&t2,&k))
	{
		int i;
		for(i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			ans[i].k=i;
			ans[i].high=max(a*t1*(100-k)/100.0+b*t2*1.0,b*t1*(100-k)/100.0+a*t2*1.0);
		}
		sort(ans,ans+n,cmp);
		for(i=0;i<n;i++)
			printf("%d %.2lf\n",ans[i].k+1,ans[i].high);
	}
    return 0;
}