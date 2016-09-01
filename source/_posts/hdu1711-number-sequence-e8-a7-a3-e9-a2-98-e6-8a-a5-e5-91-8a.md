title: hdu1711 Number Sequence 解题报告
toc: true
tags:
  - kmp
categories:
  - 算法竞赛
id: 1066
date: 2012-03-25 14:59:21
---

题目地址：[http://acm.hdu.edu.cn/showproblem.php?pid=1711](http://acm.hdu.edu.cn/showproblem.php?pid=1711 "Number Sequence")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;kmp算法，直接看大神博客水过，关于kmp算法，推荐matrix67的博客，地址：[http://www.matrix67.com/blog/archives/115](http://www.matrix67.com/blog/archives/115 "KMP算法详解")
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cmath&gt;
#include&lt;cstdio&gt;
using namespace std;
int a[1000000+5];
int b[1000000+5];
int p[1000000+5];
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n,m;
		scanf(&quot;%d%d&quot;,&amp;n,&amp;m);
		int i,j;
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;a[i]);
		memset(p,-1,sizeof(p));
		for(i=0;i&lt;m;i++)
		{
			scanf(&quot;%d&quot;,&amp;b[i]);
			if(i)
			{
				j=p[i-1];
				if(b[j+1]==b[i])
					p[i]=j+1;
				else
					p[i]=-1;
			}
		}
		j=-1;
		for(i=0;i&lt;n;i++)
		{
			while(j&gt;=0&amp;&amp;b[j+1]!=a[i])
				j=p[j];
			if(b[j+1]==a[i])
				j++;
			if(j+1==m)
				break;
		}
		if(i==n)
			printf(&quot;-1\n&quot;);
		else
			printf(&quot;%d\n&quot;,i-j+1);
	}
	return 0;
}
[/code]