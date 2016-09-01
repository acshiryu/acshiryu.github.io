title: "poj2479与poj2593,同一道DP题"
toc: true
tags:
  - DP
  - 动态规划
  - 连续子串
categories:
  - 算法竞赛
id: 1005
date: 2012-03-10 23:56:37
---

这两道题的题目的题目大意如上，对于输入的n个数，求出最大的S,这是一个简单的DP题，开两个数组，DP[i][0],DP[i][1];,其中DP[i][0]表示的是从0～i中连续子串的最大和,DP[i][1]表示i～n-1中连续子串的最大和,则题目就变成求max{DP[i][0]+DP[i+1][1]}

参考代码：
poj2479
[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int a[50005];
 int dp[50005][2];
 int i ;
 int main()
 {
     int t ;
     scanf(&quot;%d&quot;,&amp;t);
     while ( t -- )
     {
         int n ;
         int sum=0;
         scanf(&quot;%d&quot;,&amp;n);
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             scanf (&quot;%d&quot;, &amp;a[i]) ;
             if (  i )
             {
                 sum = max(sum+a[i],a[i]);
                 dp[i][0]=max(sum,dp[i-1][0]);
             }
             else
                 dp[i][0]=sum=a[i];
         }
         for ( i = n -1 ; i&gt;=0 ; i -- )
         {
             if ( i != ( n - 1 ) )
             {
                 sum = max(sum + a[i] , a[i]);
                 dp[i][1]=max(sum,dp[i+1][1]);
             }
             else
                 dp[i][1]=sum=a[i];
         }
         sum = -(1&lt;&lt;30) ;
         for ( i = 0 ; i &lt; n - 1 ; i ++ )
             sum = max ( sum , dp[i][0]+dp[i+1][1] );
         printf(&quot;%d\n&quot;,sum);
     }
     return 0;
 }[/code]
　　poj2593
[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int a[100005];
 int dp[100005][2];
 int i ;
 int main()
 {
     int n ;
     while ( scanf(&quot;%d&quot;,&amp;n) , n )
     {

         int sum=0;
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             scanf (&quot;%d&quot;, &amp;a[i]) ;
             if (  i )
             {
                 sum = max(sum+a[i],a[i]);
                 dp[i][0]=max(sum,dp[i-1][0]);
             }
             else
                 dp[i][0]=sum=a[i];
         }
         for ( i = n -1 ; i&gt;=0 ; i -- )
         {
             if ( i != ( n - 1 ) )
             {
                 sum = max(sum + a[i] , a[i]);
                 dp[i][1]=max(sum,dp[i+1][1]);
             }
             else
                 dp[i][1]=sum=a[i];
         }
         sum = -(1&lt;&lt;30) ;
         for ( i = 0 ; i &lt; n - 1 ; i ++ )
             sum = max ( sum , dp[i][0]+dp[i+1][1] );
         printf(&quot;%d\n&quot;,sum);
     }
     return 0;
 }[/code]