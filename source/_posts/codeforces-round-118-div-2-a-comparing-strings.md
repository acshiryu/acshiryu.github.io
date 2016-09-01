title: "Codeforces Round #118 (Div. 2) :A. Comparing Strings"
toc: true
tags:
  - cf
categories:
  - 算法竞赛
id: 1345
date: 2012-05-05 21:37:57
---

晕死，纯水题，竟然在最后给挂了！
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

char s1[100005];
char s2[100005];
int main()
{
	while(~scanf(&quot;%s%s&quot;,s1,s2))
	{
		int wrong=0;
		found=false;
		if(strlen(s1)!=strlen(s2))
		{
			cout&lt;&lt;&quot;NO&quot;&lt;&lt;endl;
			continue;
		}
		zero(hash);
		char c1,c2;
		for(int i=0;s1[i];i++)
		{
			if(s1[i]!=s2[i])
			{
				wrong++;
				if(wrong==1)
				{
					c1=s1[i];
					c2=s2[i];
				}
				if(wrong==2)
				{
					if(s1[i]!=c2||s2[i]!=c1)
						wrong++;
				}
				if(wrong&gt;2)
					break;
			}
		}
		if(wrong==2)
			cout&lt;&lt;&quot;YES&quot;&lt;&lt;endl;
		else
			cout&lt;&lt;&quot;NO&quot;&lt;&lt;endl;
	}
    return 0;
}

[/code]