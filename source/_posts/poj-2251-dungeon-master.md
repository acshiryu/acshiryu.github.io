title: POJ2251 Dungeon Master 解题报告
toc: true
tags:
  - BFS
  - STL
  - 搜索
  - 队列
categories:
  - 算法竞赛
id: 935
date: 2012-03-09 17:12:58
---

题目大意：这题是一个三维的迷宫题目，其中用'.'表示空地，'#'表示障碍物，'S'表示起点，'E'表示终点，求从起点到终点的最小移动次数，解法和二维的类似，只是在行动时除了东南西北移动外还多了上下。

对于题目给出数据的含义就是输入l，r，c，分别代表迷宫有l层，每层长宽分别是c，r。

对于数据一可以这样移动
(1,1,1)->(1,1,2)->(1,1,3)->(1,1,4)->(1,1,5)->(1,2,5)->(1,3,5)->(1,3,4)->(1,4,4)->(2,4,4)->(2,4,5)->(3,4,,5)
共11步就可以到达终点 

对于数据二明显不能到达，则输出Trapped

这题用BFS解，每次去队首元素，如果是终点则输出结果移动的次数，否则，从该点开始分别向东南西北上下移动（如果可以走的话）并继续搜，如果到队列为空还没搜到解法，则说明无解。

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 #include&lt;queue&gt;
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
     while ( cin &gt;&gt; l &gt;&gt; r &gt;&gt; c , l &amp;&amp; r &amp;&amp; c )
     {
         int i , j , k;
         prog start;
         memset(hash,false,sizeof(hash));//初始化为false，表示每条路都没走过
         for ( i = 0 ; i &lt; l ; i ++ )
         {
             for ( j = 0 ; j &lt; r ; j ++ )
             {
                 cin &gt;&gt; map [i][j];
                 for ( k = 0 ; k &lt; c ; k ++ )
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

         queue&lt;prog&gt;bfs;
         bfs.push(start);    //起点入队
         bool found=false;    //标记变量，判断是否找到最优解，如果为true则说明从起点到终点存在着解

         while(!bfs.empty())
         {
             prog tmp=bfs.front();
             bfs.pop();

             if(map[tmp.x][tmp.y][tmp.z]=='E')
             {//已经到了终点，则将标记变量设为true，并输出答案
                 found=true;
                 cout&lt;&lt;&quot;Escaped in &quot;&lt;&lt;tmp.step&lt;&lt;&quot; minute(s).&quot;&lt;&lt;endl;
                 break;
             }

             tmp.step++;        //移动步子+1
             prog tmp2;
             if(tmp.x&gt;0)
             {//向下走，所以改点不能在第一层，则x要大于0
                 tmp2=tmp;
                 tmp2.x--;
                 if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&amp;&amp;hash[tmp2.x][tmp2.y][tmp2.z]==false)
                 {//如果下一层不是障碍物并且也没走过，则往下走，并标记该点已走过，入队
                     hash[tmp2.x][tmp2.y][tmp2.z]=true;
                     bfs.push(tmp2);
                 }
             }

             //下面搜索方法同上 注释略
             if(tmp.x&lt;l-1)
             {//向上
                 tmp2=tmp;
                 tmp2.x++;
                 if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&amp;&amp;hash[tmp2.x][tmp2.y][tmp2.z]==false)
                 {
                     hash[tmp2.x][tmp2.y][tmp2.z]=true;
                     bfs.push(tmp2);
                 }
             }

             if(tmp.y&gt;0)
             {//向北
                 tmp2=tmp;
                 tmp2.y--;
                 if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&amp;&amp;hash[tmp2.x][tmp2.y][tmp2.z]==false)
                 {
                     hash[tmp2.x][tmp2.y][tmp2.z]=true;
                     bfs.push(tmp2);
                 }
             }

             if(tmp.y&lt;r-1)
             {//向南
                 tmp2=tmp;
                 tmp2.y++;
                 if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&amp;&amp;hash[tmp2.x][tmp2.y][tmp2.z]==false)
                 {
                     hash[tmp2.x][tmp2.y][tmp2.z]=true;
                     bfs.push(tmp2);
                 }
             }

             if(tmp.z&gt;0)
             {//向西
                 tmp2=tmp;
                 tmp2.z--;
                 if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&amp;&amp;hash[tmp2.x][tmp2.y][tmp2.z]==false)
                 {
                     hash[tmp2.x][tmp2.y][tmp2.z]=true;
                     bfs.push(tmp2);
                 }
             }

             if(tmp.z&lt;c-1)
             {//向东
                 tmp2=tmp;
                 tmp2.z++;
                 if(map[tmp2.x][tmp2.y][tmp2.z]!='#'&amp;&amp;hash[tmp2.x][tmp2.y][tmp2.z]==false)
                 {
                     hash[tmp2.x][tmp2.y][tmp2.z]=true;
                     bfs.push(tmp2);
                 }
             }

         }
         if(!found)//如果没有找到解
             cout&lt;&lt;&quot;Trapped!&quot;&lt;&lt;endl;
     }
     return 0;
 }
[/code]