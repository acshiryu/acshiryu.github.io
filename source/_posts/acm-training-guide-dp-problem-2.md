title: 《算法竞赛入门经典训练指南》动态规划习题2
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 学习笔记
id: 1998
date: 2013-08-21 14:30:00
---

# 动态规划习题(2)

#### 划分成回文串（Partitioning by Palindromes, [Uva 11584](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2631 "11584 - Partitioning by Palindromes")）

简单动态规划，用dp[i]表示前i部分的划分情况。记录每个点j，以j为中点的回文串长度，然后dp[i]=min(dp[i-s-1]|其中a[i-s~i]为回文串)

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
#define setmax(a) memset(a,0x7f,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

const int maxn=1005;
char s[maxn];
int dp[maxn];
int hw[maxn];
int hw2[maxn];
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		scanf(&quot;%s&quot;,s+1);
		int l=strlen(s+1);
		int i,j;
		for(i=1;i&lt;=l;i++)
		{
			hw[i]=hw2[i]=0;
			for(j=0;i+j&lt;=l&amp;&amp;i-j&gt;0;j++)
			{
				if(s[i+j]==s[i-j])
					hw[i]++;
				else
					break;
			}
			for(j=0;i+j+1&lt;=l&amp;&amp;i-j&gt;0;j++)
			{
				if(s[i+j+1]==s[i-j])
					hw2[i]++;
				else
					break;
			}
		}
		zero(dp);
		for(i=1;i&lt;=l;i++)
		{
			dp[i]=dp[i-1]+1;
			for(j=1;j&lt;i;j++)
			{
				if(hw[j]+j-1&gt;=i)
					dp[i]=min(dp[i],dp[2*j-i-1]+1);
				if(hw2[j]+j&gt;=i)
					dp[i]=min(dp[i],dp[2*j-i]+1);
			}
		}
		printf(&quot;%d\n&quot;,dp[l]);
	}
    return 0;
}
[/code]
<!--more-->

#### 商人（Salesmen, [LA 4256](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2257 "4256 - Salesmen")）

简单动态规划

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;vector&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define setmax(a) memset(a,0x7f,sizeof(a))

vector&lt;int&gt;v[105];
int dp[205][105];
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n,m;
		scanf(&quot;%d%d&quot;,&amp;n,&amp;m);
		int i,j;
		for(i=1;i&lt;=n;i++)
			v[i].clear();
		for(i=1;i&lt;=m;i++)
		{
			int a,b;
			scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int p;
		scanf(&quot;%d&quot;,&amp;p);
		setmax(dp);
		for(i=0;i&lt;=n;i++)
			dp[0][i]=0;
		for(i=1;i&lt;=p;i++)
		{
			int k;
			scanf(&quot;%d&quot;,&amp;k);
			for(j=1;j&lt;=n;j++)
			{
				int bl=0;
				if(j==k)
					bl=0;
				else
					bl=1;
				dp[i][j]=dp[i-1][j]+bl;
				for(int d=0;d&lt;v[j].size();d++)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][v[j][d]]+bl);
				}
			}
		}
		int ans=1000000000;
		for(i=1;i&lt;=n;i++)
		{
			ans=min(dp[p][i],ans);
		}
		printf(&quot;%d\n&quot;,ans);
	}
    return 0;
}
[/code]

#### 波浪子序列（Wavio Sequence, [Uva 10534](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1475 "10534 - Wavio Sequence")）

做两次最长上升子序列就可以了

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

int a[10005];
int t[10005];
int dp[10005];
int dp2[10005];
const int maxn=0x7fffffff;
int erfen(int i,int j,int k)
{
	while(i&lt;j)
	{
		int m=(i+j)/2+1;
		if(t[m]&gt;=k)
			j=m-1;
		else
			i=m;
	}
	return i;
}
int main()
{
	int n;
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		int i,j;
		for(i=1;i&lt;=n;i++)
			scanf(&quot;%d&quot;,&amp;a[i]);

		zero(dp);
		zero(dp2);
		zero(t);

		j=0;
		t[0]=-maxn;
		for(i=1;i&lt;=n;i++)
		{
			if(a[i]&gt;t[j])
			{
				j++;
				t[j]=a[i];
				dp[i]=j;
			}
			else
			{
				int k=erfen(0,j,a[i]);
				dp[i]=k+1;
				t[k+1]=a[i];
			}
		}

		zero(t);
		j=0;
		t[j]=-maxn;
		for(i=n;i&gt;0;i--)
		{
			if(a[i]&gt;t[j])
			{
				j++;
				t[j]=a[i];
				dp2[i]=j;
			}
			else
			{
				int k=erfen(0,j,a[i]);
				dp2[i]=k+1;
				t[k+1]=a[i];
			}
		}

		int ans=0;
		for(i=1;i&lt;=n;i++)
			ans=max(ans,2*min(dp[i],dp2[i])-1);
		printf(&quot;%d\n&quot;,ans);
	}
    return 0;
}
[/code]