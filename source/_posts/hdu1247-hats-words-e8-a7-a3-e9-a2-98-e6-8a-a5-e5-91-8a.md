title: hdu1247 Hat’s Words 解题报告
toc: true
tags:
  - STL
  - 字典树
  - 数据结构
categories:
  - 算法竞赛
id: 1069
date: 2012-03-25 15:03:16
---

题目地址：[http://acm.hdu.edu.cn/showproblem.php?pid=1247](http://acm.hdu.edu.cn/showproblem.php?pid=1247 "Hat’s Words")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;字典树，但懒的写了，直接用stl里的map+string水过，关于stl，可参见我的博客园博客：[http://www.cnblogs.com/ACShiryu/category/310688.html](http://www.cnblogs.com/ACShiryu/category/310688.html "STL详解")
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;map&gt;
#include&lt;string&gt;
#include&lt;cstdio&gt;
using namespace std;
string s[50005];
int main()
{
	map&lt;string,bool&gt;ans;
	int n=0;
	while(cin&gt;&gt;s[n])
		ans[s[n++]]=true;
	for(int i=0;i&lt;n;i++)
	{
		bool found=false;
		for(int j=1;j&lt;s[i].size();j++)
		{
			string s1(s[i],0,j);
			string s2(s[i],j);
			if(ans.count(s1)&amp;&amp;ans.count(s2))
			{
				found=true;
				break;
			}
		}
		if(found)
			cout&lt;&lt;s[i]&lt;&lt;endl;
	}
	return 0;
}
[/code]