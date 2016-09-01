title: POJ2407Relatives --欧拉函数的简单运用
toc: true
tags:
  - 互素
  - 欧拉函数
  - 素数
categories:
  - 算法竞赛
id: 969
date: 2012-03-10 01:12:14
---

题目大意就是给一个数n，求出不大于n且与n互素的数的个数，
这就是简单的欧拉函数的运用，关于欧拉函数的求法，网上一搜一大堆，这里省略。
提交一次就A了，不过测试数据不强，我的程序对于1输出的是1，而实际应该是0
[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int main()
 {
     int n ;
     while ( scanf ( &quot;%d&quot;, &amp; n ) , n )
     {
         if ( n == 1 )
             printf (&quot;0\n&quot;) ; 
         else
         {
             int i , j , m;
             m = sqrt ( n + 0.5 ) ;
             int ans = n ;
             for ( i = 2; i &lt;= m ; i ++ )
                 if ( n % i == 0)
                 {
                     ans = ans / i * ( i - 1 ) ;
                     while ( n % i == 0 ) 
                         n /= i ;
                 }
             if ( n &gt; 1 )
                 ans = ans / n * ( n - 1 ) ;

             printf (&quot;%d\n&quot;,ans);
         }
     }
     return 0;
 }[/code]