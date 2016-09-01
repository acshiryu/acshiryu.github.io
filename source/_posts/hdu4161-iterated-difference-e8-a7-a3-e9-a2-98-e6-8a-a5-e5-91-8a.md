title: HDU4161 Iterated Difference 解题报告
toc: true
tags:
  - 暴力
  - 枚举
  - 比赛
  - 题解
categories:
  - 算法竞赛
id: 828
date: 2012-03-03 09:10:47
---

<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4161](http://acm.hdu.edu.cn/showproblem.php?pid=4161)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;题目大意就是给出一段序列，然后生成一段新的序列，使新序列的第i个元素是原序列第i+1个元素与第i个元素差的绝对值(最后一个是第一个与最后一个差的绝对值),问如此经过多少步，可以得到一个元素全部一样的序列，当然，当要的步骤大于1000时我们认为不可能得到这样的序列，输出not attained
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;解决办法很简单，就是枚举循环操作，对于每次生成的序列进行判断是否满足，详细看代码</font>
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cmath&gt;
using namespace std;
const int inf=1e3;
bool equal(int *a,int n)
{
	for(int i=1;i&lt;n;i++)
	{
		if(a[i]!=a[0])
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	int a[25];
	int i,j;
	int cas=1;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;a[i]);
		for(i=0;i&lt;inf;i++)
		{
			if(!equal(a,n))
			{
				int tmp=a[0];
				for(j=0;j&lt;n-1;j++)
				{
					a[j]=abs(a[j]-a[j+1]);
				}
				a[n-1]=abs(a[n-1]-tmp);
			}
			else
			{
				printf(&quot;Case %d: %d iterations\n&quot;,cas,i);
				break;
			}
		}
		if(i==inf)
			printf(&quot;Case %d: not attained\n&quot;,cas);
		cas++;
	}
	return 0;
}
[/code]