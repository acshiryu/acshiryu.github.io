/*
ID:shiryuw1
PROG:butter
LANG:C++
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
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
	if( dist[src][v] > dist[src][u] + c ) {
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
	for( i=1; i <= n; ++i ) dist[src][i] = INF;
	dist[src][src] = 0;
	queue<int> Q;
	Q.push(src); vis[src] = true; ++cnt[src];
	while( !Q.empty() ){
		int u, v;
		u = Q.front(); Q.pop(); vis[u] = false;
		for( i=head[u]; i != -1; i=nxt[i] ){
			v = pnt[i];
			if( 1 == relax(u, v, cost[i],src) && !vis[v] ) {
				Q.push(v); vis[v] = true;
				if( (++cnt[v]) > n ) return -1; // cnt[i]为入队列次数，用来判断是否存在负权回路
			}
		}
	}
	if( dist[src][n] == INF ) return -2; // src与n不可达，有些题目可省！！！
	return dist[src][n]; // 返回src到n的最短距离，根据题意不同而改变
}

int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	int n,p,c;
	while(cin>>n>>p>>c)
	{
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&bianhao[i]);
		int a,b,d;
		e=0;
		fone(head);
		for(i=0;i<c;i++)
		{
			scanf("%d%d%d",&a,&b,&d);
			addedge(a,b,d);
			addedge(b,a,d);
		}
		for(i=1;i<=p;i++)
			SPFA(i,p);

		int ans=1<<25;
		for(i=1;i<=p;i++)
		{
			int sum=0;
			for(j=0;j<n;j++)
			{
				sum+=dist[bianhao[j]][i];
			}
			if(ans>sum)
				ans=sum;
		}
		cout<<ans<<endl;
	}
	return 0;
}