/*
Prim算法基本思想
1\. 在图G=(V, E) （V表示顶点 ，E表示边）中，从集合V中任取一个顶点（例如取顶点v0）放入集合 U中，这时 U={v0}，集合T(E)为空。
2\. 从v0出发寻找与U中顶点相邻（另一顶点在V中）权值最小的边的另一顶点v1，并使v1加入U。即U={v0,v1 }，同时将该边加入集合T(E)中。
3\. 重复2，直到U=V为止。
这时T(E)中有n-1条边，T = (U, T(E))就是一棵最小生成树。
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int map[100][100];
int lowcost[100];
const int inf = (1<<20) ;
int main()
{
    int n;
    while ( cin >> n )
    {
        int i , j ;
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
                cin >> map[i][j];
        for ( i = 0 ; i < n ; i ++ )
            lowcost[i]=map[0][i];    //初始化各点到集合的距离
        int ans=0;//记录生成树的长度
        for ( i = 0 ; i < n-1 ; i ++ )
        {
            int mindis=inf;
            int minone;
            for ( j = 0 ; j < n ; j ++ )
            {//寻找到集合距离最近的点
                if(lowcost[j]&&mindis>lowcost[j])
                {
                    mindis=lowcost[j];
                    minone=j;
                }
            }
            ans+=lowcost[minone];
            lowcost[minone]=0;
            for ( j = 0 ; j < n ; j ++ )
            {//更新各点到集合的距离
                if(lowcost[j]>map[minone][j])
                    lowcost[j]=map[minone][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}