title: poj1050经典DP的二维形式
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 1003
date: 2012-03-10 23:55:26
---

题目大意就是给出一个n×n的矩阵，要求在里面找一个子矩阵，使得子矩阵中的元素和是最大的，输出这个最大的元素和

解决这题首先要会求给n个数，问这n个数的最大子串和是多少？这一道题就是把上面的问题拓展到了二维，但解决方法类似

枚举所有的行组合，将这些行压缩成一个数列，进行上述操作就可以了

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
using namespace std;
int a[105][105];
int sum[105];
int dp[105];
int main()
{
    int n ;
    while ( cin &gt;&gt; n )
    {
        int i , j , k , t;
        for ( i = 0 ; i &lt; n ; i ++ )
            for ( j = 0 ; j &lt; n ; j ++ )
                cin &gt;&gt; a[i][j] ;
        int sumall = - (1 &lt;&lt; 30 );
        for ( i = 0 ; i &lt; n  ; i ++ )
        {
            int sumdp;    
            for ( t = i + 1 ; t &lt;= n ; t ++ )
            {
                for ( j = 0 ; j &lt; n ; j ++ )
                {
                    int sumi = 0 ;
                    for ( k = i ; k &lt; t ; k ++ )
                    {
                        sumi += a[k][j] ;
                    }
                     sum[j] = sumi ;
                    if ( j )
                        sumall = max ( sumall , sumdp = max ( sumdp + sum[j] , sum[j] ) ) ;
                    else
                       sumall = max ( sumall , sumdp = sum[j] ) ;
                }
            }
        }
        cout &lt;&lt; sumall &lt;&lt; endl ; 
    }
    return 0 ;
}
[/code]