title: poj2115 同余方程与扩展欧几里德
toc: true
tags:
  - 中国剩余定理
  - 同余方程
categories:
  - 算法竞赛
id: 979
date: 2012-03-10 01:17:59
---

题目意思给出A,B,C，问对于C语句语句
[code lang="cpp"]
for (variable = A; variable != B; variable += C)
  statement;
[/code]

循环的次数，如果是死循环，就输出FOREVER 。其中数据都在2^k内，且都为非负数,也就是说当数据大于2^k时就要对2^k取模

这题题目意思很好理解，细细观察发现假设循环执行了t次，则会有 （A + C×t ）= B mod 2 ^k 题目就是要求的最小的非负数t 。

对于同余方程的解法，可以参考http://www.cnblogs.com/ACShiryu/archive/2011/08/03/2126676.html

题目数据虽然都是32位，但在中间算的时候有可能超int 故要用__int64 刚开始没注意到，WA了2次，有一次是对1左移时没强制转换。

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 void gcd ( __int64 a , __int64 b , __int64 &amp;d , __int64 &amp;x ,__int64 &amp;y )
 {
     if ( ! b ) 
         d = a , x = 1 , y = 0 ;
     else
         gcd ( b , a % b , d , y , x ) , y -= x * ( a / b ) ;
 }
 int main()
 {
     __int64 a, b , c, k ;
     while ( cin &gt;&gt; a &gt;&gt; b &gt;&gt; c &gt;&gt; k , a || b || c || k )
     {
         __int64 d , x , y ;
         gcd ( c ,  ( ( __int64 ) 1 )&lt;&lt; k , d , x , y ) ;
         if ( ( b - a ) % d != 0 )
             cout &lt;&lt; &quot;FOREVER&quot; &lt;&lt;endl;
         else
         {
             __int64 ans = ( b - a ) / d * x ;
             ans = ans % ( (  ( ( __int64 ) 1 )&lt;&lt; k ) / d ) ;
             if ( ans &lt; 0 )
                 ans += (  ( ( __int64 ) 1 )&lt;&lt; k ) / d ;
             cout &lt;&lt; ans &lt;&lt; endl ;
         }
     }
     return 0;
 }[/code]