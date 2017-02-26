title: USACO 3.2.6 Sweet Butter(SPFA求最短路)
toc: true
tags:
  - spfa
categories:
  - 算法竞赛
id: 1442
date: 2012-07-13 20:42:14
---

SPFA，模板题，直接套用模板即可，用的吉林大学的模板库
[code lang="cpp"]
/*
ID:shiryuw1
PROG:butter
LANG:C++
*/
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;queue&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))
#define swap(t, a, b) (t=a, a=b, b=t)

const int INF = 0x3f3f3f3f;
const int V = 805;
const int E = 3000;
int pnt[E], cost[E], nxt[E];
int e, head[V]; int dist[V][V]; bool vis[V];
int cnt[V]; // 入队列次数
int bianhao[505];
int relax(int u, int v, int c,int src){
	if( dist[src][v] &gt; dist[src][u] + c ) {
		dist[src][v] = dist[src][u] + c; return 1;
	}
	return 0;
}
inline void addedge(int u, int v, int c){
	pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}
int SPFA(int src, int n){// 此处用队列实现
	int i;
	memset(cnt, 0, sizeof(cnt)); // 入队次数
	memset(vis, false, sizeof(vis));
	for( i=1; i &lt;= n; ++i ) dist[src][i] = INF;
	dist[src][src] = 0;
	queue&lt;int&gt; Q;
	Q.push(src); vis[src] = true; ++cnt[src];
	while( !Q.empty() ){
		int u, v;
		u = Q.front(); Q.pop(); vis[u] = false;
		for( i=head[u]; i != -1; i=nxt[i] ){
			v = pnt[i];
			if( 1 == relax(u, v, cost[i],src) &amp;&amp; !vis[v] ) {
				Q.push(v); vis[v] = true;
				if( (++cnt[v]) &gt; n ) return -1; // cnt[i]为入队列次数，用来判断是否存在负权回路
			}
		}
	}
	if( dist[src][n] == INF ) return -2; // src与n不可达，有些题目可省！！！
	return dist[src][n]; // 返回src到n的最短距离，根据题意不同而改变
}

int main()
{
	freopen(&quot;butter.in&quot;,&quot;r&quot;,stdin);
	freopen(&quot;butter.out&quot;,&quot;w&quot;,stdout);
	int n,p,c;
	while(cin&gt;&gt;n&gt;&gt;p&gt;&gt;c)
	{
		int i,j;
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;bianhao[i]);
		int a,b,d;
		e=0;
		fone(head);
		for(i=0;i&lt;c;i++)
		{
			scanf(&quot;%d%d%d&quot;,&amp;a,&amp;b,&amp;d);
			addedge(a,b,d);
			addedge(b,a,d);
		}
		for(i=1;i&lt;=p;i++)
			SPFA(i,p);

		int ans=1&lt;&lt;25;
		for(i=1;i&lt;=p;i++)
		{
			int sum=0;
			for(j=0;j&lt;n;j++)
			{
				sum+=dist[bianhao[j]][i];
			}
			if(ans&gt;sum)
				ans=sum;
		}
		cout&lt;&lt;ans&lt;&lt;endl;
	}
	return 0;
}
[/code]