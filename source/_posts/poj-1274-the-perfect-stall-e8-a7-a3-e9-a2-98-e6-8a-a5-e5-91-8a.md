title: POJ 1274 The Perfect Stall 解题报告
toc: true
tags:
  - 二分图
  - 匈牙利算法
  - 最大匹配
categories:
  - 算法竞赛
id: 958
date: 2012-02-25 15:13:51
---

题目大意就是求二分图的最大匹配，算得上是基础题，直接运用匈牙利算法可以求解，关于匈牙利算法昨天找了一天资料，看了无数ppt都没有搞懂，那些讲解都太抽象了，直接文字表述，连个图都没有，现在也只是对该算法一知半解。匈牙利算法的思想说白了就是要你从二分图中找出一条路径来，让路径的起点和终点都是还没有匹配过的点，并且路径经过的连线是一条没被匹配、一条已经匹配过，再下一条又没匹配这样交替地出现。找到这样的路径后，显然路径里没被匹配的连线比已经匹配了的连线多一条，于是修改匹配图，把路径里所有匹配过的连线去掉匹配关系，把没有匹配的连线变成匹配的，这样匹配数就比原来多1个。不断执行上述操作，直到找不到这样的路径为止。（传自Matrix67大牛的博客）

第一次做，刚开始不懂，看了nocow的代码后，自己当CPU运行了一遍，知道了大概，直接套模板把这题给AC了

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 bool map[201][201], vis[201] ;    //map保存两点间是否有边，vis保存每次操作后该数是否操作过
 int link[201] ;                    //link保存改点连接的另一点的序号
 int m , n ;
 bool find ( int k ) 
 {//对k寻找匹配，如果找到就记录匹配，并返回true,否则返回false
     int i , j ;
     for ( i = 1 ; i &lt;= n ; i ++ )
     {//对所有节点遍历一遍，寻找没有访问过并且与i连同的点
         if ( map [k][i] ==true &amp;&amp; ! vis[i] )
         {
             vis [i] = true ;    //记录改点以被访问
             if ( link [i] == 0 || find ( link [i] ) )
             {//如果该点还未与其他点匹配，或还能找到其他点能与该点匹配的点j进行匹配，即存在增广路
                 link [ i ] = k ;    //将i与k进行匹配
                 return true;
             }
         }
     }
     return false;
 }
 int main()
 {
     while ( cin &gt;&gt; m &gt;&gt; n ) 
     {//初始化，接受数据的输入
         memset ( map , false , sizeof ( map ) ) ;
         memset ( link , 0 , sizeof ( link ) ) ;
         int i , j ;
         for ( i = 1 ; i &lt;= m ; i ++ )
         {
             int s ;
             cin &gt;&gt; s ;
             for ( j = 0 ; j &lt; s ; j ++ )
             {
                 int k ;
                 cin &gt;&gt; k ;
                 map [i][k] = true ;
             }
         }

         int ans = 0 ;    //最大匹配数
         for ( i = 1 ; i &lt;= m ; i ++ )
         {
             memset ( vis , false , sizeof ( vis ) ) ;//对所有数据都初始为0，表明数据还没有试探
             if ( find ( i ) ) //如果对i找到一个匹配
                 ans ++ ;
         }
         cout&lt;&lt;ans&lt;&lt;endl;
     }
     return 0;
 }
[/code]