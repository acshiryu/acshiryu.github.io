title: POJ1251 Jungle Roads 解题报告
toc: true
tags:
  - Kruskal
  - 图论
  - 生成树
categories:
  - 算法竞赛
id: 951
date: 2012-03-09 17:22:47
---

题目大意在相通n个岛屿的所有桥都坏了，要重修，重修每一个桥所用的时间不同，求重修使每个岛屿都间接或直接与其他岛屿相同时所用的的最短时间（只有修完一个桥后才可修下一个桥）。简言之就是求最小生成树。

对于数据，数据输入的第一行n代表岛屿的个数，当为0是结束程序，接着n-1行开始时为这岛屿的编号，用大写字母表示，接着是一个整数m，表示与该岛屿连接的字典序大于该岛屿编号的个数，然后该行输入m对数据，每对数据的第一个字母表示与该岛屿连通的岛屿的编号，第二个数字表示要重修两岛屿之间桥所需要的时间，输出数据见样例及原题。

该题图为稀疏图，用Kruskal算法比较好，经过昨天对于生成树的题目的训练，今天终于对该类题目有所感觉，这题只是纯粹的求最小生成树，难度不大，我1次提交就AC了，点此进入关于Kruskal算法的详细介绍

[code lang="cpp"]
/*
 Kruskal算法的基本思想
 假设WN=(V,{E})是一个含有n个顶点的连通网，则按照克鲁斯卡尔算法构造最小生成树的过程为：
 先构造一个只含n个顶点，而边集为空的子图，
 若将该子图中各个顶点看成是各棵树上的根结点，则它是一个含有n棵树的一个森林。
 之后，从网的边集E中选取一条权值最小的边，若该条边的两个顶点分属不同的树，则将其加入子图，
 也就是说，将这两个顶点分别所在的两棵树合成一棵树；
 反之，若该条边的两个顶点已落在同一棵树上，则不可取，而应该取下一条权值最小的边再试之。
 依次类推，直至森林中只有一棵树，也即子图中含有n-1条边为止。
 */
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 const int inf = ( 1 &lt;&lt; 20 ) ;
 int p[27];        //    并查集，用于判断两点是否直接或间接连通
 struct prog {
     int u;
     int v;
     int w;
 }map[80];//存储边的信息，包括起点/终点/权值
 bool cmp ( prog a , prog b)
 {//排序函数，将边根据权值从小到大排
     return a.w&lt;b.w;
 }
 int find(int x)
 {//并查集的find，不解释
     return x==p[x]?x:p[x]=find(p[x]);
 }
 int main()
 {
     int n;
     while ( cin &gt;&gt; n , n ) 
     {
         int i , j ;
         for  ( i = 0 ; i &lt; 27  ; i ++ )
             p[i] = i ;//并查集初始化
         int k = 0 ;
         for ( i = 0 ; i &lt; n - 1 ; i ++ )
         {//构造边的信息
             char str[3];
             int m;
             cin &gt;&gt; str &gt;&gt; m ;
             for ( j = 0 ; j &lt; m ; j ++ ,k ++ )
             {
                 char str2[3];
                 int t;
                 cin &gt;&gt; str2 &gt;&gt; t ;
                 map[k].u=(str[0]-'A');
                 map[k].v=(str2[0]-'A');
                 map[k].w=t;
             }
         }

         sort ( map , map + k , cmp );//将边从小到大排序
         int ans=0;        //所要求的答案
         for ( i = 0 ; i &lt; k ; i ++ )
         {
             int x = find(map[i].u);
             int y = find(map[i].v);
             if( x!=y)
             {//如果两点不在同一连通分量里，则将两点连接，并存储该边
                 ans+=map[i].w;
                 p[x]=y;
             }
         }
         cout&lt;&lt;ans&lt;&lt;endl;
     }
     return 0;
 }[/code]