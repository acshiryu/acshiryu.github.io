title: POJ 2485 Highways 解题报告
toc: true
tags:
  - 图论
  - 最小生成树
categories:
  - 算法竞赛
id: 956
date: 2012-03-10 01:04:58
---

题目大意就是求最小生成树的最大权边，关于求法不再重复，详情请见本博客的今天和昨天题目的解题报告，可以看到此题的类似解法，可以直接把那代码贴过来，改两行就行了。

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int map[500][500];
 int lowcost[500];
 const int inf = (1&lt;&lt;20) ;
 int main()
 {
     int n;
     int t;
     cin &gt;&gt; t;
     while ( t -- )
     {
         cin &gt;&gt; n ;
         int i , j ;
         for ( i = 0 ; i &lt; n ; i ++ )
             for ( j = 0 ; j &lt; n ; j ++ )
                 cin &gt;&gt; map[i][j];
         for ( i = 0 ; i &lt; n ; i ++ )
             lowcost[i]=map[0][i];    //初始化各点到集合的距离
         int ans=0;//记录生成树的最大权值
         for ( i = 0 ; i &lt; n-1 ; i ++ )
         {
             int mindis=inf;
             int minone;
             for ( j = 0 ; j &lt; n ; j ++ )
             {//寻找到集合距离最近的点
                 if(lowcost[j]&amp;&amp;mindis&gt;lowcost[j])
                 {
                     mindis=lowcost[j];
                     minone=j;
                 }
             }
             if(ans &lt;mindis )
                 ans =mindis;
             lowcost[minone]=0;
             for ( j = 0 ; j &lt; n ; j ++ )
             {//更新各点到集合的距离
                 if(lowcost[j]&gt;map[minone][j])
                     lowcost[j]=map[minone][j];
             }
         }
         cout&lt;&lt;ans&lt;&lt;endl;
     }
     return 0;
 }[/code]