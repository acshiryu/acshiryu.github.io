title: USACO 2.3.1 Longest Prefix 解题报告
toc: true
tags:
  - DP
  - 动态规划
  - 字典数
  - 数据结构
categories:
  - 算法竞赛
id: 906
date: 2012-03-08 23:20:40
---

题目大意：就是给出一个字符串，求最大前缀的长度,可以用DP+字典树求解
[code lang="cpp"]
/*
ID:shiryuw1
PROG:prefix
LANG:C++
*/
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
using namespace std;
const int MAX=5020;
char str[200005]={0};
struct progtrie{
	int a[26];
	bool hash;
}trie[MAX];
int tree=1;
int maxpre=-1;
int vis[200005]={0};

bool isin(char *ch)
{
	int i;
	int k=0;
	for(i=0;ch[i]!=0;i++)
	{
		k=trie[k].a[ch[i]-'A'];
		if(k==0)
		{
			return false;
		}
	}
	if(k==0||trie[k].hash==false)
		return false;
	return true;
}

int main()
{
	freopen(&quot;prefix.in&quot;,&quot;r&quot;,stdin);
	freopen(&quot;prefix.out&quot;,&quot;w&quot;,stdout);
	int i,ii;
	for(i=0;i&lt;MAX;i++)
	{
		for(ii=0;ii&lt;26;ii++)
		{
			trie[i].a[ii]=0;
		}
		trie[i].hash=false;
	}
	while(1)
	{
		char ch[20];
		cin&gt;&gt;ch;
		if(ch[0]=='.')
			break;
		int k=0;
		for(i=0;ch[i]!=0;i++)
		{
			if(trie[k].a[ch[i]-'A']==0)
			{
				trie[k].a[ch[i]-'A']=tree;
				tree++;
			}
			k=trie[k].a[ch[i]-'A'];
		}
		trie[k].hash=true;
	}
	getchar();
	char ch[100]={0};
	while(cin&gt;&gt;ch)
	{
		strcat(str,ch);
	}
	bool ans=true;
	int len=strlen(str);
	int maxlength=0;
	for(i=1;i&lt;=len;i++)
	{
		int length=0;
		int j;
		for(j=1;j&lt;=10;j++)
		{
			int x;
			if(i&gt;=j)
			{
				if(vis[i-j]!=(i-j))
					continue;
				ans=false;
				int y=0;
				for(x=i-j;x&lt;i;x++)
				{
					ch[y]=str[x];
					y++;
				}
				ch[y]=0;

				if(isin(ch))
				{
					if(vis[i-j]+y&gt;length)
					{
						length=vis[i-j]+y;
					}
				}
			}

		}
		vis[i]=length;
		if(length&gt;maxlength)
			maxlength=length;
		if(ans)
			break;
	}
	cout&lt;&lt;maxlength&lt;&lt;endl;
	return 0;
}
[/code]