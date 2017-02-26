title: HDOJ 1754 I Hate It 解题报告
toc: true
tags:
  - 数据结构
  - 线段树
categories:
  - 算法竞赛
id: 912
date: 2012-03-08 23:27:29
---

这题很无奈，第一次做线段树，RE了好多次，代码也修改了好多次，终于AC了

刚开始时数组开小了，所以导致RE

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
using namespace std;
int num [ 2000200 ] ;
struct prig{
    int x ;        //起点
    int y ;        //终点
    int max ;    //从x到y的最大值（包括x和y）
} sum [ 4000400 ] ;
int build ( int k ,int x , int y )
{
    sum [ k ] . x = x ;
    sum [ k ] . y = y ;
    if( y == x )
    {
        sum [ k ] . max = num [ x-1 ] ;
        return num [ x-1 ] ;
    }

    int mid = ( x + y  ) / 2 ;
    int maxnum = max ( build ( 2 * k , x , mid  ) , build ( 2 * k + 1 ,mid + 1 , y ) ) ;
    sum [ k ] . max = maxnum ;
    return maxnum ;
}

int found ( int k ,int x , int y )
{
    if ( sum [ k ] . y &lt; x )
        return 0 ;
    if ( sum [ k ] . x &gt; y )
        return 0 ;
    if ( sum [ k ] . x &gt;= x &amp;&amp; sum [ k ] . y &lt;= y )
        return  sum [ k ] . max ;
    return max ( found ( 2 * k , x , y ) , found ( 2 * k + 1 , x , y ) );
}

int updata ( int k ,int x , int y )
{
    if( sum [ k ] . x &lt;= x &amp;&amp; sum [ k ] . y &gt;= x )
    {
        if ( sum [ k ] . x == x &amp;&amp; sum [ k ] . y == x )
        {
            sum [ k ] . max = y;
            return y ;
        }
        sum [ k ] . max = max ( updata ( k * 2 , x , y ) , updata ( k * 2 + 1 , x ,y ) ) ;
    }
    return sum [ k ] . max ;
}

int main()
{
    int n , m;
    while ( cin &gt;&gt; n &gt;&gt; m )
    {
        int i ;
        for ( i = 0 ; i &lt; n ; i ++ )
        {
            scanf ( &quot;%d&quot; , &amp; num[i] );
        }

        build ( 1 , 1 , n );

        while ( m -- )
        {
            char op[10];
            int x , y ;
            scanf ( &quot;%s%d%d&quot; , op , &amp; x , &amp; y ) ;

            if ( strcmp ( op , &quot;Q&quot; ) == 0 )
            {
                printf ( &quot;%d\n&quot; , found ( 1 , x , y ) ) ;
            }
            else
            {
                num [ x - 1 ] = y ;
                updata ( 1 , x , y ) ;
            }
        }
    }
    return 0;
}[/code]