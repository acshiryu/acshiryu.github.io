title: poj3233 又见矩阵，不过是等比吗？
toc: true
tags:
  - 分治
  - 数学
  - 矩阵
categories:
  - 算法竞赛
id: 1007
date: 2012-03-10 23:57:44
---

题目大意很明了，初看是像是就等比数列前n项和，但公比是一个矩阵，能用吗？

我不知道，因为如果是类似等比数列前n项和的好像关于矩阵除法比较难写，中间涉及到逆举证神马的，直接忽略

输入的数据第一行分别是n，k，m

代表矩阵的是n×n型，求前k项和，结果的每一项对m取模

然后就是一个n×n的矩阵。

我做这题时用的是类似二分的方法做的，仔细观察可以发现

Sk = A + A2 + A3 + … + Ak   

    =(1+Ak/2)*(A + A2 + A3 + … + Ak/2  )+{Ak}

    =(1+Ak/2)*(Sk/2 )+{Ak}

**当k为偶数时不要大括号里面的数**

故可以用这方法直接推出答案，中间要记得对数取模，以防超int，还要注意S1=A ；

然后就是写矩阵乘法与加法部分，可直接套模板

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int n , m ;
 struct matrix {//矩阵
     int a[30][30];
     void init(  )
     {//初始化
         int i ;
         memset ( a, 0 ,sizeof ( a ) ) ;
         for ( i = 0 ; i &lt; 30 ; i ++ )
             a[i][i] = 1 ;
     }
 };
 void print ( matrix s )
 {//打印一个矩阵
     int i , j ;
     for ( i = 0 ; i &lt; n ; i ++ )
     {
         for ( j = 0 ; j &lt; n ; j ++ )
         {
             if ( j )
                 cout&lt;&lt;' ';
             cout&lt;&lt;s.a[i][j]%m;
         }
         cout&lt;&lt;endl;
     }
 }
 matrix matrixadd ( matrix a , matrix b )
 {//矩阵加法，计算时记得要取模，避免超int
     int i , j ;
     matrix c ;
     for ( i = 0 ; i &lt; n ; i ++ )
         for ( j = 0  ; j &lt; n ; j ++ )
             c.a[i][j]=((a.a[i][j]+b.a[i][j])%m);
     return c ;
 }
 matrix matrixmul ( matrix a , matrix b )
 {//矩阵乘法，计算时记得要取模，避免超int
     int i , j , k ;
     matrix c ;
     for ( i = 0 ; i &lt; n ; i ++ )
     {
         for ( j = 0 ; j &lt; n ; j ++ )
         {
             c.a[i][j]=0;
             for ( k = 0 ; k &lt; n ; k ++ )
                 c.a[i][j] +=((a.a[i][k]*b.a[k][j])%m) ;
             c.a[i][j] %= m ;
         }
     }
     return c ;
 }
 matrix mul ( matrix s , int k  )
 {//矩阵的k次方，快速幂
     matrix ans ;
     ans .init () ;
     while ( k &gt;= 1 )
     {
         if ( k &amp; 1 )
             ans = matrixmul ( ans , s ) ;
         k = k &gt;&gt; 1 ;
         s = matrixmul ( s , s ) ;
     }
     return ans ;
 }
 matrix sum ( matrix s , int k )
 {//举证前k项求和
     if ( k == 1 )
         return s ;
     matrix tmp ;//用来保存答案
     tmp.init();//初始化
     tmp = matrixadd ( tmp , mul ( s , k &gt;&gt; 1 ) );    //计算1+A^(k/2)
     tmp = matrixmul ( tmp , sum ( s , k &gt;&gt; 1 ) ) ;    //计算(1+A^(k/2))*(A + A^2 + A^3 + … + A^(k/2)  )
     if ( k&amp;1 )//考虑是否要+A^k
         tmp = matrixadd ( tmp , mul ( s , k ) ) ;
     return tmp ;//返回前n项的值
 }

 int main()
 {
     int k ;
     while ( cin &gt;&gt; n &gt;&gt; k &gt;&gt; m )
     {
         int i , j ;
         matrix s ;
         for ( i = 0 ; i &lt; n ; i ++ )
             for ( j = 0 ; j &lt; n ; j ++ )
                 cin &gt;&gt; s.a[i][j] ;
         s = sum ( s , k ) ;
         print(s);    
     }
     return 0;
 }
[/code]