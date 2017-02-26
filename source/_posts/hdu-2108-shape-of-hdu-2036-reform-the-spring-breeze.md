title: hdu2108和hdu2036  叉乘的运用
toc: true
tags:
  - 计算几何
categories:
  - 算法竞赛
id: 994
date: 2012-03-10 23:51:40
---

题目地址：

http://acm.hdu.edu.cn/showproblem.php?pid=2108

http://acm.hdu.edu.cn/showproblem.php?pid=2036

这两道题目分别是判断一个多边形是否是凸多边形，求一个多边形的面积

题意很简单，题目也不难，算是最基础的计算几何了

参考资料：计算几何基础

参考代码：

hdu2108 by ACShiryu
[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 struct ac {
     int x ;
     int y ;
 }po[555555];
 int cross(ac a , ac b ,ac c)
 {
     return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
 }
 bool convex(int n)
 {
     for(int i = 0 ; i &lt; n ; i ++)
         if(cross(po[i],po[(i+1)%n],po[(i+2)%n])&lt;0)
             return false;
     return true;
 }
 int main()
 {
     int n ;
     while (cin &gt;&gt; n , n)
     {
         for (int i=0;i &lt; n ; i ++ )
             cin &gt;&gt; po[i].x &gt;&gt; po[i].y;
         if (convex(n))
             cout&lt;&lt;&quot;convex&quot;&lt;&lt;endl;
         else
             cout&lt;&lt;&quot;concave&quot;&lt;&lt;endl;
     }
     return 0;
 }[/code]
　　hdu2036 by ACShiryu
[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 struct ac {
     int x ;
     int y ;
 }po[555555];
 int cross(ac a , ac b ,ac c)
 {
     return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
 }
 bool convex(int n)
 {
     for(int i = 0 ; i &lt; n ; i ++)
         if(cross(po[i],po[(i+1)%n],po[(i+2)%n])&lt;0)
             return false;
     return true;
 }
 int main()
 {
     int n ;
     while (cin &gt;&gt; n , n)
     {
         for (int i=0;i &lt; n ; i ++ )
             cin &gt;&gt; po[i].x &gt;&gt; po[i].y;
         if (convex(n))
             cout&lt;&lt;&quot;convex&quot;&lt;&lt;endl;
         else
             cout&lt;&lt;&quot;concave&quot;&lt;&lt;endl;
     }
     return 0;
 }[/code]