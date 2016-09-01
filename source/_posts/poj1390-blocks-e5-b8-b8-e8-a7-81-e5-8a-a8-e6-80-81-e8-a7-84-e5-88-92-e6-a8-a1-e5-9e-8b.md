title: POJ1390 Blocks 常见动态规划模型
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 1359
date: 2012-05-08 22:11:06
---

黑书真不是盖的！lrj黑书的常见模型分析的第一道例题（P123）
题目大意黑书上都有，但分析初看时没看懂,等到wa了几次才明白，因为合并的区间段有可能来自不同的区域，所以这个若干段不好处理。
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

struct prog{
	int k;
	int num;
	int p;
}ans[205];
int dp[205][205][205];
int main()
{
	int T,TT=1;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int N;
		scanf(&quot;%d&quot;,&amp;N);
		int i,j,k;
		i=-1,k=-1;
		zero(ans);
		while(N--)
		{
			int a;
			scanf(&quot;%d&quot;,&amp;a);
			if(a!=k)
				i++;
			ans[i].k=a;
			ans[i].num++;
			k=a;
		}
		int n=i+1;
		for(i=0;i&lt;n;i++)
		{
			for(j=i-1;j&gt;=0;j--)
			{
				if(ans[i].k==ans[j].k)
					break;
			}
			ans[i].p=j;
		}
		zero(dp);
		for(i=0;i&lt;n;i++)
			for(j=0;j&lt;200;j++)
				dp[i][i][j]=(ans[i].num+j)*(ans[i].num+j);
		for(j=1;j&lt;n;j++)
		{
			for(i=0;i+j&lt;n;i++)
			{
				for(k=0;k&lt;200;k++)
				{
					dp[i][i+j][k]=dp[i][i+j-1][0]+(ans[i+j].num+k)*(ans[i+j].num+k);
					int p=ans[i+j].p;
					while(p&gt;=i&amp;&amp;ans[i+j].num+k&lt;200)
					{
						dp[i][i+j][k]=max(dp[i][i+j][k],dp[i][p][ans[i+j].num+k]+dp[p+1][i+j-1][0]);
						p=ans[p].p;
					}
				}
			}
		}
		printf(&quot;Case %d: %d\n&quot;,TT++,dp[0][n-1][0]);
	}
	return 0;
}
[/code]
附上两组测试数据，刚开始就是wa在这两组上的
输入：
`
2
21
1 1 1 2 1 1 1 3 1 1 1 1 1 3 3 3 3 3 3 3 3
8
1 2 2 3 1 3 2 1`
输出：
`
187
18
`