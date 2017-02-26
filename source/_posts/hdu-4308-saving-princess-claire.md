title: hdu4308Saving Princess claire_ 搜索解题报告（多校1）
toc: true
tags:
  - BFS
  - 最短路
categories:
  - 算法竞赛
id: 1472
date: 2012-08-09 10:37:17
---

题目大意就是从Y走到C经过\*最少是多少，其中\#不可走，P可传送至任何一个为P的地方，这题可以广搜，hdu给出的是最短路，下面是官方的解题报告


简单最短路。
给出的地图中，Y为起点，C为终点，\#点不能通过，可直接忽略。所有的P为互通的传送门，故可将所以的P看作同一个点。每个能通过的点可以向上下左右四个方向走，如果对应的方向可以通过，则连边，若要走到的点是\*，则边权为通过的费用，否则边权为0。
连边后求Y到C的最短路即可。

我的代码
```c++
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
 
char mat[5005][5005];
bool hash[5005];

int fx[][2]={
	{-1,0},
	{0,-1},
	{1,0},
	{0,1}
};

struct loc{
    int x,y;
}p[505],start,end;

struct prog{
    int x,y;
    int cnt;
};

bool operator<(prog a,prog b)
{
    return a.cnt>b.cnt;
}

int p_num;

int main()
{
    int r,c,cost;
    while(~scanf("%d%d%d",&r,&c,&cost))
    {
        priority_queue<prog>que;
        int i,j;
        p_num=0;
        for(i=0;i<r;i++)
        {
            scanf("%s",mat[i]);
            for(j=0;j<c;j++)
            {
                if(mat[i][j]=='P')
                    p[p_num].x=i,p[p_num++].y=j;
                if(mat[i][j]=='Y')
                    start.x=i,start.y=j;
                if(mat[i][j]=='C')
                    end.x=i,end.y=j;
            }
        }
        prog a;
        a.cnt=0;
        a.x=start.x;
        a.y=start.y;
        que.push(a);
        zero(hash);
        hash[a.x*c+a.y]=1;
        while(!que.empty())
        {
            prog tmp=que.top();
            que.pop();
            for(i=0;i<4;i++)
            {
                a=tmp;
                a.x+=fx[i][0];
                a.y+=fx[i][1];
                
                if(a.x<0||a.y<0||a.x>=r||a.y>=c)
                    continue;
                if(mat[a.x][a.y]=='#')
                    continue;
                if(hash[a.x*c+a.y]==1)
                    continue;
                hash[a.x*c+a.y]=1;
                
                if(mat[a.x][a.y]=='C')
                {
                    printf("%d\n",cost*a.cnt);
                    goto over;
                }
                if(mat[a.x][a.y]=='*')
                    a.cnt++;
                if(mat[a.x][a.y]=='P')
                {
                    for(j=0;j<p_num;j++)
                    {
                        prog t;
                        t.x=p[j].x;
                        t.y=p[j].y;
                        hash[t.x*c+t.y]=1;
                        t.cnt=a.cnt;
                        que.push(t);
                    }
                    continue;
                }
                que.push(a);
            }
        }
        printf("Damn teoy!\n");
over:;
    }
    return 0;
}
```
