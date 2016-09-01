title: "POJ3185 The Water Bowls\t解题报告"
toc: true
tags:
  - 位运算
  - 枚举
  - 高斯消元
categories:
  - 算法竞赛
id: 1433
date: 2012-07-10 16:40:57
---

题目大意和POJ1222 类似，不过这题更简单，只用枚举第一个开关的状态就行了，题目保证有解，只需要简单的位运算即可，这题也可高斯消元

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

int a[25],b[25];
int main()
{
    while(~scanf(&quot;%d&quot;,&amp;a[0]))
    {
        b[0]=a[0];
        int i;
        for(i=1;i&lt;20;i++)
        {
            scanf(&quot;%d&quot;,&amp;a[i]);
            b[i]=a[i];
        }
        int ans=1&lt;&lt;20;
        for(i=0;i&lt;2;i++)
        {
            int cnt=0;
            memcpy(b,a,sizeof(b));
            if(i==1)
            {
                b[0]=!b[0];
                b[1]=!b[1];
                cnt++;
            }
            for(int j=1;j&lt;19;j++)
            {
                if(b[j-1]==1)
                {
                    cnt++;
                    b[j-1]=!b[j-1];
                    b[j]=!b[j];
                    b[j+1]=!b[j+1];
                }
            }
            if(b[19]^b[18]==0)
            {
                if(b[19]==1)
                    cnt++;
                if(ans&gt;cnt)
                    ans=cnt;
            }
        }
        printf(&quot;%d\n&quot;,ans);
    }
    return 0;
}
[/code]