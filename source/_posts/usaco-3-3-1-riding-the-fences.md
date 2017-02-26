title: USACO 3.3.1 Riding The Fences 欧拉回路
toc: true
tags:
  - usaco
  - 欧拉回路
categories:
  - 算法竞赛
id: 1444
date: 2012-07-14 10:48:26
---

欧拉回路，模板题
[code lang="cpp"]
/*
ID:shiryuw1
PROG:fence
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

int cnt[505];
int adj[505][505];
int path[2500];
int e;
int k;
void DFS(int s)
{
	int i,j;
	for(i=1;i&lt;=k;i++)
	{
		if(adj[s][i])
		{
			adj[s][i]--;
			adj[i][s]--;
			DFS(i);
			path[e++]=i;
		}
	}
}
int main()
{
	  freopen(&quot;fence.in&quot;,&quot;r&quot;,stdin);
	  freopen(&quot;fence.out&quot;,&quot;w&quot;,stdout);
	int n;
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		int i,j;
		zero(cnt);
		zero(adj);
		k=1;
		e=0;
		for(i=0;i&lt;n;i++)
		{
			int a,b;
			scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
			adj[a][b]++;
			adj[b][a]++;
			cnt[a]++;
			cnt[b]++;
			k=max(k,max(a,b));
		}
		int s=0;
		for(i=1;i&lt;=k;i++)
		{
			if(s==0)
				s=i;
			if(cnt[i]%2)
			{
				s=i;
				break;
			}
		}
		DFS(s);
		path[e++]=s;
		for(i=e-1;i&gt;=0;i--)
			printf(&quot;%d\n&quot;,path[i]);
	}
	return 0;
}
[/code]