title: USACO 2.3.5 Controlling Companies 解题报告
toc: true
tags:
  - 图论
categories:
  - 算法竞赛
id: 916
date: 2012-03-08 23:30:22
---

题目意思就是打印所有的符合公司A能管理B的情况。其中A和B满足下面三个条件中的至少一个，就可以说A能管理B

*   公司A = 公司B。
*   公司A拥有大于50%的公司B的股票。
*   公司A能管理K(K >= 1)个公司，记为C1, ..., CK，每个公司Ci拥有xi%的公司B的股票，并且x1+ .... + xK > 50%。

这题可以将i从1出发到100，找到没被i管理的公司j，求出sum=∑map[k][j] (其中，k是被i管理的公司)

如果sum>50,则i控制j。再继续寻找下一个j。如果一直没找到可被管理的公司，这再从下一个i开始查找

数据分析：数据量不大，最坏的情况是有100个公司，程序的时间复杂度为O（n^3），不会超时，但还要注意自己的能被自己所管理，也就是说当使用第三条规则时还要加上a管理a的情况，刚开始时没加上，提交一直WA；

[code lang="cpp"]
#include&lt;iostream&gt; 
 #include&lt;cstdlib&gt; 
 #include&lt;cstdio&gt; 
 #include&lt;cstring&gt; 
 #include&lt;algorithm&gt; 
 #include&lt;cmath&gt; 
 using namespace std; 
 int map [ 105 ] [ 105 ] = { 0 } ;     //初始时i拥有j的股份的多少
 int nmap [ 105 ] [ 105 ] = { 0 } ;    //通过传递时，i拥有j股份的多少
 bool con [ 105 ] [ 105 ] = { false } ; //当为true时表示i能管理j
 int main() 
 { 
     //因为USACO都是通过读取文件的形式来验证程序的
     freopen(&quot;concom.in&quot;,&quot;r&quot;,stdin);   
     freopen(&quot;concom.out&quot;,&quot;w&quot;,stdout); 
     int n ; 
     cin &gt;&gt; n ; 
     int i , j , k ; 
     for ( i = 0 ; i &lt; n ; i ++ ) 
     { 
         int a , b , c ; 
         cin &gt;&gt; a &gt;&gt; b &gt;&gt; c ;   //a拥有b的c%的股份
         map [ a ] [ b ] = c ; 
         if ( c &gt;= 50 )         //当股份超过50%时则说明a能管理b
             con [ a ] [ b ] = true ; 
     }

     for ( i = 1 ; i &lt;= 100 ; i ++ ) 
     { 
         con [ i ] [ i ] = true ; 
         bool tag = true ;//判断是否又有新公司能被i管理，当为false时
                           //说明已无新公司可被i管理，则从下一个i开始
         while ( tag ) 
         { 
             tag = false ; //初始时标记为无公司加入
             for ( j = 1 ; j &lt;= 100 ; j ++ ) 
             { 
                 if ( ! con [ i ] [ j ]) 
                 {      //如果i不能管理j,则看规则是否能符合第三条
                     int sum = 0 ; //定义i间接拥有j的股份
                     for ( k = 1 ; k &lt;= 100 ; k ++ ) 
                     { 
                         if  ( con [ i ] [ k ] ) 
           {//i能管理k,，则i间接拥有j股份值要加上k拥//j有的股份值
                             sum += map [ k ] [ j ] ; 
                         }

                     } 
                     if ( sum &gt; 50 ) 
                     { //如果间接拥有股份值超过50%，则i能管理j
                         tag = true ; //标记为true,有新公司被管理
                         con [ i ] [ j ] = true ; 
                     } 
                 } 
             } 
         } 
     } 
     for ( i = 1 ; i &lt;= 100 ; i ++ ) 
     { 
         for ( j = 1 ; j &lt;= 100 ; j ++ ) 
         { //输出i能管理j的情况，要排除i=j
             if ( con [ i ] [ j ] &amp;&amp; i != j ) 
                 cout &lt;&lt; i &lt;&lt; ' ' &lt;&lt; j &lt;&lt; endl ; 
         } 
     }
     return 0; 
 }
[/code]