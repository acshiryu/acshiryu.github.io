title: POJ1019 ---简单的数学找规律题
toc: true
tags:
  - 找规律
  - 数字串
  - 递推
categories:
  - 算法竞赛
id: 973
date: 2012-03-10 01:14:21
---

题目大意就是给你这一串数字11212312341234512345612345671234567812345678912345678910123456789101112345678910……（未列完）

要我们求出第n个数是多少(从左到右看)，例如第2个是1，第三个是2，第八个是2；

如果仔细观察这一串数字，可以发现他可以还分为很多小串，假设第i小串是123……i，假设第i小串所占的空间是a[i]，则通过对比a[i]与a[i+1]发现，

第i+1串只比第i串多一个数，即i+1，故他们所占的空间差就是第i+1所占的空间。

对任意一个数所占的空间很好求，即 （int）log10（k）+1；

然后就可以求出每一个串的起始位置，通过与n比较就可以确定n出现在那一个串里，最后在求出n在这个串里的相对位置，就可以求出该题的解

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cmath&gt;
 #include&lt;cstdio&gt;
 using namespace std;
 int a1[32000] ;        //用来存储每一个串所占的空间
 __int64 a[32000] ;    //用来存储每一个串的起始位置
 int num[150000];    //打印出最大的一个串
 int main()
 {
     int i;
     a1[0]=0 ;
     a1[1]=1;
     for ( i = 2 ; i &lt; 32000 ; i ++ )
         a1[i] = a1[i-1] + (int)log10(1.0*i)+1;    //推导详见上文
     a[0]=1;
     for ( i = 1 ; i &lt; 32000 ; i ++ )
         a[i]=a[i-1]+a1[i-1];                    //上一个串的起点加所占空间就是下一个串的起点                
     int k = 1;
     for ( i = 1 ; i &lt; 31300 ; i ++ )
     {//打印最大的一个串
         char str[20];

         str[0]='0';
         int ti = i ;
         int len = 0 ;
         while (ti)
         {
             str[len]=ti%10+'0';
             ti=ti/10;
             len++;
         }
         while ( len -- )
         {
             num[k]=str[len]-'0';
             k++;
         }
     }
     int t;
     cin &gt;&gt; t;
     while ( t-- )
     {
         int mn;
         cin &gt;&gt;mn;
         for ( i =1; i &lt; 32000 ; i ++ )
             if ( a[i]&gt;=mn )
                 break;
         if ( a[i] ==mn )
             cout&lt;&lt;1&lt;&lt;endl;
         else
         {//mn-a[i-1]+1就是其在第i-1个串里的相对位置
             cout&lt;&lt;num[mn-a[i-1]+1]&lt;&lt;endl;
         }
     }
     return 0;
 }
[/code]