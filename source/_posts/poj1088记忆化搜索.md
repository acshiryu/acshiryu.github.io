title: poj1088记忆化搜索
toc: true
tags:
  - 记忆化搜索
categories:
  - 算法竞赛
id: 1000
date: 2012-03-10 23:54:21
---

就是从各点进行搜索，并用以数组记录搜索的结果，一遍下次搜索该处时再用
然后遍历一下该数组，找到最大的一个元素

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdio&gt;
 using namespace std;
 int map[105][105];
 int f[][2]={
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};
 int vis[105][105] ;
 int m , n ;
 int DFS ( int x , int y )
 {
     if ( vis[x][y] != -1 )
         return vis[x][y] ;
     int i ;
     int sum = 1 ;
     for ( i = 0 ; i &lt; 4 ; i ++ )
     {
         int s = x + f[i][0] ;
         int t = y + f[i][1] ;
         if ( s &lt; 0 || t &lt; 0 || s &gt;= m || t &gt;= n )
             continue;
         if ( map[s][t] &gt;= map[x][y] )
             continue;
         sum = max ( sum , DFS ( s , t ) + 1 ) ;
     }
     vis[x][y] = sum ;
     return sum ;
 }
 int main()
 {
     while ( cin &gt;&gt; m &gt;&gt; n )
     {
         int sum = 0;
         int i , j ;
         for ( i = 0 ; i &lt; m ; i ++ )
             for ( j = 0 ; j &lt; n ; j  ++ )
                 cin &gt;&gt; map [i][j] ;
         memset ( vis , -1 , sizeof ( vis ) ) ;
         for ( i = 0 ; i &lt; m ; i ++ )
             for ( j = 0 ; j &lt; n ; j  ++ )
                 sum = max ( sum , DFS ( i , j ) ) ; 
         cout &lt;&lt; sum &lt;&lt; endl ;
     }
     return 0 ;
 }[/code]