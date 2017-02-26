title: POJ2689 Prime Distance 素数筛选
toc: true
tags:
  - 筛选
  - 素数
categories:
  - 算法竞赛
id: 1459
date: 2012-07-22 10:43:32
---

题目大意就是求出l,r间距离最近和最远的两个相邻素数。数据范围是2^32，明显不能直接枚举，会超时，也不能直接筛选，会超内存，但还好，l与r的值相差不超过10^6，故可以两次筛选，第一次，筛选出1~2^16里的所有素数，第二次用这些素数筛选出l到r的所有素数，由于数据太大，存储的下表明显不能直接用l到r之间的数，但注意到数组l之前的数权威空白，故下表可以用i-l来进行存储

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

bool ispri[46348];
bool ans[1000005];
int main()
{
	unsigned int i,j,k=0;
	one(ispri);
	ispri[0]=ispri[1]=1;
	for(i=2;i&lt;46348;i++)
	{
		if(ispri[i])
		{
			for(j=i*i;j&lt;46348;j+=i)
				ispri[j]=0;
		}
	}
	unsigned int l,r;
	while(~scanf(&quot;%u%u&quot;,&amp;l,&amp;r))
	{
		unsigned int a,b,c,d;
		a=b=c=d=-1;
		one(ans);
		if(l&lt;2)l=2;
		for(i=2;i&lt;46348;i++)
		{
			if(ispri[i])
			{
				unsigned int t=l/i;
				for(j=i*t;j&lt;=r;j+=i)
				{
					if(j&gt;=l)
					{
						if(j!=i)
							ans[j-l]=0;
						else
							ans[j-l]=1;
					}
				}
			}
		}
		for(i=0;i&lt;=r-l;i++)
		{
			if(ans[i])
			{
				if(a==-1)
					a=c=i;
				else if(b==-1)
					b=d=i;
				else
				{
					if(b-a&gt;i-k)
						b=i,a=k;
					if(d-c&lt;i-k)
						d=i,c=k;
				}
				k=i;
			}
		}
		if(b==-1)
			printf(&quot;There are no adjacent primes.\n&quot;);
		else
			printf(&quot;%u,%u are closest, %u,%u are most distant.\n&quot;,a+l,b+l,c+l,d+l);
	}
    return 0;
}
[/code]