title: POJ1321 棋盘问题 解题报告
toc: true
tags:
  - DFS
  - 搜索
categories:
  - 算法竞赛
id: 937
date: 2012-03-09 17:15:19
---

简单搜索题，题目意思很明了，其中'#'可以放棋子，'.'不能，并且同一行或同一列不能放两个棋子，

这题只需要深搜，每次从上一个放棋子地方的下一行开始寻找可以放棋子的地方，当发现该点时，记录行数，并更新棋盘，将于此点同行同列的都更新为'.'，如果找不到，则返回，当把所有棋子都放上去的时候，则找到一个接，计数+1，就这样进行搜索，可以保证AC

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
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
     for ( i = tmp.x + 1 ; i &lt;= m -n; i ++ )
     {//从上个棋子的下一行开始搜，如果剩余可放棋子数明显大于剩余行数，则可以知道此时无解
         for ( j = 0 ; j &lt; m ; j ++ )
         {//从该行的第一个棋盘开始搜到最后一个
             if ( tmp.map[i][j]=='#')
             {//如果找到了一点可以放棋子
                 prog tmp2;
                 tmp2=tmp;
                 tmp2.x=i;//记下改点的行数
                 int k;
                 for (k = i+1 ; k &lt; m ; k ++)
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
     while ( cin &gt;&gt; m &gt;&gt; n , m != -1 || n != -1 )
     {
         ans=0;//初始化为0
         prog map;
         map.x=-1;//此时还未放棋子，初始化为-1
         int i;
         for ( i = 0 ; i &lt; m ; i ++ )
         {
             cin &gt;&gt; map . map [ i ];
         }
         DFS(map,n);
         cout&lt;&lt;ans&lt;&lt;endl;
     }
     return 0;
 }[/code]