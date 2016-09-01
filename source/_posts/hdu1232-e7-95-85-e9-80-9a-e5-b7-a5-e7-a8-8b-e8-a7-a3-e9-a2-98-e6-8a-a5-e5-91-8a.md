title: hdu1232 畅通工程 解题报告
toc: true
tags:
  - 并查集
  - 数据结构
categories:
  - 算法竞赛
id: 1028
date: 2012-03-15 21:05:03
---

题目地址：[http://acm.hdu.edu.cn/showproblem.php?pid=1232](http://acm.hdu.edu.cn/showproblem.php?pid=1232 "畅通工程")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;并查集，将连通的点归结在一起，然后再扫描，看有多少个团队，然后团队数-1，详细看代码
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
using namespace std;
int pre[1005 ];
bool tmp[1005];
int find(int k)
{
	return pre[k]==k?k:pre[k]=find(pre[k]);
}
void join(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb)
		pre[fa]=fb;
}
int main()
{
	int n,m;
	while(scanf(&quot;%d%d&quot;,&amp;n,&amp;m),n)
	{
		int i,j;
		for(i=0;i&lt;1005;i++)
			pre[i]=i;
		for(i=0;i&lt;m;i++)
		{
			int a,b;
			scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
			join(a,b);
		}
		memset(tmp,0,sizeof(tmp));
		int cnt=0;
		for(i=1;i&lt;=n;i++)
		{
			if(tmp[find(i)]==0)
			{
				cnt++;
				tmp[find(i)]=1;
			}
		}
		printf(&quot;%d\n&quot;,cnt-1);
	}
}
[/code]