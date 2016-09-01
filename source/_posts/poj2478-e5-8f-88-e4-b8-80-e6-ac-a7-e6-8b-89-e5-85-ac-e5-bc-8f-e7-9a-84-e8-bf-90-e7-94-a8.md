title: poj2478 又一欧拉公式的运用
toc: true
tags:
  - 数学
  - 数论
  - 欧拉公式
categories:
  - 算法竞赛
id: 985
date: 2012-03-10 01:20:29
---

题目大意就是求Fi集合中元素的个数，其中Fi集合的元素满足下列条件

形如a/b，且0<a<b<=i, gcd(a,b)=1 

很明显，这题就是欧拉公式的运用，关于欧拉公式可查看下这篇文章

http://www.cnblogs.com/ACShiryu/archive/2011/08/04/poj2407.html

对于这题，可以先求出以每一个小于m的数为分母的数的个数，即也是与该数互素的数的个数，也就是求的phi[i]；

然后再每一个phi都加起来

题目就是比较简单的欧拉运用，1A

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
usingnamespace std;
int phi[1000005];
int main()
{
    int i , j ;
    memset ( phi , 0 ,sizeof ( phi ) ) ;
    for ( i =2 ; i &lt;=1000000 ; i ++ )
    {//筛选求phi
if ( ! phi [i] )
        {
            for ( j = i ; j &lt;=1000000 ; j += i )
            {
                if ( ! phi [j] )
                    phi [j ] = j ;
                phi [j] = phi [j] / i * ( i -1 ) ;
            }
        }
    }
    int n ;
    while ( cin &gt;&gt; n  , n )
    {
        __int64 sum =0 ;
        for ( i =2 ; i &lt;= n ; i ++ )
            sum += phi [i] ;
        cout&lt;&lt;sum&lt;&lt;endl;
    }
    return0;
}[/code]