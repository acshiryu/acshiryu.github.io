title: USACO3.1.5 Contact 解题报告
toc: true
tags:
  - STL
  - usaco
  - 字典树
categories:
  - 算法竞赛
id: 1397
date: 2012-05-10 20:52:28
---

USACO卡题有一段时间了，没想到今天连A三题，看来有进步了？？？？不过，马上要数据库考试了，美国奶牛3.2要暂停了

这题做好很简单，但是输入输出不好处理，输入我是通过
[code lang="cpp"]
while(~scanf(&quot;%s&quot;,s+strlen(s)));
[/code]
来处理的，但是在输出上wa了几次，主要是那个回车和空格的处理，还有输出六个的问题

这题可以用map来做，每次取出s中长度a~b的一段给map中，并计数+1,最后再排序，对排序的问题不怎么会用，我是再从考一个pair数组给解决的，C++的STL不是很熟，详看代码
[code lang="cpp"]
/*
ID:shiryuw1
PROG:contact
LANG:C++
*/
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;string&gt;
#include &lt;map&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

typedef map&lt;string , int&gt; msi;
typedef pair&lt;string ,int&gt; psi;
char s[200005];
string strget(char *t,int k)
{
	string str;
	for(int i=0;i&lt;k;i++)
		str+=t[i];
	return str;
}
psi cnt[5555];
int strsec(string s)
{
	unsigned int i,ans=0;
	for(i=0;i&lt;s.length();i++)
		ans=ans*2+s[i]-'0';
	return ans;
}
bool cmp(psi a,psi b)
{
	if(a.second==b.second)
	{
		if((a.first.length())==(b.first.length()))
			return strsec(a.first)&lt;strsec(b.first);
		return (a.first.length())&lt;(b.first.length());
	}
	return a.second&gt;b.second;
}
int main()
{
	freopen(&quot;contact.in&quot;,&quot;r&quot;,stdin);
	freopen(&quot;contact.out&quot;,&quot;w&quot;,stdout);
	int a,b,n,i,j;
	scanf(&quot;%d%d%d&quot;,&amp;a,&amp;b,&amp;n);
	msi ans;
	string tmp;
	while(~scanf(&quot;%s&quot;,s+strlen(s)));
	int len=strlen(s);
	for(i=0;i&lt;=len-a;i++)
	{
		tmp=strget(s+i,a);
		for(j=a;j&lt;=b&amp;&amp;i+j&lt;=len;j++)
		{
			if(j!=a)
				tmp+=s[i+j-1];
			if(!ans.count(tmp))
				ans[tmp]=0;
			//cout&lt;&lt;tmp&lt;&lt;endl;
			ans[tmp]++;
		}
	}
	msi::iterator iter;
	for(iter=ans.begin(),i=0;iter!=ans.end();iter++,i++)
	{
		cnt[i].first=(iter-&gt;first);
		cnt[i].second=(iter-&gt;second);
	}
	sort(cnt,cnt+(j=i),cmp);
	int num=0;
	int hang=0;
	for(i=0;i&lt;j;i++)
	{
		if(i&amp;&amp;cnt[i].second==cnt[i-1].second)
		{
			if(hang==5)
			{
				cout&lt;&lt;endl;
				hang=-1;
			}
			else
			{
				cout&lt;&lt;' ';
			}
			cout&lt;&lt;cnt[i].first;
			hang++;
		}
		else
		{
			if(num&gt;=n)
				break;
			if(i)
				puts(&quot;&quot;);
			cout&lt;&lt;cnt[i].second&lt;&lt;&quot;\n&quot;&lt;&lt;cnt[i].first;
			hang=0;
			num++;
		}
	}
	puts(&quot;&quot;);
    return 0;
}
[/code]