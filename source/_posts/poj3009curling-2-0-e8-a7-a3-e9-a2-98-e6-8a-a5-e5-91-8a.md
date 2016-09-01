title: POJ3009Curling 2.0解题报告
toc: true
tags:
  - DFS
  - 搜索
categories:
  - 算法竞赛
id: 931
date: 2012-03-09 17:08:25
---

题目大意就是给出一个w*h的地图，其中0代表空地，1代表障碍物，2代表起点，3代表终点，每次行动可以走多个方格，每次只能向附近一格不是障碍物的方向行动，直到碰到障碍物才停下来，此时障碍物也会随之消失,如果行动时超出方格的界限或行动次数超过了10则会game over .如果行动时经过3则会win，记下此时行动次数（不是行动的方格数），求最小的行动次数

由于题目给出要在10步内找到最优解，又每次可以向四个方向进行搜索，时间复杂度是O（4^10）=O((2^10)^2)=O(1000^2)=O(1000000)

在搜索时如果发现此时搜索的层次已经大于最优解，则可以回溯，因为继续向下搜也不会再出现更优解。

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int w,h;
 struct prog{
     int map[25][25];//迷宫地图
     int x ;    int y ；//此时的坐标
 };
 int step;            //最优移动次数，初始时为11
 void DFS ( prog tmp , int k )
 {
     if(k&gt;=step)        //如果递归层数不小于最优移动次数，就没必要继续搜索
         return ;
     int i , j ;

     if(tmp.x+1&lt;h&amp;&amp;tmp.map[tmp.x+1][tmp.y]!=1)
     {//如果该处下面没越界，并且不是障碍物
         for ( i = 1 ; tmp.x + i &lt; h; i ++ )
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
                 if(step&gt;k+1)    //看搜索的结果是否比最优解优，如果优，更新step
                     step=k+1;
                 return ;
             }
         }
     }

     //下面的搜索原理和上面类似，注释略

     if(tmp.x-1&gt;=0&amp;&amp;tmp.map[tmp.x-1][tmp.y]!=1)
     {//向上
         for ( i = 1 ; tmp.x - i &gt;=0; i ++ )
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
                 if(step&gt;k+1)
                     step=k+1;
                 return ;
             }
         }
     }

     if(tmp.y+1&lt;w&amp;&amp;tmp.map[tmp.x][tmp.y+1]!=1)
     {//向右
         for ( i = 1 ; tmp.y + i &lt; w; i ++ )
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
                 if(step&gt;k+1)
                     step=k+1;
                 return ;
             }
         }
     }

     if(tmp.y-1&gt;=0&amp;&amp;tmp.map[tmp.x][tmp.y-1]!=1)
     {//向左
         for ( i = 1 ; tmp.y - i &gt;=0; i ++ )
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
                 if(step&gt;k+1)
                     step=k+1;
                 return ;
             }

         }
     }

 }
 int main()
 {
     while(cin&gt;&gt;w&gt;&gt;h,w&amp;&amp;h)
     {//输入长高
         prog cur;
         int i , j ;
         memset(cur.map,0,sizeof(cur.map));
         for ( i = 0 ; i &lt; h ; i ++ )
         {
             for ( j = 0 ; j &lt; w ; j ++ )
             {
                 cin &gt;&gt; cur.map[i][j];
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
             cout&lt;&lt;-1&lt;&lt;endl;
         else
             cout&lt;&lt;step&lt;&lt;endl;
     }
     return 0;
 }[/code]