title: "POJ2262Goldbach's Conjecture 简单的素数判定"
toc: true
tags:
  - 枚举
  - 素数
categories:
  - 算法竞赛
id: 967
date: 2012-03-10 01:10:54
---

题目大意就是输入一个不小于6的合数，把它表示成两个质数的和，如果有多个，数出相差最大的一组

这题就是简单的枚举+素数判定，没什么技巧

行开始时分解合数时到sqrt（n）时停止，WA了一次，应该是n/2

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 bool isprime ( int k )
 {
     int t = sqrt ( k + 0.5 ) ;
     for ( int i = 2  ; i &lt;= t ; i ++ )
         if ( k % i == 0 )
             return false ;
     return true ;
 }
 int main()
 {
     int n ;
     while ( scanf (&quot;%d&quot;, &amp;n) , n )
     {
         int i ;
         int t = n / 2 ;
         for ( i = 3 ; i &lt;= t ; i += 2 )
             if ( isprime ( i ) &amp;&amp; isprime ( n - i ) )
                 break ;
         printf ( &quot;%d = %d + %d\n&quot; , n , i , n - i ) ;
     }
     return 0;
 }[/code]