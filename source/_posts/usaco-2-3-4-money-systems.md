title: USACO 2.3.4 Money Systems 解题报告
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 914
date: 2012-03-08 23:28:45
---

题目大意很简单，就是给出钱币系统，求能拼出V的情况总数

可以用DP求解，注意到 money [ j ] [ i ] += money [ j - k * sys [ i - 1 ] ] [ i - 1 ] ;

其中money [ j ] [ i ] 表示用前i种币拼出j的情况总数，明显题目要求的是money [ n ] [ v ]

[code lang="cpp"]
/* 
ID:shiryuw1 
PROG:money 
LANG:C++ 
*/ 
#include&lt;iostream&gt; 
#include&lt;cstdlib&gt; 
#include&lt;cstdio&gt; 
#include&lt;cstring&gt; 
#include&lt;algorithm&gt; 
#include&lt;cmath&gt; 
using namespace std; 
int sys [ 30 ] ; 
long long money [ 10005 ] [ 30 ] = { 0 } ; 
int main() 
{ 
    freopen(&quot;money.in&quot;,&quot;r&quot;,stdin); 
    freopen(&quot;money.out&quot;,&quot;w&quot;,stdout); 
    int v , n ; 
    cin &gt;&gt; v &gt;&gt; n ; 
    int i , j , k ; 
    for ( i = 0 ; i &lt; v ; i ++ ) 
    { 
        cin &gt;&gt; sys [ i ] ; 
    } 
    sort ( sys , sys + v );

    for ( i = 0 ; i &lt;= n ; i ++ ) 
    { 
        if ( i % sys [ 0 ] == 0 ) 
            money [ i ] [ 1 ] = 1; 
        else 
            money [ i ] [ 1 ] = 0 ; 
    } 
    for ( i = 2 ; i &lt;= v ; i ++ ) 
    { 
        for ( j = 0 ; j &lt;= n ; j ++ ) 
        { 
            for ( k = 0 ; j &gt;= k * sys [ i - 1 ] ; k ++ ) 
            { 
                money [ j ] [ i ] += money [ j - k * sys [ i - 1 ] ] [ i - 1 ] ; 
            } 
        } 
    }

    printf ( &quot;%lld\n&quot; , money [ n ] [ v ] ); 
    return 0; 
}[/code]