title: 通过POJ1061青蛙的约会来谈拓展欧几里德算法
toc: true
tags:
  - 同余方程
  - 扩展欧几里德
  - 数论
categories:
  - 算法竞赛
id: 963
date: 2012-03-10 01:08:56
---

对于题目中的数据，详见下表
![](http://pic002.cnblogs.com/images/2011/315754/2011080320313778.png)
故，可得两只青蛙跳四次就可以在点3处相遇

对于这道题可以知道，当他们相遇时距离原点的位移是相等的，则假设青蛙跳了t次后，则他们相对于原点的位移是

A：（x+mt）%l

B：（y+nt）%l

则可以列方程（x+mt）-（y+nt）=cl  （ c为整数）

则变形得 (m-n)t-cl=y-x;

题目要求的就是要使等式成立时最小时的正整数t

在解决这个问题前，我们首先就应该知道什么是扩展欧几里德算法

即

找出一对整数（x，y），使得ax+by=gcd（a，b）。

注意，这里的x和y不一定是正数，也可能是负数或者0.

下面是扩展欧几里德算法的源程序：（参考刘汝佳的《算法竞赛入门经典》第179页）
[code lang="cpp"]
void gcd ( int a , int b , int&amp;d , int&amp;x , int&amp;y )
{//a，b分别代表方程的系数，d返回a，b的最大公约数，x，y返回对应的解
    if ( ! b )//当b等于0的时候，方程就变成了ax=gcd（a，0）=a，所以此时明显可以得到方程的解为x=1，y=0，此时d就为a
        d = a , x =1 , y =0 ;
     else
     {//递归求方程的解，等下证明
          gcd ( b , a % b , d , y , x ) ;
          y -= ( a / b ) * x ; 
    }
}[/code]
书上对该算法没有给出证明，只有“用数学归纳法并不难证明算法的正确性”一笔代过，现在，去我们就来证明该算法的正确性

当b=0时很好理解，详见上面的注释

关键是当b=/=0，则我们先来假设方程的ax+by=gcd（a，b）=d的一个正整数解为x1，y1；别怀疑，这个方程一定有解

则有ax1+by1=gcd（a，b）   （1）

又对于方程bx +（a mod b）y =gcd （b ，a mod b )有解x2，y2（假设）

则有bx2+(a mod  b)y2=gcd ( b,a mod b) = gcd(a, b)   （2）

又a mod b = a - (a/b)*b；

则（2）式变为bx2+(a-(a/b)*b)y2=gcd(a,b);

即 ay2 + b(x2-(a/b)*y2) = gcd (a,b)    (3) ;

对比（1）（3）得

x1=y2    ;     y1 =  x2 - (a/b)*y2

故，ax+by=gcd（a，b）的解只需要在方程bx +（a mod b）y =gcd （b ，a mod b )的解的基础上进行简单的运算就变成原来方程的解，因为gcd不断递推时会有b=0的情况出现，故可以通过递推来得到方程的解

然后得出了关于方程ax+by=gcd（a，b）的解x0，y0，

但如何要求题目所要求的解了；

假设方程是ax+by=c；

现在我们已经知道了ax+by=gcd（a，b）的解x0，y0，即ax0+by0=gcd（a，b）；

则等式两边同乘以c/gcd（a，b）则得

ax0*c/gcd(a,b)+by0*c/gcd(a,b)=c;（则可知人如果c不是gcd（a，b）的倍数则无解）

故可以得到原方程的一个解是x1=x0*c/gcd(a,b)，y1=y0*c/gcd(a,b)，

再根据下面的结论就可以很好的得出此题的答案了

**设a，b，c为任意整数。若方程ax+by=c的一组整数解为（x0，y0），则它的任意整数解都可以写成（x0+kb',y0-ka'),其中a'=a/gcd（a，b），b'=b/gcd（a，b），k为任意整数**

关于上面的结论很好证明，此处略。

刚开始的时候没有注意到怎样就解答系，WA了两次

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;

 void gcd ( __int64 a , __int64 b , __int64 &amp;d , __int64 &amp;x , __int64 &amp;y )
 {

     if ( ! b ) 
         d = a , x = 1 , y = 0 ;
     else 
         gcd ( b , a%b , d , y , x ) , y -= x * ( a / b ) ; 
 }

 int main()
 {
     __int64 s , t , m , n , l ;
     while ( ~ scanf (&quot;%I64d%I64d%I64d%I64d%I64d&quot; , &amp; s , &amp; t , &amp; m , &amp; n , &amp; l ) )
     {
         __int64 a , b , d , ans ;
         __int64 x , y ;
         a = l ;
         b = m - n ;
         ans = t - s ;
         if ( b &lt; 0 )
             b = n - m , ans = s - t ;
         gcd ( a , b , d , x , y ) ;
         if ( ans % d )//无解出现的情况
             printf(&quot;Impossible\n&quot;) ;
         else
         {
             __int64 tmp = l / d ;        
             ans = (  ans / d * y ) % tmp ;//求出答案，因答案要求最小，故还得对答案的“周期”取余
             if ( ans &lt; 0 )//如果出现的是负数，就要加上周期
                 ans += tmp ;
             printf (&quot;%I64d\n&quot;,ans);
         }
     }
     return 0;
 }[/code]