title: hdu4632 Palindrome subsequence 20103多校4-1001
toc: true
tags:
  - DP
categories:
  - 算法竞赛
id: 1951
date: 2013-08-03 16:10:53
---

dp题
[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;

const int maxn=1000+10;
const int mod=10007;
int dp[maxn][maxn];
char s[maxn];
int len;
int main()
{
	int T,cas=1;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		scanf(&quot;%s&quot;,s);
		len=strlen(s);
		int i,j,k;
		for(i=len-1;i&gt;=0;i--)
		{
			for(k=0;i+k&lt;len;k++)
			{
				j=i+k;
				if(k==0)
				{
					dp[i][j]=1;
				}
				else if(k==1)
				{
					dp[i][j]=2+(s[i]==s[j]);
				}
				else
				{
					dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+mod)%mod;		
					if(s[i]==s[j])
						dp[i][j]+=dp[i+1][j-1]+1;
				}
			}
		}
		printf(&quot;Case %d: %d\n&quot;,cas++,dp[0][len-1]%mod);
	}
    return 0;
}
[/code]