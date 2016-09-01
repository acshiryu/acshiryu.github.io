title: POJ 1325 Machine Schedule 解题报告
toc: true
tags:
  - 图论
  - 最小覆盖点
categories:
  - 算法竞赛
id: 961
date: 2012-03-10 01:07:57
---

题目大意就是有两台机器A，B，分别由m和n种模式，初始时都在模式0，现在有k个工作，每一个工作都可以将A设置成模式i或将B设置成模式j，但每一次更换模式时机器不得不要重启，求完成所有工作的最小重启次数

输入数据的第一行有三个数据，分别代表工作数，A/B的模式数，当输入0时结束程序，接下来多行，每行的开始代表工作的序号，和完成该工作需将A/B设置的模式数，

输出一个整数，代表机器最小重启次数，

这一题关键的地方在于建图，图建好了问题就迎刃而解，这题可以将每一个工作的A/B的模式连接成一条边，这样就构成了一个二分图，这样每一个工作都可以由图中所构成的边完成，故我们只需要用最少的顶点覆盖每一条边就行了，也就是说题目要求求的最小重启次数实际上是要求二分图的最小覆盖数，在根据二分图的一个重要性质，最小覆盖数=最大匹配数，关于证明详见Matrix67's Blog。

关于求二分图最大匹配的算法这里不再重复，详见POJ 1274 The Perfect Stall 解题报告

参考代码（未加注释，因为代码和POJ 1274很像，建议直接看[POJ 1274 The Perfect Stall 解题报告](http://acshiryu.com/archives/958 "POJ 1274 The Perfect Stall 解题报告")）：
[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int m , n , k ;
 bool map[100][100] , vis [100];
 int link [100];
 bool find ( int x ) 
 {
     int i ;
     for ( i = 1 ; i &lt; n ; i ++ )
     {
         if (map[x][i] &amp;&amp; !vis[i] )
         {
             vis[i]=true;
             if( link [i] == 0 || find ( link [i] ) )
             {
                 link [i] = x ;
                 return true ;
             }
         }
     }
     return false ;
 }
 int main()
 {
     while ( cin &gt;&gt; m , m )
     {
         cin &gt;&gt; n &gt;&gt; k ;
         int i , j ;
         memset ( map , 0 , sizeof ( map ) ) ;
         memset ( link , 0 , sizeof ( link ) );
         for ( i = 0 ; i &lt; k ; i ++ )
         {
             int a , b , c ;
             cin &gt;&gt; a &gt;&gt; b &gt;&gt; c ;
             if ( b == 0 || c == 0 )
                 continue ;
             map [b][c] = true ;
         }
         int ans = 0 ;
         for ( i = 1 ; i &lt; m ; i ++ )
         {
             memset ( vis , 0 , sizeof ( vis ) ) ;
             if ( find ( i ) )
                 ans ++ ;
         }
         cout &lt;&lt; ans &lt;&lt; endl ;
     }
     return 0;
 }[/code]