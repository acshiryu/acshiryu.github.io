title: POJ1222EXTENDED LIGHTS OUT 解题报告
toc: true
tags:
  - 位运算
  - 枚举
  - 高斯消元
categories:
  - 算法竞赛
id: 1427
date: 2012-07-10 16:27:36
---

题目大意是给你一个5*6的矩阵，矩阵里每一个单元都有一个灯和一个开关，如果按下此开关，那么开关所在位置的那个灯和开关前后左右的灯的状态都会改变(即由亮到不亮或由不亮到亮)。给你一个初始的灯的状态，问怎样控制每一个开关使得所有的灯最后全部熄灭，保证解唯一

刚开始看时，感觉像搜索，但状态太多，有2^30，必然超时。但可以发现，每一开关的影响是受上下左右影响的，也就是说，如果我第一行的开关状态定下来的话，那么第二行的开关状态也就定下来了，以此类推到最高行，如果最后最高行和目标状态一样，那么就发现答案。解决开关中间要涉及到一些位运算，详细参考代码！这题也可以用高斯消元做。

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

int a[10][10];
int ans[10];
int mat[10];
int test(int k,int t)
{
    k=k^t;
    k=k^(t&lt;&lt;1);
    k=k^(t&gt;&gt;1);
    k=k&amp;((1&lt;&lt;6)-1);
    return k;
}
int main()
{
    int T,cas=1;
    scanf(&quot;%d&quot;,&amp;T);
    while(T--)
    {
        int i,j,k;
        for(i=0;i&lt;5;i++)
        {
            k=0;
            for(j=0;j&lt;6;j++)
            {
                scanf(&quot;%d&quot;,&amp;a[i][j]);
                k=k*2+a[i][j];
            }
            mat[i]=k;
        }

        int bin=(1&lt;&lt;6)-1;

        int up;
        for(i=0;i&lt;=bin;i++)
        {
            ans[0]=i;
            k=mat[0];
            for(j=1;j&lt;=5;j++)
            {
                up=test(k,ans[j-1]);
                k=mat[j]^ans[j-1];
                ans[j]=up;
            }
            if(up==0)
                break;
        }

        printf(&quot;PUZZLE #%d\n&quot;,cas++);
        for(i=0;i&lt;5;i++)
        {
            for(j=5;j&gt;=0;j--)
            {
                printf(&quot;%d&quot;,bool(ans[i]&amp;(1&lt;&lt;j)));
                if(j!=0)
                    printf(&quot; &quot;);
            }
            printf(&quot;\n&quot;);
        }
    }

    return 0;
}
[/code]