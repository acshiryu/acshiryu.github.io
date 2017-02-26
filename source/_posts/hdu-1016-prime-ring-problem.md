title: hdu1016 Prime Ring Problem解题报告
toc: true
tags:
  - DFS
  - 搜索
  - 素数
categories:
  - 算法竞赛
id: 1024
date: 2012-03-15 20:34:31
---

题目地址：[http://acm.hdu.edu.cn/showproblem.php?pid=1016](http://acm.hdu.edu.cn/showproblem.php?pid=1016 "Prime Ring Problem")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;直接DFS水过，没什么意思，对于DFS还不是很熟的可以参见我的另一篇文章([POJ1426 Find The Multiple 解题报告](/archives/939 "POJ1426 Find The Multiple 解题报告"))，代码注释很详细，这里略去
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cstdlib&gt;
#include&lt;algorithm&gt;
#include&lt;cstring&gt;
using namespace std;
bool num[25];
int a[25];
bool ispri[50];
void DFS(int k,int n)
{
	int i,j;
	if(k==n)
	{
		if(ispri[a[k-1]+1])
		{
			for(i=0;i&lt;n;i++)
			{
				if(i)
					printf(&quot; &quot;);
				printf(&quot;%d&quot;,a[i]);
			}
			printf(&quot;\n&quot;);
		}
		return ;
	}
	for(i=1;i&lt;=n;i++)
	{
		if(num[i])
			continue;
		if(ispri[a[k-1]+i])
		{
			a[k]=i;
			num[i]=1;
			DFS(k+1,n);
			num[i]=0;
		}
	}
}
int main()
{
	int n;
	int cnt=1;
	memset(ispri,1,sizeof(ispri));
	ispri[0]=ispri[1]=0;
	int i,j;
	for(i=2;i&lt;=8;i++)
	{
		if(ispri[i])
		{
			for(j=i*i;j&lt;50;j+=i)
				ispri[j]=0;
		}
	}
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		memset(num,0,sizeof(num));
		printf(&quot;Case %d:\n&quot;,cnt++);
		a[0]=1;
		num[1]=1;
		DFS(1,n);
		printf(&quot;\n&quot;);
	}
}
[/code]