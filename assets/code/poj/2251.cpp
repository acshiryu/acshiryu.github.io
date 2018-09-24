#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
bool hash[35][35][35];
char map[35][35][35];
struct prog{
    int x;int y;int z;        //定义点的坐标
    int step;                //移动的步子数
};
int main()
{
    int l , r , c ;
    while ( cin >> l >> r >> c , l && r && c )
    {
        int i , j , k;
        prog start;
        memset(hash,false,sizeof(hash));//初始化为false，表示每条路都没走过
        for ( i = 0 ; i < l ; i ++ )
        {
            for ( j = 0 ; j < r ; j ++ )
            {
                cin >> map [i][j];
                for ( k = 0 ; k < c ; k ++ )
                {
                    if(map[i][j][k]=='S')
                    {//对起点的相关变量初始化
                        start.x=i;
                        start.y=j;
                        start.z=k;
                        start.step=0;
                        hash[i][j][k]=true;
                    }
                }
            }
        }

        queue<prog>bfs;
        bfs.push(start);    //起点入队
        bool found=false;    //标记变量，判断是否找到最优解，如果为true则说明从起点到终点存在着解

        while(!bfs.empty())
        {
            prog tmp=bfs.front();
            bfs.pop();

            if(map[tmp.x][tmp.y][tmp.z]=='E')
            {//已经到了终点，则将标记变量设为true，并输出答案
                found=true;
                cout<<"Escaped in "<<tmp.step<<" minute(s)."<<endl;
                break;
            }

            tmp.step++;        //移动步子+1
            prog tmp2;
            if(tmp.x>0)
            {//向下走，所以改点不能在第一层，则x要大于0
                tmp2=tmp;
                tmp2.x--;
                if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
                {//如果下一层不是障碍物并且也没走过，则往下走，并标记该点已走过，入队
                    hash[tmp2.x][tmp2.y][tmp2.z]=true;
                    bfs.push(tmp2);
                }
            }

            //下面搜索方法同上 注释略
            if(tmp.x<l-1)
            {//向上
                tmp2=tmp;
                tmp2.x++;
                if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
                {
                    hash[tmp2.x][tmp2.y][tmp2.z]=true;
                    bfs.push(tmp2);
                }
            }

            if(tmp.y>0)
            {//向北
                tmp2=tmp;
                tmp2.y--;
                if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
                {
                    hash[tmp2.x][tmp2.y][tmp2.z]=true;
                    bfs.push(tmp2);
                }
            }

            if(tmp.y<r-1)
            {//向南
                tmp2=tmp;
                tmp2.y++;
                if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
                {
                    hash[tmp2.x][tmp2.y][tmp2.z]=true;
                    bfs.push(tmp2);
                }
            }

            if(tmp.z>0)
            {//向西
                tmp2=tmp;
                tmp2.z--;
                if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
                {
                    hash[tmp2.x][tmp2.y][tmp2.z]=true;
                    bfs.push(tmp2);
                }
            }

            if(tmp.z<c-1)
            {//向东
                tmp2=tmp;
                tmp2.z++;
                if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
                {
                    hash[tmp2.x][tmp2.y][tmp2.z]=true;
                    bfs.push(tmp2);
                }
            }

        }
        if(!found)//如果没有找到解
            cout<<"Trapped!"<<endl;
    }
    return 0;
}