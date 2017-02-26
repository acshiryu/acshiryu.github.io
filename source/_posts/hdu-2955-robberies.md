title: hdu2955 教你怎样抢银行划算！
toc: true
tags:
  - DP
  - 动态规划
  - 背包问题
categories:
  - 算法竞赛
id: 998
date: 2012-03-10 23:53:37
---

题目大意是有n家银行，每家银行可抢mi的金钱，被抓的分险是pi，当你的分险和大于p时就会被抓，求你在不被抓的前提下怎样才能抢到最多的钱,这题，就是01背包的小数形式，我们可以用pi表示抢到i金币时的最大逃脱率

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 double q[105];
 int m[105];
 double dp[10005];
 int main()
 {
     int t ;
     cin &gt;&gt; t ;
     while ( t -- )
     {
         double p ;
         int n ;
         cin &gt;&gt; p &gt;&gt; n ;
         int i , j ;
         int sum = 0 ;
         for ( i = 0 ; i &lt; n ; i ++ )
             cin &gt;&gt; m[i] &gt;&gt; q[i] , sum += m[i] ;
         memset ( dp , 0 , sizeof ( dp ) ) ;
         dp[0] = 1.0 ;
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             for ( j = sum ; j &gt;= m[i] ; j -- )
             {
                 dp[j] = max ( dp [j] , dp [j-m[i]] * ( 1 - q[i] ) ) ;
             }
         }
         for ( j = sum ;  j &gt;= 0 ; j -- )
             if ( dp [j] &gt;= 1 - p )
             {
                 cout &lt;&lt; j &lt;&lt; endl;
                 break;
             }
     }
     return 0;
 }[/code]