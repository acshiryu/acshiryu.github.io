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