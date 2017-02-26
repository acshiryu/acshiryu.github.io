title: USACO3.2.3 Spinning Wheels
toc: true
tags:
  - 枚举
categories:
  - 算法竞赛
id: 1416
date: 2012-06-08 16:51:47
---

随便写的，估计明天我就会忘了每个函数的意思

简单枚举，明显每个齿轮的周期都有360  然后就枚举360秒  然后枚举360个角度，判断每一秒的每一个角度是否都有空缺，

[code lang="cpp"]
/*
ID:shiryuw1
PROG:spin
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

struct prog{
	int v;
	int s[5];
	int l[5];
	int k;
}spin[5];
bool inn(int k,int m,int n)
{
	int t=k+360;
	if((k&gt;=m&amp;&amp;k&lt;=n)||(t&gt;=m&amp;&amp;t&lt;=n))
		return true;
	return false;
}
bool inspink(int m,int n)
{
	for(int i=0;i&lt;spin[n].k;i++)
	{
		if(inn(m,spin[n].s[i],spin[n].s[i]+spin[n].l[i]))
			return true;
	}
	return false;
}
bool inspin(int k)
{
	int i;
	for(i=0;i&lt;5;i++)
		if(!inspink(k,i))
			return false;
	return true;
}
bool pass()
{
	int i;
	for(i=0;i&lt;360;i++)
	{
		if(inspin(i))
			return true;
	}
	return false;
}
void rotation()
{
	int i,j;
	for(i=0;i&lt;5;i++)
	{
		for(j=0;j&lt;spin[i].k;j++)
		{
			spin[i].s[j]=(spin[i].s[j]+spin[i].v)%360;
		}
	}
}
int main()
{
  freopen(&quot;spin.in&quot;,&quot;r&quot;,stdin);
 freopen(&quot;spin.out&quot;,&quot;w&quot;,stdout);
	int i,j;
	for(i=0;i&lt;5;i++)
	{
		int k;
		cin&gt;&gt;spin[i].v&gt;&gt;k;
		spin[i].k=k;
		while(k--)
		{
			cin&gt;&gt;spin[i].s[k]&gt;&gt;spin[i].l[k];
		}
	}
	for(i=0;i&lt;360;i++)
	{
		if(pass())
			break;
		rotation();
	}
	if(i&gt;=360)
		cout&lt;&lt;&quot;none&quot;&lt;&lt;endl;
	else
		cout&lt;&lt;i&lt;&lt;endl;
    return 0;
}
[/code]