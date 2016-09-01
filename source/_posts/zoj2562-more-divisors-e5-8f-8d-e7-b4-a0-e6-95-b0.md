title: ZOJ2562 More Divisors 反素数
toc: true
tags:
  - 反素数
  - 素数
categories:
  - 算法竞赛
id: 1461
date: 2012-07-22 10:52:06
---

题目大意就是求N之内的最大反素数（一个正整数N满足在1..N 中,N有最多的约数，则它是一个反素数）；

根据反素数定义，可以得出反素数的两个性质

故可以根据这两个性质通过搜索可以很容易的找到反素数

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

typedef long long ll;
int pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
struct prog{
    ll yz;
    ll num;
}ans;
ll n;
void DFS(prog tmp,int i,int k)
{
    if(ans.yz&lt;tmp.yz)
        ans=tmp;
    if(ans.yz==tmp.yz&amp;&amp;ans.num&gt;tmp.num)
        ans=tmp;
    if(k==0||i==12)
        return ;
    ll j;
    int t=0;
    for(j=1;j*tmp.num&lt;=n&amp;&amp;t&lt;=k;t++,j*=pri[i+1])
    {
        prog tx;
        tx.num=j*tmp.num;
        tx.yz=tmp.yz*(1+t);
        DFS(tx,i+1,t);
    }
}
int main()
{
    while(cin&gt;&gt;n)
    {
        ans.num=1;
        ans.yz=1;
        int k=0;
        for(ll i=1;i&lt;=n;i*=2,k++)
        {
            //cout&lt;&lt;i&lt;&lt;endl;
            //system(&quot;pause&quot;);
            prog tmp;
            tmp.num=i;
            tmp.yz=k+1;
            DFS(tmp,0,k);
        }
        cout&lt;&lt;ans.num&lt;&lt;endl;
    }
    return 0;
}
[/code]