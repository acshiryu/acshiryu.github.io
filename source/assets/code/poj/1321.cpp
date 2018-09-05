#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct prog {
    char map [10][10];    //棋盘
    int x;                //上一个棋子的行数
};
int m;                    //棋盘大小
int ans;                //解的个数
void DFS(prog tmp,int n)
{
    if(n==0)
    {//如果要求放的所有棋子都已经放好了，则索命找到了答案，则计数+1并返回
        ans++;
        return ;
    }
    int i , j ;
    for ( i = tmp.x + 1 ; i <= m -n; i ++ )
    {//从上个棋子的下一行开始搜，如果剩余可放棋子数明显大于剩余行数，则可以知道此时无解
        for ( j = 0 ; j < m ; j ++ )
        {//从该行的第一个棋盘开始搜到最后一个
            if ( tmp.map[i][j]=='#')
            {//如果找到了一点可以放棋子
                prog tmp2;
                tmp2=tmp;
                tmp2.x=i;//记下改点的行数
                int k;
                for (k = i+1 ; k < m ; k ++)
                {//更新棋盘，因为，不会再向该行和该行之前的棋盘搜索，故只用更新该行下同列的棋盘
                    tmp2.map[k][j]='.';
                }
                DFS(tmp2,n-1);//放好一个棋子，继续搜

            }
        }
    }
}
int main()
{

    int  n ;            //要求放棋子的多少
    while ( cin >> m >> n , m != -1 || n != -1 )
    {
        ans=0;//初始化为0
        prog map;
        map.x=-1;//此时还未放棋子，初始化为-1
        int i;
        for ( i = 0 ; i < m ; i ++ )
        {
            cin >> map . map [ i ];
        }
        DFS(map,n);
        cout<<ans<<endl;
    }
    return 0;
}