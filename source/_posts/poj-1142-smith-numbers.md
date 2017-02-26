title: POJ1142Smith Numbers一道简单的数学题
toc: true
tags:
  - 数学
  - 数论
categories:
  - 算法竞赛
id: 965
date: 2012-03-10 01:09:49
---

题目大意就是要你找一个大于n的和数，并且满足他的各位的和与他所有的质因子的各位的和相等的最小的一个数，即此题的Smith Number

例如对于4937774，比他大的第一个数是4937775

因为4+9+3+7+7+7+5=42

又4937775=3*5*5*65837

而3+5+5+6+5+8+3+7=42

故4937775是题目要求的答案。

这是一道纯数学题，可以通过暴力直接得到答案，因为这样的数分布比较密，

不过在做这题时学到了很好的一个思想，分治法，详见代码；

提交1次就A了，刚开始时想复杂了，准备筛选做的，看了一下讨论，好像没必要，可直接暴力

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 bool isprime (int k)
 {//判断是否是素数
     int t = sqrt ( k + 0.5 );
     for ( int i = 2 ; i &lt;= t ; i ++ )
         if ( k % i == 0 )
             return false;
     return true;
 }
 int sum(int k)
 {//求出该数各位上的和
     int i , s;
     s = 0 ;
     while ( k != 0 )
     {
         i = k % 10 ;
         s += i ;
         k = k / 10 ;
     }
     return s;
 }
 int cut (int k )
 {//分治法思想，如果是素数，就返回sum，否则，就将该数分成两部分，再来求各部分的质因子的sum
     if ( isprime(k) )
         return sum (k);
     for ( int i = (int) sqrt (k + 0.5) ; i &gt;1 ; i -- )
         if ( k % i == 0 ) 
             return cut (i) + cut (k / i) ;
 }
 int main()
 {
     int n;
     while ( cin &gt;&gt; n , n )
     {
         while ( n ++ )
         {
             if (!isprime(n)&amp;&amp;sum(n)==cut(n))
                 break;
         }
         cout&lt;&lt;n&lt;&lt;endl;
     }
 }[/code]