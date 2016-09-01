title: hdu4300Clairewd’s message 多校第一场
toc: true
tags:
  - kmp
categories:
  - 算法竞赛
id: 1468
date: 2012-08-09 10:25:02
---

简单KMP，下面是官方题解

这道题问的就是将1个串如何变为stringA+stringB的形式，使得stringA是stringB经过映射得到相同的串。映射那步其实没有什么价值，假设str为原串s经过映射后得到的串，我们可以以str为模式串，以s为原串做一次扩展KMP，得到extend数组，extend[i]表示原串以第i开始与模式串的前缀的最长匹配。经过O(n)的枚举，我们可以得到,若extend[i]+i=len且i>=extend[i]时，表示stringB即为该点之前的串，stringA即为该点之前的str串，最后输出即可。

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

char s[30];
char q[30];
char inter[100010];
char cry[50010];
int p[100010];
int cnt[100010];
int main()
{
    int T;
    scanf(&quot;%d&quot;,&amp;T);
    while(T--)
    {
        int i,j;
        scanf(&quot;%s%s&quot;,s,inter);
        for(i=0;s[i];i++)
        {
            q[s[i]-'a']=i+'a';
        }

        zero(cry);
        int len=strlen(inter);
        if(len==1)
        {
            printf(&quot;%c%c\n&quot;,inter[0],q[inter[0]-'a']);
            continue;
        }
        for(i=(len-1)/2+1;inter[i];i++)
            cry[i-1-(len-1)/2]=s[inter[i]-'a'];

        p[0]=-1;
        j=-1;
        for(i=1;inter[i];i++)
        {
            while(j&gt;=0&amp;&amp;inter[j+1]!=inter[i])
                j=p[j];
            if(inter[j+1]==inter[i])
                j++;
            p[i]=j;
        }

        j=-1;
        int t;
        t=strlen(cry);
        //cout&lt;&lt;cry&lt;&lt;endl;
        for(i=0;cry[i];i++)
        {
            while(j&gt;=0&amp;&amp;inter[j+1]!=cry[i])
                j=p[j];
            if(inter[j+1]==cry[i])
            {
                j++;
            }
            cnt[i]=j;
            if(j==t)
                j=p[j];
        }

        for(i=0;i&lt;len-cnt[t-1]-1;i++)
            printf(&quot;%c&quot;,inter[i]);
        for(i=0;i&lt;len-cnt[t-1]-1;i++)
            printf(&quot;%c&quot;,q[inter[i]-'a']);
        printf(&quot;\n&quot;);
    }
    return 0;
}
[/code]