title: burnside定理，polya计数 模版
toc: true
tags:
  - burnside
  - polya
  - 组合数学
categories:
  - 算法竞赛
id: 1048
date: 2012-03-24 21:31:50
---

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
{//c代表颜色种类数，s表示项链长度
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

//应用举例，poj2409
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