title: USACO3.2.1 Factorials 求n！最后非零数（初级）
toc: true
tags:
  - 数学
  - 数论
  - 暴力
  - 阶乘
categories:
  - 算法竞赛
id: 1413
date: 2012-06-08 16:09:00
---

[code lang="cpp"]
/*
ID:shiryuw1
PROG:fact4
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

int main()
{
	freopen(&quot;fact4.in&quot;,&quot;r&quot;,stdin);
	 freopen(&quot;fact4.out&quot;,&quot;w&quot;,stdout);
	int n;
	while(cin&gt;&gt;n)
	{
		int ans=1;
		int a,b;
		a=b=0;
		for(int i=1;i&lt;=n;i++)
		{
			int k=i;
			while(k%2==0)
			{
				a++;
				k/=2;
			}
			while(k%5==0)
			{
				b++;
				k/=5;
			}
			ans=ans*k%10;
		}
		a-=b;
		a%=4;
		if(a==0)
		{
			if(b)
				a=4;
		}
		ans=(ans*(1&lt;&lt;a))%10;
		cout&lt;&lt;ans&lt;&lt;endl;
	}
    return 0;
}
[/code]