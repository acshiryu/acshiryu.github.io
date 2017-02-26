title: poj1080 人类基因配对
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 996
date: 2012-03-10 23:52:35
---

是就是求两基因的相似度，先要在每个基因对中加入若干空格，然后再依次加上匹配度，详见上表，则相似度就是最大的匹配度和

例如对于测试数据一，加上空格则变成

AGTGAT--G

-GT----TAG

则相似度就是（-3）+5+5+（-2）+5+（-1）+5=14，可以证明这是最大的，故为所求

此题为dp,详见代码

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int map[][5]={    {5,-1,-2,-1,-3},
                 {-1,5,-3,-2,-4},
                 {-2,-3,5,-2,-2},
                 {-1,-2,-2,5,-1},
                 {-3,-4,-2,-1,0} };
 char str1[105];
 char str2[105];
 int f[256];
 bool vis[105][105];
 int ans[105][105];
 int DFS ( int x , int y )
 {

     int i ;
     int xy=0;
     if ( x == -1 )
     {
         for ( i = 0 ; i &lt;= y ; i ++ )
             xy += map[str2[i]][4] ;
         return xy ;
     }
     if ( y == -1 )
     {
         for ( i = 0 ; i &lt;= x ; i ++ )
             xy += map[str1[i]][4] ;
         return xy ;
     }
     if ( vis[x][y] ) 
         return ans[x][y] ;
     vis[x][y]=true;
     ans[x][y] = max ( DFS ( x - 1 , y - 1 ) + map[str1[x]][str2[y]] , max ( DFS(x,y-1)+map[4][str2[y]] , DFS(x-1,y)+map[str1[x]][4] )) ;
     return ans[x][y] ;
 }
 int main()
 {
     f['A']=0;
     f['C']=1;
     f['-']=4;
     f['G']=2;
     f['T']=3;
     int t ;
     cin &gt;&gt; t ;
     while ( t -- )
     {
         int i , j ;
         int len1 , len2 ;
         cin &gt;&gt; len1 &gt;&gt; str1 ;
         for ( i = 0 ; i &lt; len1 ; i ++ )
             str1[i]=f[str1[i]];

         cin &gt;&gt; len2 &gt;&gt; str2 ;
         for ( i = 0 ; i &lt; len2 ; i ++ )
             str2[i]=f[str2[i]];
         memset ( vis , 0 , sizeof ( vis ) ) ;
         cout &lt;&lt; DFS(len1-1,len2-1) &lt;&lt; endl ;
     }
     return 0;
 }[/code]