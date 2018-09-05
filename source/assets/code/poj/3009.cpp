#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int w,h;
struct prog{
    int map[25][25];//迷宫地图
    int x ;    int y ；//此时的坐标
};
int step;            //最优移动次数，初始时为11
void DFS ( prog tmp , int k )
{
    if(k>=step)        //如果递归层数不小于最优移动次数，就没必要继续搜索
        return ;
    int i , j ;

    if(tmp.x+1<h&&tmp.map[tmp.x+1][tmp.y]!=1)
    {//如果该处下面没越界，并且不是障碍物
        for ( i = 1 ; tmp.x + i < h; i ++ )
        {//从该处深度+1开始，一步步寻找
            if(tmp.map[tmp.x+i][tmp.y]==1)
            {//如果找到某处有障碍物，则从该处开始继续搜索
                prog tmp2=tmp;                //定义一个临时结构体
                tmp2.map[tmp.x+i][tmp.y]=0;    //将该处的障碍物消失
                tmp2.x=tmp.x+i-1;            //位置应为障碍物的上面
                DFS(tmp2,k+1);                //继续搜索
                break;
            }

            if(tmp.map[tmp.x+i][tmp.y]==3)
            {//如果经过了3，即终点
                if(step>k+1)    //看搜索的结果是否比最优解优，如果优，更新step
                    step=k+1;
                return ;
            }
        }
    }

    //下面的搜索原理和上面类似，注释略

    if(tmp.x-1>=0&&tmp.map[tmp.x-1][tmp.y]!=1)
    {//向上
        for ( i = 1 ; tmp.x - i >=0; i ++ )
        {
            if(tmp.map[tmp.x-i][tmp.y]==1)
            {
                prog tmp2=tmp;
                tmp2.map[tmp.x-i][tmp.y]=0;
                tmp2.x=tmp.x-i+1;
                DFS(tmp2,k+1);
                break;
            }

            if(tmp.map[tmp.x-i][tmp.y]==3)
            {
                if(step>k+1)
                    step=k+1;
                return ;
            }
        }
    }

    if(tmp.y+1<w&&tmp.map[tmp.x][tmp.y+1]!=1)
    {//向右
        for ( i = 1 ; tmp.y + i < w; i ++ )
        {

            if(tmp.map[tmp.x][tmp.y+i]==1)
            {
                prog tmp2=tmp;
                tmp2.map[tmp.x][tmp.y+i]=0;
                tmp2.y=tmp.y+i-1;
                DFS(tmp2,k+1);
                break;
            }

            if(tmp.map[tmp.x][tmp.y+i]==3)
            {
                if(step>k+1)
                    step=k+1;
                return ;
            }
        }
    }

    if(tmp.y-1>=0&&tmp.map[tmp.x][tmp.y-1]!=1)
    {//向左
        for ( i = 1 ; tmp.y - i >=0; i ++ )
        {
            if(tmp.map[tmp.x][tmp.y-i]==1)
            {
                prog tmp2=tmp;
                tmp2.map[tmp.x][tmp.y-i]=0;
                tmp2.y=tmp.y-i+1;
                DFS(tmp2,k+1);
                break;
            }
            if(tmp.map[tmp.x][tmp.y-i]==3)
            {
                if(step>k+1)
                    step=k+1;
                return ;
            }

        }
    }

}
int main()
{
    while(cin>>w>>h,w&&h)
    {//输入长高
        prog cur;
        int i , j ;
        memset(cur.map,0,sizeof(cur.map));
        for ( i = 0 ; i < h ; i ++ )
        {
            for ( j = 0 ; j < w ; j ++ )
            {
                cin >> cur.map[i][j];
                if(cur.map[i][j]==2)
                {//记录起点坐标
                    cur.x=i;
                    cur.y=j;
                }
            }
        }
        step=11;//初始化为11
        DFS( cur , 0 );
        if(step==11)//说明没找到解
            cout<<-1<<endl;
        else
            cout<<step<<endl;
    }
    return 0;
}