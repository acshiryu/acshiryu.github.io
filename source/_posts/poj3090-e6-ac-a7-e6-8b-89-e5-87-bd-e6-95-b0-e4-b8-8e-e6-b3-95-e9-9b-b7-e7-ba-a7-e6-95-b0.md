title: poj3090 欧拉函数与法雷级数
toc: true
tags:
  - 数论
  - 欧拉函数
  - 法雷级数
categories:
  - 算法竞赛
id: 983
date: 2012-03-10 01:19:42
---

题目大意先看上图，给出大小为n的图（有（n+1）^2个格点），求出图中可视点的个数，可视点就是在图中从（0，0）看不被遮挡的点，例如（1，1）是可视点，（2，2）不是，因为（2，2）被（1，1）给遮挡了

这一题和poj2478的解法类似，解答方法也相似，点此进入poj2478解题报告，这题是求法雷级数的题

然而也不能直接就把poj2478的代码个复制过来

因为对于这一题，并没有要求分子一定比分母小，也就是水（5，3）也是题目可视点，但进一步观察发现如果（a，b）是可视点，那么（b，a）也一定是可视点

则我们根据这个规律，我们就可以假设出a<b,则只要求出a<b的格点数，然后再乘以2

但还是会有问题，此题中（1，0），（0，1）也是格点数，但我们在运用欧拉函数时并不考虑0，并且也存在a=b的格点，即（1，1）

还好这样特殊的点并不多，只有三个，我们只需要特殊考虑就行了

刚开始是求欧拉函数没考虑边界大情形，RE了两次，最后发现问题，修正了一下，果然AC了

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int phi[1005];
 int main()
 {
     int i , j ;
     memset ( phi , 0 ,sizeof ( phi ) ) ;
     phi[1]=1;
     for ( i = 2 ; i &lt;1005 ; i ++ )
     {//筛选求phi
         if ( ! phi [i] )
         {
             for ( j = i ; j &lt;1005 ; j += i )
             {
                 if ( ! phi [j] )
                     phi [j ] = j ;
                 phi [j] = phi [j] / i * ( i - 1 ) ;
             }
         }
     }
     int t ;
     int k = 1 ;
     cin &gt;&gt; t ;
     while ( t-- )
     {
         int n ;
         cin &gt;&gt; n ;
         cout &lt;&lt; k &lt;&lt; ' ' &lt;&lt; n &lt;&lt; ' ';
         int sum = 3 ;//特别考虑的三个点，（1，0）（0，1）（1，1）
         for ( i = 2 ; i &lt;= n ; i ++ )
             sum += 2 *(phi [i] );
         cout&lt;&lt;sum&lt;&lt;endl;
         k++;
     }
     return 0;
 }[/code]