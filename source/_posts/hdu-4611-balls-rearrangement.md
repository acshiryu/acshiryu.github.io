title: hdu4611Balls Rearrangement gcd问题 2013多校2-1001
toc: true
tags:
  - gcd
  - 循环
  - 找规律
  - 数论
categories:
  - 算法竞赛
id: 1939
date: 2013-07-27 14:59:11
---

题目实际上就是求$$\sum_{i=0}^{n-1}\left | i \mod a-i \mod b \right |$$

既然有取余，明显会有循环节，很显然循环节是lcm(a,b)

那就求出循环节部分的值再乘以循环的次数再加上其余部分就可以了

多校的时候a,b都取的int，WA了  后来才弄对

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

__int64 gcd(__int64 a,__int64 b)
{
	return b==0?a:gcd(b,a%b);
}
__int64 lcm(__int64 a,__int64 b)
{
	return a/gcd(a,b)*b;
}

__int64 abs(__int64 k)
{
	return k&lt;0?-k:k;
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		__int64 n,a,b;
		scanf(&quot;%I64d%I64d%I64d&quot;,&amp;n,&amp;a,&amp;b);

		if(a&gt;b)
		{
			__int64 t;
			t=b;
			b=a;
			a=t;
		}

		__int64 k=gcd(a,b);
		__int64 ga=a/k;
		__int64 gb=b/k;
		__int64 i,j;
		__int64 sum=0;
		__int64 sumi;
		__int64 sumn=0;
		__int64 x=0;
		__int64 nm=(n%lcm(a,b))/b;
		__int64 tx=0;
		for(i=0;i&lt;ga;i++)
		{
			sumi=0;
			__int64 anum=x/a;
			__int64 x1=(anum+1)*a-x;
			sumi+=x1*abs(x%a-x%b);
			x+=x1;
			__int64 sy=b-x1;
			while(sy&gt;=a)
			{
				sy-=a;
				sumi+=a*abs(x%a-x%b);
				x+=a;
			}
			sumi+=sy*abs(x%a-x%b);

			x+=sy;

			sum+=sumi;
		}
		x=0;
		for(i=0;i&lt;nm;i++)
		{
			sumi=0;
			__int64 anum=x/a;
			__int64 x1=(anum+1)*a-x;
			sumi+=x1*abs(x%a-x%b);
			x+=x1;
			__int64 sy=b-x1;
			while(sy&gt;=a)
			{
				sy-=a;
				sumi+=a*abs(x%a-x%b);
				x+=a;
			}
			sumi+=sy*abs(x%a-x%b);

			x+=sy;

			sumn+=sumi;
		}

		__int64 ans=sum*(n/lcm(a,b))+sumn;

		__int64 nab=n%lcm(a,b);
		for(i=nm*b;i&lt;nab;i++)
			ans+=abs(i%a-i%b);

		printf(&quot;%I64d\n&quot;,ans);

	}
    return 0;
}
[/code]