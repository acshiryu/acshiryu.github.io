title: "Codeforces Round #118 (Div. 2) :D. Mushroom Scientists"
toc: true
tags:
  - cf
  - 数论
categories:
  - 算法竞赛
id: 1351
date: 2012-05-05 21:57:26
---

题目就是给出a b c和S，求出一组非负数x y z 使得x+y+z=S,并且要求x^a*y^b*z^c最大
有公式，可以直接套用
但要注意a=b=c=0的情况，要特殊处理，否则当x=s*a/(a+b+c) y=s*b/(a+b+c) z=s*c/(a+b+c)时x^a*y^b*z^c最大
可以证明，此处证明略，有兴趣的可以参考[这篇文章](/go.php?url=http://www.science-mathematics.com/Mathematics/201110/16848.htm "Multi-Variable Optimization (Calc III) help!")
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

int main()
{
	int n,a,b,c;
	while(cin&gt;&gt;n&gt;&gt;a&gt;&gt;b&gt;&gt;c)
	{
		int s=a+b+c;
		double ans=(1.0*n/s);
		if(a==0&amp;&amp;b==0&amp;&amp;c==0)
			printf(&quot;%.1lf %.1lf %.1lf\n&quot;,0.0,0.0,0.0);
		else
		        printf(&quot;%.16f %.16f %.16f\n&quot;,ans*a,ans*b,ans*c);

	}
    return 0;
}
[/code]