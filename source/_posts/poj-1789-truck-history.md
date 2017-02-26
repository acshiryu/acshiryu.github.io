title: POJ 1789 Truck History 解题报告
toc: true
tags:
  - Prim
  - 图论
  - 生成树
categories:
  - 算法竞赛
id: 947
date: 2012-03-09 17:20:29
---

题目大意是就是给出n个长度为7的字符串，每个字符串代表一个车，定义车的距离是两个字符串间不同字母的个数，题目要求的数不同的车的距离的最小值，即所求的就是最小生成树

关于数据的输入和输出详见样例，要注意输出完数据后还有个'.'，这题是一个稠密图，用Prim算法比较好，关于Prim算法详见：
http://www.nocow.cn/index.php/Prim%E7%AE%97%E6%B3%95

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 char str[2000][8];
 int dis[2000][2000];
 int lowdis[2000];
 int main()
 {
     int n ;
     while ( cin &gt;&gt; n , n )
     {
         int i , j , k ;
         for ( i = 0 ; i &lt; n ; i ++ )
             cin &gt;&gt; str [i];
         memset(dis,0,sizeof(dis));
         //求任意两车之间的距离
         for ( i = 0 ; i &lt; n - 1 ; i ++ )
         {
             for ( j = i+1 ; j &lt; n ; j ++ )
             {
                 for ( k = 0 ; k &lt; 7 ; k ++ )
                 {
                     if(str[i][k]!=str[j][k])
                         dis[i][j]++;
                 }
                 dis[j][i]=dis[i][j];
             }
         }
         //初始化集合和颠倒集合的距离
         for ( i = 0 ; i &lt; n ; i ++ )
             lowdis[i]=dis[0][i];
         int ans = 0 ;    //    所求的解
         for ( i = 0 ; i &lt; n - 1 ; i ++ )
         {
             int mindis = ( 1 &lt;&lt; 20 ) ;
             for ( j = 0 ; j &lt; n ; j ++ )
             {
                 if( lowdis[j] &amp;&amp; mindis &gt; lowdis[j] )
                 {//寻找到集合距离最小的点
                     mindis = lowdis[j] ;
                     k = j;
                 }
             }
             ans += mindis ;
             lowdis[k] = 0 ;
             for ( j = 0 ; j &lt; n ; j ++ )
             {//更新各点到集合的距离
                 if(lowdis[j]&gt;dis[k][j])
                     lowdis[j]=dis[k][j];
             }
         }
         //输出答案，注意后面还有个‘.’
         cout&lt;&lt;&quot;The highest possible quality is 1/&quot;&lt;&lt;ans&lt;&lt;&quot;.&quot;&lt;&lt;endl;
     }
     return 0;
 }[/code]