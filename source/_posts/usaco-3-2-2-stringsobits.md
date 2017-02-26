title: USACO3.2.2 Stringsobits 解题报告
toc: true
tags:
  - 组合数学
categories:
  - 算法竞赛
id: 1403
date: 2012-05-14 21:57:06
---

组合数学，比较简单的一题，详细看代码，注意要用无符号数或者64位整数
[code lang="cpp"]
/*
ID:shiryuw1
PROG:kimbits
LANG:C++
*/
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

long long c[50][50];
int main()
{
	freopen(&quot;kimbits.in&quot;,&quot;r&quot;,stdin);
	freopen(&quot;kimbits.out&quot;,&quot;w&quot;,stdout);
	long long n,l,k,i,j;
	zero(c);
	for(i=0;i&lt;50;i++)
	{
		c[i][i]=c[0][i]=1;
	}
	for(i=1;i&lt;50;i++)
	{
		for(j=i+1;j&lt;50;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i][j-1];
		}
	}
	cin&gt;&gt;n&gt;&gt;l&gt;&gt;k;
	while(n--)
	{
		long long sum=0;
		for(i=0;i&lt;=l;i++)
			sum+=c[i][n];
		if(k&gt;sum)
		{
			printf(&quot;1&quot;);
			k-=sum;
			l--;
		}
		else
			printf(&quot;0&quot;);
	}
	printf(&quot;\n&quot;);
	return 0;
}
[/code]