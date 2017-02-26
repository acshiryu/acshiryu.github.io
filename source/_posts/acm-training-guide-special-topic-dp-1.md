title: 《算法竞赛入门经典训练指南》动态规划专题1
toc: true
tags:
  - DP
  - 动态规划
  - 数论
  - 状态压缩
  - 递推
categories:
  - 学习笔记
id: 1976
date: 2013-08-14 14:57:32
---

# 动态规划专题(1)

#### 例题26 约瑟夫环的变形（And Then There Was One, Japan 2007, [LA 3882](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1883 "3882 - And Then There Was One"), [POJ 3517](http://poj.org/problem?id=3517 "And Then There Was One")）

经典问题，递推解决

[code lang="cpp"]
#include&lt;cstdio&gt;
int main()
{
	int n,m,k;
	while(scanf(&quot;%d%d%d&quot;,&amp;n,&amp;k,&amp;m),n||m||k)
	{
		int i;
		int ans=0;
		for(i=2;i&lt;=n;i++)
			ans=(ans+k)%i;
		ans=(ans+m-k+1)%n;
		while(ans&lt;=0)
			ans+=n;
		printf(&quot;%d\n&quot;,ans);
	}
}
[/code]

#### 例题27 王子和公主（Prince and Princess, [Uva 10635](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1576 "10635 - Prince and Princess")）

LCS问题，可转为LIS问题

[code lang="cpp"]

#include &lt;cstdio&gt;
#define zero(a) memset(a,0,sizeof(a))
int dp[630000],mp[630000];
void erfen(int l,int r,int k)
{
	while(l&lt;r)
	{
		int m=(l+r)/2;
		if(dp[m]&lt;k) l=m+1;
		else r=m;
	}
	dp[l]=k;
}
int main()
{
	int T,cas=1;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n,p,q,i,j,k;
		scanf(&quot;%d%d%d&quot;,&amp;n,&amp;p,&amp;q);
		zero(mp);
		for(i=0;i&lt;=p;i++)
		{
			scanf(&quot;%d&quot;,&amp;k);
			mp[k]=i+1;
		}
		zero(dp);
		j=0;
		for(i=1;i&lt;=q+1;i++)
		{
			scanf(&quot;%d&quot;,&amp;k);
			k=mp[k];
			if(k&gt;dp[j])
			{
				dp[j+1]=k;
				j++;
			}
			else if(k!=0)
			{
				erfen(0,j,k);
			}
		}
		printf(&quot;Case %d: %d\n&quot;,cas++,j);
	}
    return 0;
}
[/code]
<!--more-->

#### 例题28 Sum游戏（Game of Sum, [Uva 10891](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1832 "10891 - Game of Sum")）

动态规划，用dp[i][j]表示第i~j个元素组成的子元素先手能拿的最大分，则后手能拿的最大分就是sum[i][j]-dp[i][j]

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

int dp[105][105];
int a[105];
int sum[105];
int f[105][105];
int g[105][105];
int main()
{
	int n;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j,k;
		sum[0]=0;
		for(i=1;i&lt;=n;i++)
		{
			scanf(&quot;%d&quot;,&amp;a[i]);
			sum[i]=sum[i-1]+a[i];
		}

		for(i=1;i&lt;=n;i++)
		{
			dp[i][i]=a[i];
			f[i][i]=a[i];
			g[i][i]=a[i];
		}

		for(i=n-1;i&gt;=1;i--)
		{
			for(j=1;i+j&lt;=n;j++)
			{
				int suma=sum[i+j]-sum[i-1];
				dp[i][i+j]=suma-min(0,min(f[i+1][i+j],g[i][i+j-1]));
				f[i][i+j]=min(dp[i][i+j],f[i+1][i+j]);
				g[i][i+j]=min(dp[i][i+j],g[i][i+j-1]);
			}
		}
		printf(&quot;%d\n&quot;,2*dp[1][n]-sum[n]);
	}
    return 0;
}
[/code]

#### 例题29 黑客的攻击（Hackers' Crackdown, [Uva 11825](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925 "11825 - Hackers")）

状态dp，用二进制表示状态。通过这题学习到原来枚举集合S的子集的一个好方法，详看代码

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

int p[20];
int dp[70000];
int c[70000];
int main()
{
	int n,cas=1;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int maxn=(1&lt;&lt;n)-1;
		int i,j,k;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%d&quot;,&amp;j);
			p[i]=1&lt;&lt;i;
			while(j--)
			{
				scanf(&quot;%d&quot;,&amp;k);
				p[i]=p[i]|(1&lt;&lt;k);
			}
		}
		for(int s=0;s&lt;=maxn;s++)
		{
			c[s]=0;
			for(i=0;i&lt;n;i++)
			{
				if(s&amp;(1&lt;&lt;i))
					c[s]=c[s]|p[i];
			}
		}

		zero(dp);
		for(int s=1;s&lt;=maxn;s++)
		{
			//枚举集合s的子集s0，原来还可以这样！！！
			for(int s0=s;s0;s0=(s0-1)&amp;s)
			{
				if(c[s0]==maxn)
				{
					dp[s]=max(dp[s],dp[s^s0]+1);
				}
			}
		}
		printf(&quot;Case %d: %d\n&quot;,cas++,dp[maxn]);
	}
    return 0;
}
[/code]