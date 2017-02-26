title: poj3070来体会矩阵的妙用
toc: true
tags:
  - 快速幂
  - 斐波那契数列
  - 矩阵
categories:
  - 算法竞赛
id: 1009
date: 2012-03-10 23:58:50
---

题目大意就是求出斐波那契数列第k项的后四位，如果有前导0就不输出0，但最后一个0必须输出

刚开始的时候就想到了一个关于斐波那契数列的数列的一个公式，准备用那个公式求的，但题目已经提示了用矩阵，就没用那个公式

这一题就要注意到矩阵

的右上角或左下角对应的值正好是第n项的值

故可以通过快速幂来求得斐波那契数列的哦n项，由于数据较大，还要记得要不断的对10000取模

矩阵的快速幂我是直接抄的模板，刚开始时不理解，现在懂了，详情直接看代码

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 struct prog {
     int a[2][2] ;
     void init(){
         a[0][0]=a[1][0]=a[0][1]=1;
         a[1][1]=0;
     }
 };

 prog matrixmul ( prog a ,prog b )
 {
     int i , j , k ;
     prog c ;
     for ( i = 0 ; i &lt; 2; i ++ )
     {
         for ( j = 0 ; j &lt; 2 ; j ++ )
         {
             c.a[i][j]=0;
             for ( k =0 ; k &lt; 2; k ++ )
                 c.a[i][j]+=(a.a[i][k]*b.a[k][j]) ;
             c.a[i][j] %= 10000 ;
         }
     }
     return c ;
 }
 prog mul (prog s , int k )
 {
     prog ans ;
     ans.init();
     while ( k &gt;= 1 )
     {
         if ( k &amp; 1 )
             ans = matrixmul ( ans , s ) ;
         k = k &gt;&gt; 1 ;
         s = matrixmul ( s , s ) ;
     }
     return ans ;
 }
 int main()
 {
     int n ;
     while ( cin &gt;&gt; n , ~ n )
     {
         if ( ! n )
         {
             cout&lt;&lt;0&lt;&lt;endl ;
             continue ;
         }
         prog s ;
         s.init ( ) ;
         s = mul ( s , n - 1 ) ;
         cout &lt;&lt; s . a [0][1] % 10000 &lt;&lt;endl;
     }

     return 0;
 }[/code]