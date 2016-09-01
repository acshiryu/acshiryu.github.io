title: hdu4301Divide Chocolate 动态规划解题报告（多校1）
toc: true
tags:
  - 动态规划
categories:
  - 算法竞赛
id: 1470
date: 2012-08-09 10:31:54
---

下面是官方的解题报告

题意：

给定一个2*n的矩形，求把这个矩形分割为k部分的方法，且对称的切割方法视为不同，输出时模上100000007。

(1<=n<=1000,1<=k<=2*n)

解法：

看到这个题目，很容易想到DP。

状态表示 f[i][0][j]:前i行已经出现了j部分且第i行的两个格子属于同一部分的方法数

         f[i][1][j]:前i行已经出现了j部分且第i行的两个格子属于不同部分的方法数

初始条件 f[1][0][1]=f[1][1][2]=1

状态转移 f[i+1][0][j]=(f[i+1][0][j]+f[i][0][j]+f[i][1][j]*2)%mod;

         f[i+1][0][j+1]=(f[i+1][0][j+1]+f[i][0][j]+f[i][1][j])%mod;

         f[i+1][1][j]=(f[i+1][1][j]+f[i][1][j])%mod;

         f[i+1][1][j+1]=(f[i+1][1][j+1]+f[i][0][j]*2+f[i][1][j]*2)%mod;

         f[i+1][1][j+2]=(f[i+1][1][j+2]+f[i][0][j]+f[i][1][j])%mod;

共12种不同的状态转移（见下图）

 ![](http://fmn.rrimg.com/fmn059/20120719/1700/b_large_MrQQ_733a000059f71262.jpg)

我的代码
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

int dp[2][1005][2010];
const int mod = 100000007;

int main()
{
    int T;
    scanf(&quot;%d&quot;,&amp;T);
    while(T--)
    {
        int n,k,i,j;
        scanf(&quot;%d%d&quot;,&amp;n,&amp;k);
        zero(dp);
        for(i=1;i&lt;=n;i++)
            dp[0][i][1]=1,dp[1][i][1]=0;
        dp[1][1][2]=1;
        for(i=2;i&lt;=n;i++)
        {
            for(j=2;j&lt;=2*i&amp;&amp;j&lt;=k;j++)
            {
                dp[0][i][j]=( dp[0][i-1][j-1] + dp[0][i-1][j] + dp[1][i-1][j-1] + dp[1][i-1][j]*2 ) % mod;
                dp[1][i][j]=( dp[0][i-1][j-1]*2 +dp[0][i-1][j-2]+ dp[1][i-1][j-1]*2 + dp[1][i-1][j] + dp[1][i-1][j-2]) % mod;
            }
        }
        printf(&quot;%d\n&quot;,(dp[0][n][k]+dp[1][n][k])%mod);
    }
    return 0;
}
[/code]