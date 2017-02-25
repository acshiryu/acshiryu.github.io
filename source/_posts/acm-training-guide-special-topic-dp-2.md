title: 《算法竞赛入门经典训练指南》动态规划专题2
toc: true
tags:
  - DP
  - 动态规划
  - 树
  - 状态dp
  - 状态压缩
categories:
  - 学习笔记
id: 1986
date: 2013-08-18 00:25:03
---

# 动态规划专题(2)

#### 例题30 放置街灯（Placing Lampposts, [Uva 10859](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1800 "10859 - Placing Lampposts")）

动态规划，比较复杂的一题。通过这题，学到一个技巧

一般来说，如果题目要求两个量v1,v2，若要求满足v1最大或最小的时候，v2同事也要最大或最小。则可以把v1和v2合成一个量x=M*v1+v2.其中M要是比v2的理论值与v1理论值之差还要大的数,最后就求出v1=x/M，v2=x%M。因为要v1和v2同增或同减，则对于此题，M可取2000，v1为点灯数，v2为只被一盏灯照到的边的数。

解决此题，首先将无根树转换成有根树，用dp[i][j]来表示对于节点i父节点点灯状态为j时的最小x值，注意当i为根的时候的特殊情况，详细看代码

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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

vector&lt;int&gt;d[1005];
bool vis[1005][2];
int dp[1005][2];
const int bs=2000;
int DFS(int i,int j,int f)
{
	if(vis[i][j]==1)
		return dp[i][j];
	vis[i][j]=1;
	int k;
	int ans1,ans2;
	ans1=bs;
	for(k=0;k&lt;d[i].size();k++)
	{
		if(d[i][k]!=f)
		{
			ans1+=DFS(d[i][k],1,i);
		}
	}
	if(f&gt;=0&amp;&amp;(!j))
		ans1++;
	dp[i][j]=ans1;
	ans2=0;
	if(j||f&lt;0)
	{
		for(k=0;k&lt;d[i].size();k++)
		{
			if(d[i][k]!=f)
			{
				ans2+=DFS(d[i][k],0,i);
			}
		}
		if(f&gt;=0)
			ans2++;
		dp[i][j]=min(ans1,ans2);
	}
	return dp[i][j];
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n,m;
		scanf(&quot;%d%d&quot;,&amp;n,&amp;m);
		int i;
		for(i=0;i&lt;1005;i++)
			d[i].clear();
		for(i=0;i&lt;m;i++)
		{
			int a,b;
			scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
			d[a].push_back(b);
			d[b].push_back(a);
		}
		zero(vis);
		zero(dp);
		int ans=0;
		for(i=0;i&lt;n;i++)
		{
			if(!vis[i][0])
				ans+=DFS(i,0,-1);
		}
		printf(&quot;%d %d %d\n&quot;,ans/bs,m-ans%bs,ans%bs);
	}
    return 0;
}
[/code]
<!--more-->

#### 例题31 捡垃圾的机器人（Robotruck, SWERC 2007, [LA 3983](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1984 "3983 - Robotruck")）

动态规划，设计的转移方程比较简单，用dp[i][j]表示捡到了第i个垃圾后重量为j时走了多少步，特别的dp[i][0]表示剪完1~i的垃圾并丢到垃圾箱走的步子数，则有两种绝策

(1)捡完第i-1个垃圾后继续捡第i个垃圾，则有方程：$$dp[i][j]=dp[i-1][j-lj[i].w]+juli(i-1,i)$$，特别的$$dp[i][0]=min(dp[i][j]+juli(i,0))$$

(2)捡完第i-1个垃圾并扔到垃圾桶里再捡第i个垃圾，则有方程：$$dp[i][lj[i].w]=dp[i-1][0]+juli(i,0)$$，特别的$$dp[i][0]=dp[i][lj[i].w]+juli(i,0)$$

时间和空间复杂度都是$$O(NC)$$，但利用滚动数组可以把空间复杂度降到$$O(C)$$

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

int dp[105];
struct prog{
	int x;int y;int w;
}lj,old_lj,lj0;
int juli(prog i,prog j)
{
	return abs(i.x-j.x)+abs(i.y-j.y);
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int C,n,i,j,k;
		scanf(&quot;%d&quot;,&amp;C);
		scanf(&quot;%d&quot;,&amp;n);
		memset(dp,0x7f,sizeof(dp));
		dp[0]=0;
		old_lj.x=0;
		old_lj.y=0;
		old_lj.w=0;
		lj0=old_lj;
		for(i=1;i&lt;=n;i++)
		{
			scanf(&quot;%d%d%d&quot;,&amp;lj.x,&amp;lj.y,&amp;lj.w);
			int jl0=juli(lj,lj0);
			int tmp=dp[0]+jl0;
			dp[0]=tmp+jl0;;
			int jl=juli(lj,old_lj);
			for(j=C;j&gt;=lj.w+old_lj.w;j--)
			{
				dp[j]=dp[j-lj.w]+jl;
				dp[0]=min(dp[0],dp[j]+jl0);
			}
			while(j&gt;0)
			{
				dp[j]=0x7f7f7f7f;
				j--;
			}
			dp[lj.w]=min(dp[lj.w],tmp);
			old_lj=lj;
		}
		printf(&quot;%d\n&quot;,dp[0]);
		if(T)
			printf(&quot;\n&quot;);
	}
    return 0;
}
[/code]

这题关于时间上的复杂度仍然可以继续优化，利用单调队列，可将复杂度降为$$O(N)$$，详细可参考《训练指南》第73页。

#### 例题32 分享巧克力（Sharing Chocolate, World Finals 2010, [LA 4794](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2795 "4794 - Sharing Chocolate")）

状态DP，转移方程很好想到，但需要继续优化，可参考《训练指南》

[code lang="cpp"]
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

int sum[40000];
int cnt[40000];
int dp[105][40000];
int ans[20];
int all;
bool DFS(int r,int s)
{
	if(dp[r][s]!=-1)
		return dp[r][s];
	int &amp;rs =dp[r][s];
	if(cnt[s]==1)
		return rs=1;
	int c=sum[s]/r;
	for(int sx=(s-1)&amp;s;sx;sx=(sx-1)&amp;s)
	{
		int sy=s-sx;
		if(sum[sx]%r==0&amp;&amp;DFS(min(r,sum[sx]/r),sx)==1&amp;&amp;DFS(min(r,sum[sy]/r),sy)==1)
			return rs=1;
		if(sum[sx]%c==0&amp;&amp;DFS(min(c,sum[sx]/c),sx)==1&amp;&amp;DFS(min(c,sum[sy]/c),sy)==1)
			return rs=1;
	}
	return rs=0;
}
int main()
{
	int n,cas=1;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		all=(1&lt;&lt;n)-1;
		int x;int y;
		scanf(&quot;%d%d&quot;,&amp;x,&amp;y);
		int i,j,k;
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;ans[i]);
		zero(sum);
		fone(dp);
		zero(cnt);
		for(i=1;i&lt;=all;i++)
		{
			for(j=0;j&lt;n;j++)
			{
				if(i&amp;(1&lt;&lt;j))
				{
					sum[i]+=ans[j];
					cnt[i]++;
				}
			}
		}

		if(sum[all]!=x*y||sum[all]%x!=0||DFS(min(x,y),all)==0)
			printf(&quot;Case %d: No\n&quot;,cas++);
		else
			printf(&quot;Case %d: Yes\n&quot;,cas++);
	}
    return 0;
}
[/code]