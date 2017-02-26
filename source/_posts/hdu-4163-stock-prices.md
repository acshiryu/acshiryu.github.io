title: HDU4163 Stock Prices 解题报告
toc: true
tags:
  - sort
  - STL
  - 排序
  - 稳定排序
  - 算法
  - 题解
categories:
  - 算法竞赛
id: 827
date: 2012-03-03 09:13:29
---

<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4163](http://acm.hdu.edu.cn/showproblem.php?pid=4163)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这题就是一个排序题，比较纠结。题目大意就是就是给出n个数，每个数对应着唯一的编号，就是他所处的序号，然后求出前k1小的元素对应的位置，升序输出，如果有相同的元素，选择和最小的，求出前k2大的元素对应的位置，升序输出，如果有相同的元素，选择和最大的。实际上就是一个稳定排序问题，可以用STL里的stable_sort，后续我会发一些关于STL模板库常用算法。详情看代码</font>
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cmath&gt;
#include&lt;algorithm&gt;
#include&lt;cstring&gt;
using namespace std;
struct prog{
	int num;
	int to;
}a[1000006],ans[1000006];
bool cmp(prog a,prog b)
{
	return a.num&lt;b.num;
}
bool cmpto(prog a,prog b)
{
	return a.to&lt;b.to;
}
int main()
{
	int cas=1;
	int n,s,t;
	while(scanf(&quot;%d%d%d&quot;,&amp;n,&amp;s,&amp;t),n)
	{
		int i,j;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%d&quot;,&amp;a[i].num);
			a[i].to=i;
		}
		stable_sort(a,a+n,cmp);//stable_sort 稳定排序
		printf(&quot;Case %d\n&quot;,cas++);
		memcpy(ans,a,s*sizeof(ans[0]));
		stable_sort(ans,ans+s,cmpto);
		for(i=0;i&lt;s;i++)
		{
			if(i)
				printf(&quot; &quot;);
			printf(&quot;%d&quot;,ans[i].to+1);
		}
		printf(&quot;\n&quot;);
		memcpy(ans,a+n-t,t*sizeof(ans[0]));
		stable_sort(ans,ans+t,cmpto);
		for(i=t-1;i&gt;=0;i--)
		{
			printf(&quot;%d&quot;,ans[i].to+1);
			if(i)
				printf(&quot; &quot;);
		}
		printf(&quot;\n&quot;);
	}
	return 0;
}
[/code]