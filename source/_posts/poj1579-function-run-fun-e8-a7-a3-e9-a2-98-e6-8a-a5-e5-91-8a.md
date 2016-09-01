title: poj1579 Function Run Fun 解题报告
toc: true
tags:
  - 记忆化搜索
categories:
  - 算法竞赛
id: 1030
date: 2012-03-15 21:08:32
---

题目地址:[http://poj.org/problem?id=1579](http://poj.org/problem?id=1579 "Function Run Fun")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;记忆化搜索，因为递推的重复量很大，不能直接进行，必须记忆化，详细看代码
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
using namespace std;
int w[25][25][25];
int DFS(int a,int b,int c)
{
	if(a&lt;=0||b&lt;=0||c&lt;=0)
		return 1;
	if(a&gt;20||b&gt;20||c&gt;20)
		return DFS(20,20,20);
	int&amp; ans=w[a][b][c];
	if(ans!=-1)
		return ans;
	if(a&lt;b&amp;&amp;b&lt;c)
		ans=DFS(a, b, c-1) + DFS(a, b-1, c-1) - DFS(a, b-1, c);
	else
		ans=DFS(a-1, b, c) + DFS(a-1, b-1, c) + DFS(a-1, b, c-1) - DFS(a-1, b-1, c-1);
	return ans;
}
int main()
{
	int i,j,k;
	memset(w,-1,sizeof(w));
	while(cin&gt;&gt;i&gt;&gt;j&gt;&gt;k)
	{
		if(i==-1&amp;&amp;j==-1&amp;&amp;k==-1)
			break;
		printf(&quot;w(%d, %d, %d) = %d\n&quot;,i,j,k,DFS(i,j,k));
	}
}
[/code]