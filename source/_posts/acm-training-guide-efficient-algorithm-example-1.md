title: 《算法竞赛入门经典训练指南》高效算法设计举例1
toc: true
tags:
  - STL
  - 排序
  - 计数排序
  - 计算几何
  - 贪心
categories:
  - 学习笔记
id: 1956
date: 2013-08-04 23:37:29
---

# 高效算法设计举例(1)

#### 例题17 年龄排序（Age Sort，[Uva11462](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2457 "11462 - Age Sort")）

计数排序

[code lang="cpp"]
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
int a[105];
int main()
{
	int n;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int k;
		memset(a,0,sizeof(a));
		while(n--)
		{
			scanf(&quot;%d&quot;,&amp;k);
			a[k]++;
		}
		bool sc=0;
		for(int i=1;i&lt;=100;i++)
		{

			while(a[i]--)
			{
				if(sc)
					printf(&quot; &quot;);
				sc=1;
				printf(&quot;%d&quot;,i);
			}
		}
		printf(&quot;\n&quot;);
	}
}
[/code]
<!--more-->

#### 例题18 开放式学分制（Open Credit System，[Uva11078](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2019 "11078 - Open Credit System")）

简单贪心

[code lang="cpp"]
#include&lt;cstdio&gt;
#include&lt;algorithm&gt;
using namespace std;
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n;
		int maxn=-150000;
		int ans=-300000;
		scanf(&quot;%d&quot;,&amp;n);
		while(n--)
		{
			int k;
			scanf(&quot;%d&quot;,&amp;k);
			ans=max(ans,maxn-k);
			maxn=max(maxn,k);
		}
		printf(&quot;%d\n&quot;,ans);
	}
}
[/code]

#### 例题19 计算器谜题（Calculator Conundrum，[Uva11549](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2544 "11549 - Calculator Conundrum")）

找循环节，输出寻找过程中出现最大的值。用STL来判断每个值是否出现过

关于判重，训练指南上有一个更巧妙的方法，空间复杂度瞬间降为O(1)，使用floyd判圈算法

[code lang="cpp"]
#include&lt;cstdio&gt;
#include&lt;set&gt;
#include&lt;algorithm&gt;
#include&lt;iostream&gt;
#include&lt;cmath&gt;
using namespace std;
typedef long long __int64;
__int64 mypow10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,100000000000};
inline int count(__int64 k)
{
	if(k==0)
		return 1;
	int cnt=0;
	while(k)
	{
		k=k/10;
		cnt++;
	}
	return cnt;
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		__int64 n,k;
		//scanf(&quot;%I64d%I64d&quot;,&amp;n,&amp;k);
		cin&gt;&gt;n&gt;&gt;k;
		set&lt;int&gt;s;
		int maxn=0;
		while(s.count(k)==0)
		{
			maxn=max(maxn,(int)k);
			s.insert(k);
			k=k*k;
			int l=count(k);
			if(l&gt;n)
				k=k/mypow10[l-n];
		}
		printf(&quot;%d\n&quot;,maxn);
	}
}
[/code]

#### 例题20 流星（Meteor，[LA3905](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1906 "3905 - Meteor")）

计算几何,代码和白书差不多

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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

const int maxn=100000+10;
const double inf=1e-6;
struct prog{
	double x;
	bool fx;
	prog(double y,bool f)
	{
		x=y;
		fx=f;
	}
	prog(){}
}lr[2*maxn];
int num;
void update(int x,int a,int w,double &amp;L,double &amp;R)
{
	if(a==0)
	{
		if(x&lt;=0||x&gt;=w)
			R=L-1;
	}
	else if(a&gt;0)
	{
		L=max(L,-1.0*x/a);
		R=min(R,1.0*(w-x)/a);
	}
	else
	{
		L=max(L,1.0*(w-x)/a);
		R=min(R,-1.0*x/a);
	}
}
bool operator&lt;(prog a,prog b)
{
	if(a.x==b.x)
		return a.fx&gt;b.fx;
	return a.x&lt;b.x;
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int w,h,n;
		scanf(&quot;%d%d%d&quot;,&amp;w,&amp;h,&amp;n);
		int i,j;
		num=0;
		for(i=0;i&lt;n;i++)
		{
			int x,y,a,b;
			scanf(&quot;%d%d%d%d&quot;,&amp;x,&amp;y,&amp;a,&amp;b);

			 double L=0,R=1e9;
			 update(x,a,w,L,R);
			 update(y,b,h,L,R);

			 if(R&gt;L)
			 {
				 lr[num++]=prog(L,0);
				 lr[num++]=prog(R,1);
			 }
		}

		sort(lr,lr+num);

		int cnt=0;
		int ans=0;
		for(i=0;i&lt;num;i++)
		{
			if(lr[i].fx==0)
				ans=max(ans,++cnt);
			else
				cnt--;
		}
		printf(&quot;%d\n&quot;,ans);
	}
    return 0;
}
[/code]