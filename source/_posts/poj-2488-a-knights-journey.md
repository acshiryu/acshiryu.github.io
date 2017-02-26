title: "POJ2488 A Knight's Journey 解题报告"
toc: true
tags:
  - DFS
  - 搜索
categories:
  - 算法竞赛
id: 924
date: 2012-03-08 23:36:21
---

题目大意是给出一个规格小于8*8的棋盘，判断一个只能走“日”的骑士能否不重复的走遍整个棋盘，如果能，按字典序输出走的路径，否则输出“impossible”

这题是一道搜索题，可以用DFS直接解决。每次从左到右，从上到下进行搜索，并标记搜索过的地方；

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
using namespace std;
struct prog {
	char a ;
	int b ;
}tra;
struct proglu{
	char str[900];
}map;
bool hash[900];
bool found=false;
int p , q ;
int number=0;
void DFS(prog tmp , int n ,proglu map ,int k)
{
	if(found)
		return ;
	if(n==1)
	{
		int i;
		cout&lt;&lt;&quot;Scenario #&quot;&lt;&lt;number&lt;&lt;&quot;:&quot;&lt;&lt;endl;
		for(i=0;i&lt;k;i++)
		{

			cout&lt;&lt;map.str[i];
		}
		cout&lt;&lt;endl;
		found=true;
	}
	int t=(tmp.a-'A')*30+tmp.b;
	hash[t]=true;
	prog tmp2;
	tmp2=tmp;
	tmp2.a-=2;
	tmp2.b--;
	if(tmp2.a&gt;='A'&amp;&amp;tmp2.b&gt;=1&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a-=2;
	tmp2.b++;
	if(tmp2.a&gt;='A'&amp;&amp;tmp2.b&lt;=q&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a-=1;
	tmp2.b-=2;
	if(tmp2.a&gt;='A'&amp;&amp;tmp2.b&gt;=1&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a-=1;
	tmp2.b+=2;
	if(tmp2.a&gt;='A'&amp;&amp;tmp2.b&lt;=q&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=1;
	tmp2.b-=2;
	if(tmp2.a&lt;='A'+p-1&amp;&amp;tmp2.b&gt;=1&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=1;
	tmp2.b+=2;
	if(tmp2.a&lt;='A'+p-1&amp;&amp;tmp2.b&lt;=q&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=2;
	tmp2.b-=1;
	if(tmp2.a&lt;='A'+p-1&amp;&amp;tmp2.b&gt;=1&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=2;
	tmp2.b+=1;
	if(tmp2.a&lt;='A'+p-1&amp;&amp;tmp2.b&lt;=q&amp;&amp;hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}
}

int main()
{
	int k = 1 ;

	int t;
	cin&gt;&gt;t;
	while(t--)
	{
		number++;
		cin &gt;&gt; q &gt;&gt; p ;
		if(number!=1)
			cout&lt;&lt;endl;
		memset(hash,false,sizeof(hash)) ;
		tra.a='A';
		tra.b=1;
		memset(map.str,0,sizeof(map.str));
		map.str[0]='A';
		map.str[1]='1';
		found=false;
		DFS(tra,p*q,map,2); 
		if(!found)
		{
			cout&lt;&lt;&quot;Scenario #&quot;&lt;&lt;number&lt;&lt;&quot;:&quot;&lt;&lt;endl;

			cout&lt;&lt;&quot;impossible&quot;&lt;&lt;endl;
		}
	}
	return 0;
}
[/code]