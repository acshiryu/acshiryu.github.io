title: "POJ1681 Painter's Problem 解题报告"
toc: true
tags:
  - 位运算
  - 枚举
  - 高斯消元
categories:
  - 算法竞赛
id: 1429
date: 2012-07-10 16:32:11
---

题目意思很简单，很poj 1222其实是一模一样的，只是要会判断是否存在无解的情况，思路可参考[POJ1222EXTENDED LIGHTS OUT 解题报告](http://acshiryu.com/archives/1427 "POJ1222EXTENDED LIGHTS OUT 解题报告")。可以位运算枚举，也可以高斯消元

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

char a[20][20];
int ans[20];
int mat[20];
int n;

int OneCount(unsigned int x)
{//计算二进制中的1的个数  参考Matrix67
    x=(x&amp;0x55555555)+((x&gt;&gt;1)&amp;0x55555555); 
    x=(x&amp;0x33333333)+((x&gt;&gt;2)&amp;0x33333333);
    x=(x&amp;0x0f0f0f0f)+((x&gt;&gt;4)&amp;0x0f0f0f0f); 
    x=(x&amp;0x00ff00ff)+((x&gt;&gt;8)&amp;0x00ff00ff); 
    x=(x&amp;0x0000ffff)+((x&gt;&gt;16)&amp;0x0000ffff);
    return x;
}
int test(int k,int t)
{
    k=k^t;
    k=k^(t&lt;&lt;1);
    k=k^(t&gt;&gt;1);
    k=k&amp;((1&lt;&lt;n)-1);
    return k;
}
int main()
{
    int T,cas=1;
    scanf(&quot;%d&quot;,&amp;T);
    while(T--)
    {
        int i,j,k;
        scanf(&quot;%d&quot;,&amp;n);
        for(i=0;i&lt;n;i++)
        {
            k=0;
            scanf(&quot;%s&quot;,a[i]);
            for(j=0;j&lt;n;j++)
            {
                a[i][j]=(a[i][j]=='y'?0:1);
                k=k*2+a[i][j];
            }
            mat[i]=k;
        }

        int bin=(1&lt;&lt;n)-1;

        int up;
        for(i=0;i&lt;=bin;i++)
        {
            ans[0]=i;
            k=mat[0];
            for(j=1;j&lt;=n;j++)
            {
                up=test(k,ans[j-1]);
                k=mat[j]^ans[j-1];
                ans[j]=up;
            }
            if(up==0)
                break;
        }

        if(i==bin+1)
        {
            printf(&quot;inf\n&quot;);
            continue;
        }
        int cnt=0;
        for(i=0;i&lt;n;i++)
        {
            cnt+=OneCount(ans[i]);
        }
        printf(&quot;%d\n&quot;,cnt);
    }

    return 0;
}

[/code]