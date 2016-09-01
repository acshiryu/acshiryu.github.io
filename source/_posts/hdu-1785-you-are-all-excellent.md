title: hdu 1785 You Are All Excellent
toc: true
tags:
  - 数学
categories:
  - 算法竞赛
id: 1015
date: 2012-03-11 00:05:02
---

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 struct prog{
     double x ;
     double y ;
     double asin0 ;
 }po[105];
 bool cmp ( prog a , prog b )
 {
     return a.asin0&lt;b.asin0;
 }
 int main()
 {
     int n ;
     while ( cin &gt;&gt; n , n &gt;= 0 )
     {
         int i , j ;
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             cin &gt;&gt; po[i].x &gt;&gt; po[i].y ;
             double z = sqrt ( pow ( po[i].x , 2) + pow ( po[i].y , 2 ) ) ;
             po[i].asin0 = acos ( po[i].x / z ) ;
         }
         sort ( po , po + n , cmp ) ;
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             if(i)
                 printf(&quot; &quot;);
             printf(&quot;%.1lf %.1lf&quot;,po[i].x,po[i].y);
         }
         printf(&quot;\n&quot;);
     }
     return 0;
 }
[/code]