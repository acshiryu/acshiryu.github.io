title: poj 2891 Strange Way to Express Integers 扩展欧几里得
toc: true
tags:
  - gcd
  - 扩展欧几里得
  - 欧几里得
categories:
  - 算法竞赛
id: 1457
date: 2012-07-22 10:35:52
---

题目大意就是给出a和r，求c,其中c mod ai = ri；这题就是扩展欧几里得的一个简单应用

首先我们可以假设c=a0*x+r0=a1*y+r1;则a0*x-a1*y=r1-r0;此时可以求出x，故可以求出c。

假设A=lcm(a0,a1),则A=a0*t1=a1*t1；那么可以推出C'=A*z+C=a0*t*z+a0*x+r0=a0*(t0*z+x)+r0=a1*(t1*z+y)+r1;故这时再将这两个式子合并写成C'=lcm(a0,a1)*z+C；再与接下来的ai和ri合并即可

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

void e_gcd ( __int64 a , __int64 b , __int64 &amp;d , __int64 &amp;x , __int64 &amp;y )
{

	if ( ! b )
		d = a , x =1 , y =0 ;
	else
		e_gcd ( b , a%b , d , y , x ) , y -= x * ( a / b ) ;
}
__int64 gcd(__int64 a,__int64 b)
{
	return b==0?a:gcd(b,a%b);
}
__int64 lcm(__int64 a,__int64 b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int T;
	while(~scanf(&quot;%d&quot;,&amp;T))
	{
		int i,j;
		T--;
		__int64 m,n,r1,r2;
		bool ans=true;
		scanf(&quot;%I64d%I64d&quot;,&amp;m,&amp;r1);
		for(i=0;i&lt;T;i++)
		{
			scanf(&quot;%I64d%I64d&quot;,&amp;n,&amp;r2);
			if(ans)
			{
				__int64 x,y,d;
				e_gcd(m,n,d,x,y);
				if((r2-r1)%d!=0)
					ans=false;
				__int64 t=(r2-r1)/d;
				x=x*t;
				y=y*t;
				x%=(n/d);//求出最小正整数x
				while(x&lt;0)
					x+=(n/d);
				r1=m*x+r1;//合并
				m=lcm(m,n);
				if((r1-r2)%n!=0)
					ans=false;
			}
		}
		if(ans)
			printf(&quot;%I64d\n&quot;,r1);
		else
			printf(&quot;-1\n&quot;);

	}
    return 0;
}
[/code]