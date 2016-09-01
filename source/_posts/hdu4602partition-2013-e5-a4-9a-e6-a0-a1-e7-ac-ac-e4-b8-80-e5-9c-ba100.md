title: HDU4602Partition 2013多校第一场100
toc: true
tags:
  - 数学
  - 数论
  - 递推
categories:
  - 算法竞赛
id: 1919
date: 2013-07-24 13:48:28
---

可以知道对于任何数n都可以写成
$$n=x+[y+z+...]$$,则对于任意的一个$$x(0\leq x<n)$$，后面的式子有$${2}^{n-x-1}$$种写法

假设对于给定的k，题目要求的就是$$f(n)$$

则对于x有两种可能
若$$x=k$$，则这$${2}^{n-x-1}$$个式子中，因为第一项就是k，所以每一个式子至少含有1个$$k$$，现在就看其余项中含有多少$$k$$，而其余项就是求$$f(n-x)$$
若$$x\neq k$$相等，则第一项不含有$$k$$，就看其余项中含有含有多少$$k$$，依旧是求$$f(n-x)$$
注意到，当$$k>n$$是，$$f(n)=0$$

则可以得到
$$f(n)=\sum_{i=k}^{n-1}{f(i)}+{2}^{n-k-1}$$

于是可以求出通项公式
$$f(n)=(n-k+3)*{2}^{n-k-2}(n>k)$$

> 官方解题报告
> 我们特判出$$n\leq k$$的情况。
> 对于$$1\leq k<n$$,我们可以等效为$$n$$个点排成一列，并取出其中的连续k个点。下面分两种情况考虑：
> 第一种情况，被选出的不包含断电，那么有$$n-k-1$$种情况完成上述操作，剩下未被圈的点之间还有$$n-k-2$$个位置，可以在每个位置断开，所以共$${(n-k-1)}*{2}^{n-k-2}$$种方法。
> 第二种情况，即被选出的包含端点，那么有两种情况，并且剩余共$$n-k-1$$个位置，所以共$$2*{2}^{n-k-1}$$种方法。
> 总计$$2*{2}^{n-k-1}+{(n-k-1)}*{2}^{n-k-2}=(n-k-3)*{2}^{n-k-1}$$。

<!--more-->
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

const int mod=1e9+7;
__int64 mul(__int64 n,__int64 k)
{
	__int64 ans=1;
	while(k&gt;=1)
	{
		if(k&amp;1)
			ans=ans*n%mod;
		k=k/2;
		n=n*n%mod;
	}
	return ans;
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		__int64 n,k;
		scanf(&quot;%I64d%I64d&quot;,&amp;n,&amp;k);
		__int64 m=n-k;

		if(m&lt;0)
		{
			printf(&quot;0\n&quot;);
			continue;
		}
		if(m==0||m==1)
		{
			printf(&quot;%I64d\n&quot;,m+1);
			continue;
		}

		printf(&quot;%I64d\n&quot;,mul(2,m-2)*(m+3)%mod);
	}
    return 0;
}
[/code]

标程
[code lang="cpp"]
#include &quot;iostream&quot;
#include &quot;cstring&quot;
#include &quot;cstdio&quot;
using namespace std;
typedef long long LOL;
const LOL MOD = 1000000007ll;
LOL solve(LOL n,LOL k)
{
    if(n&lt;k) return 0;
    if(n==k) return 1;
    LOL ans=n-k+3;
    LOL tmp=2;
    k=n-k-2;
    if(k==-1){
        return ans/2;
    }
    while(k){
        if(k%2){
            ans=(ans*tmp)%MOD;
        }
        tmp=(tmp*tmp)%MOD;
        k/=2;
    }
    return ans;
}
int main(void)
{
    LOL n,k;
    int T;
    scanf(&quot;%d&quot;,&amp;T);
    while(T--){
        cin&gt;&gt;n&gt;&gt;k;
        cout&lt;&lt;solve(n,k)&lt;&lt;endl;
    }
    return 0;
}

[/code]