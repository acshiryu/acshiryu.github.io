title: poj1191棋盘分割(动态规划)
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 1338
date: 2012-05-05 15:26:12
---

黑书上面动态规划篇的第二道例题，题目大意很简单，可以记忆化搜索或dp做。最近在训练dp，直接dp做了，但记忆化搜索更简单。黑书上面的动态规划转移方程也写得很简单，用五层for循环嵌套。我的方程和他的略有不同，但大体意思是一样的！
`dp[k x1 y1 x2 y2]=min{
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dp[k-1 x1 y1 a y2]+dp[0 a+1 y1 x2 y2] , dp[k-1 a+1 y1 x2 y2]+dp[0 x1 y1 a y2] ,  （x1≤a﹤x2）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dp[k-1 x1 y1 x2 a]+dp[0 x1 a+1 x2 y2] , dp[k-1 x1 a+1 x2 y2]+dp[0 x1 y1 x2 a] ,  （y1≤a﹤y2）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;};`
然后就是5个嵌套的for循环，这题还有一个问题，不知道为什么，我之前用int和__int64都wa了，改成long double才ac了，难道卡在精度上？
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

int a[10][10];
int sum[10][10];
long double dp[20][10][10][10][10];
long double count(int x,int y,int m,int n)
{
	long double ans= __int64(sum[m][n]-sum[m][y]-sum[x][n]+sum[x][y]);
	return ans*ans;
}
int main()
{
	int n;
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		int i,j,k;
		zero(sum);
		int num=0;
		for(i=1;i&lt;=8;i++)
		{
			for(j=1;j&lt;=8;j++)
			{
				scanf(&quot;%d&quot;,&amp;a[i][j]);
				sum[i][j]=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1]+a[i][j];
				num+=a[i][j];
			}
		}
		int x,y;
		for(i=1;i&lt;=8;i++)
			for(j=1;j&lt;=8;j++)
				for(x=i;x&lt;=8;x++)
					for(y=j;y&lt;=8;y++)
						dp[0][i][j][x][y]=count(i-1,j-1,x,y);	
		for(k=1;k&lt;n;k++)
		{
			for(i=0;i&lt;=8;i++)
			{
				for(j=0;j&lt;=8;j++)
				{
					for(x=1;x+i&lt;=8;x++)
					{
						for(y=1;y+j&lt;=8;y++)
						{

							int t;
							dp[k][x][y][x+i][y+j]=long double((1)&lt;&lt;30);
							for(t=x;t&lt;x+i;t++)
							{
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][t+1][y][x+i][y+j]+dp[0][x][y][t][y+j]);
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][x][y][t][y+j]+dp[0][t+1][y][x+i][y+j]);
							}
							for(t=y;t&lt;y+j;t++)
							{
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][x][y][x+i][t]+dp[0][x][t+1][x+i][y+j]);
								dp[k][x][y][x+i][y+j]=min(dp[k][x][y][x+i][y+j],dp[k-1][x][t+1][x+i][y+j]+dp[0][x][y][x+i][t]);
							}
						}
					}
				}
			}
		}
		long double ans=1.0*dp[n-1][1][1][8][8]/n-long double(1.0*num/n)*long double(1.0*num/n);
		printf(&quot;%.3lf\n&quot;,sqrt(ans));
	}
    return 0;
}
[/code]