title: "Codeforces Round #118 (Div. 2) :B. Growing Mushrooms"
toc: true
tags:
  - cf
categories:
  - 算法竞赛
id: 1347
date: 2012-05-05 21:45:32
---

水题，就是对每组的max(a*t1*(100-k)/100.0+b*t2*1.0,b*t1*(100-k)/100.0+a*t2*1.0)排序，如果相等，再让序号排
[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
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
		return a.k&lt;b.k;
	return a.high&gt;b.high;
}
int main()
{

	int n,t1,t2,k;
	while(~scanf(&quot;%d%d%d%d&quot;,&amp;n,&amp;t1,&amp;t2,&amp;k))
	{
		int i;
		for(i=0;i&lt;n;i++)
		{
			int a,b;
			scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
			ans[i].k=i;
			ans[i].high=max(a*t1*(100-k)/100.0+b*t2*1.0,b*t1*(100-k)/100.0+a*t2*1.0);
		}
		sort(ans,ans+n,cmp);
		for(i=0;i&lt;n;i++)
			printf(&quot;%d %.2lf\n&quot;,ans[i].k+1,ans[i].high);
	}
    return 0;
}
[/code]