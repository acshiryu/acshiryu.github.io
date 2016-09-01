title: 【图论】建立邻接表
toc: true
tags:
  - 图论
  - 邻接表
categories:
  - 算法竞赛
id: 1598
date: 2012-09-18 21:34:27
---

[code lang="cpp"]
const int V = 805;//点的个数
const int E = 3000;//边的条数
int pnt[E], cost[E], nxt[E];//pnt-边的终点，cost-边的价值，nxt-下一条边的地址
int e, head[V];
int dist[V][V]; 

inline void addedge(int u, int v, int c){//从u到v增加权值为c的边
    pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}

int main()
{//使用时初始化
    e=0;
    memset(head,-1,sizeof(head));
}
[/code]