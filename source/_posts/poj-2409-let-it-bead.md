title: poj2409 Let it Bead 解题报告
toc: true
tags:
  - polya
  - 组合数学
categories:
  - 算法竞赛
id: 1062
date: 2012-03-25 14:46:53
---

题目地址:[http://poj.org/problem?id=2409](http://poj.org/problem?id=2409 "Let it Bead")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Polya计数，直接套模版水过，关于Polya计数，任何一本关于组合数学的书都有，详细证明略去。模版地址[/archives/1048](/archives/1048 "burnside定理，polya计数 模版")
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cmath&gt;
#include&lt;algorithm&gt;
using namespace std;
typedef long long ll;
int gcd (int a, int b) 
{ 
	return b ? gcd(b,a%b) : a; 
}
ll polya(int c,int s)
{
	int k;
	ll p[64]; 

	// power of c
	p[0] = 1; 
	for (k=0 ; k&lt;s ; k++) 
		p[k+1] = p[k] * c;

	// reflection part
	ll count = s&amp;1 ? s * p[s/2 + 1] :
	(s/2) * (p[s/2] + p[s/2 + 1]);

	// rotation part
	for (k=1 ; k&lt;=s ; k++) 
		count += p[gcd(k, s)];
	count /= 2 * s;
	return count;
}

int main (void)
{
	int c, s;
	while (scanf(&quot;%d%d&quot;, &amp;c, &amp;s),c||s) 
	{
		cout&lt;&lt;polya(c,s)&lt;&lt;endl;
	}
	return 0;
}
[/code]