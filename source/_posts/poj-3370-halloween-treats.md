title: poj3370同样的是抽屉原理
toc: true
tags:
  - 抽屉原理
  - 数论
categories:
  - 算法竞赛
id: 975
date: 2012-03-10 01:15:52
---

题目大意是给出n和m及m个整数（n<m），要从m中找出任意个数使得其和是n的倍数，输出时就输出每一个数所在的编号

例如对于题目中的数据二，明显可以找出11，2，5，他的和是18，是3的倍数，而11，2，5对应于题目中的数据分别是2，3，4，故结果输出的是2，3，4

当然，除了2，3，4这一个解，还有1，2也是题目的解，但题目要求对于多解的情形只用输出一组解，如果无解，就输出“no sweets”

但根据抽屉原理，可以得出没有无解的情况，

详细证明请看我的关于poj2356的解题报告，这两题长得非常相像

http://www.cnblogs.com/ACShiryu/archive/2011/08/09/poj2356.html

刚开始时没注意到数据范围，TLE和WA分别一次，这题数据明显比2356强，中间有可能超int，故要用__int64，并且cin比scanf慢

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int a[100000] , mod[100000] ;
 int main()
 {
     int c , n ;
     while ( scanf(&quot;%d%d&quot;,&amp;c,&amp;n) , c || n )
     {
         int i , j ;
         for ( i = 0 ; i &lt; n ; i ++ )
             scanf(&quot;%d&quot;,&amp;a[i]) , mod[i] = -2 ;//将mod初始化为-2
         mod[0]=-1 ;//mod[0]为-1，就是假设存在a[-1]，且a[-1]是n的倍数，这样就可以把两种情况写在一起
         __int64 sum = 0 ;//直接用sum，省去了另开数组的空间
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             sum += a[i] ;
             if ( mod [ sum % c ] != -2 )
             {//如果在i之前有与sum对n同余的数，则可以输出答案，
                 for ( j = mod [ sum % c ] + 1 ; j &lt;= i ; j ++ )
                 {
                     cout&lt;&lt;j+1;
                     if ( i != j )
                         cout&lt;&lt;' ';
                 }
                 cout&lt;&lt;endl;
                 break;
             }
             mod [sum%c] = i ;//记录余数对应的是i
         }
     }
     return 0;
 }[/code]