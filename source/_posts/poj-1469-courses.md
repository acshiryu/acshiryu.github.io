title: POJ 1469 COURSES 解题报告
toc: true
tags:
  - 二分图
  - 图论
  - 最大匹配
categories:
  - 算法竞赛
id: 959
date: 2012-03-10 01:07:04
---

题目大意就是n个学生去p个课堂，每一个学生都有自己的课堂，并且每个学生只能去一个课堂，题目要求能够安排每一个课堂都有人吗？

输入数据的第一行是测试数据的个数，每组测试数据的开始分别是p和n，接着p行，每行的开始是这个课堂的学生人数m，接着m个数代表该课堂的学生编号，对于输出，如果该组数据能够这样安排就输出YES，否则输出NO。

例如，对于第一组数据明显可以这样匹配，3-3，2-2，1-1，而对于第二组数据则无法找到匹配方案，这题明显的求二分图的最大匹配，关于该算法详见POJ 1274 The Perfect Stall 解题报告 

但做这题的时候，用临界矩阵做刚开始时数组开小了，RE了一次，第二次TLE，后改为临界表，依旧TLE，最后，无奈，把cin全换成scanf时过了，在此要感谢laputa大神的提醒，Orz！

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 const int maxn = 301*101;
 int first[maxn],next[maxn],v[maxn];//头结点，下一点，和边的终点（即学生编号）
 bool vis[maxn];    //记录是否访问过
 int link [maxn];//记录与之匹配的点
 int p , n ;
 bool find ( int k )
 {
     int i ;
     for ( i = first[k] ; i != -1 ;  i =next [i] ) 
     {//寻找与k连接的点
         if ( !vis [v[i]] )
         {//如果没访问过，则访问并标记
             vis [ v[i]] =true ;
             if ( link [v[i]] == 0 || find ( link [v[i]] ) )
             {//如果该学生还未匹配课堂或存在增广路
                 link [v[i]] = k ;//与之匹配
                 return true ;
             }
         }
     }
     return false;
 }
 int main()
 {
     int t ; 
     scanf(&quot;%d&quot;,&amp;t) ;
     while ( t -- )
     {
         scanf(&quot;%d%d&quot;,&amp;p,&amp;n) ;
         if ( p &gt; n ) //如果学生人数都少于课堂数，明显不可能达到匹配
             cout &lt;&lt;&quot;NO&quot;&lt;&lt;endl;
         else
         {
             int i , j ; 
             memset ( first , -1 , sizeof ( first ) );    //初始化表头
             memset ( link , 0 , sizeof ( link ) ) ;        //初始化
             int e = 0 ;

             for ( i = 0 ; i &lt; p ; i ++ )
             {
                 int a ;
                 scanf(&quot;%d&quot;,&amp;a);
                 for ( j = 0 ; j &lt; a ; j ++ , e ++ )
                 {
                     scanf(&quot;%d&quot;,&amp;v[e]);
                     next [e] = first [i+1];    //插入链表，从头端插入
                     first [i+1] = e ;        //记录链表头结点
                 }
             }
             bool ans = 0 ;
             for ( i = 0 ; i &lt; p ; i ++ )
             {
                 memset ( vis , 0 , sizeof ( vis ) ) ;
                 if ( !find ( i + 1 ) )
                 {//如果找不到与改点匹配的点，则答案就为NO
                     ans =true;
                     break;
                 }
             }
             if ( ans )
                 cout&lt;&lt;&quot;NO&quot;&lt;&lt;endl;
             else
                 cout&lt;&lt;&quot;YES&quot;&lt;&lt;endl;
         }
     }
     return 0;
 }[/code]