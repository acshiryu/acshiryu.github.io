title: "Codeforces Round #118 (Div. 2) :C. Plant"
toc: true
tags:
  - cf
  - 矩阵快速幂
categories:
  - 算法竞赛
id: 1349
date: 2012-05-05 21:51:20
---

就是求第n个图形的上三角的个数
设f[n]为第n个图形的上三角的个数  g[n]为第n个图形的下三角的个数
则有
`f[n]=3*f[n-1]+g[n-1];
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;g[n]=3*g[n-1]+f[n-1];`
则可以构造矩阵 用矩阵快速幂解决
![构造矩阵](/app/pic/archives/1349/1.png)
![构造矩阵](/app/pic/archives/1349/2.png)
[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 struct prog {
     __int64 a[2][2] ;
     void init(){
         a[0][0]=a[1][1]=3;
         a[1][0]=a[0][1]=1;
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
                 c.a[i][j]+=__int64(a.a[i][k]*b.a[k][j]) ;
             c.a[i][j] %= 1000000007  ;
         }
     }
     return c ;
 }
 prog mul (prog s , __int64 k )
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
     __int64 n ;
     while ( cin &gt;&gt; n  )
     {
		 if(n==0)
		 {
			 cout&lt;&lt;1&lt;&lt;endl;
			 continue;
		 }
         prog s ;
         s.init ( ) ;
         s = mul ( s , n - 1 ) ;
		 cout&lt;&lt;s.a[0][0]%1000000007&lt;&lt;endl;
     }

     return 0;
 }
[/code]