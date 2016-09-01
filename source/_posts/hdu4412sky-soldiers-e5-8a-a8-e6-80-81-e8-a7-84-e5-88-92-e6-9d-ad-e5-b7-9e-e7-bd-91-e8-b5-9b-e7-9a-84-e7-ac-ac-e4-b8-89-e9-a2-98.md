title: Hdu4412Sky Soldiers 动态规划 杭州网赛的第三题
toc: true
tags:
  - DP
  - 动态规划
  - 题解
categories:
  - 算法竞赛
id: 1633
date: 2012-09-25 20:18:42
---

题目大意是有k个伞兵落到地面上，已知每个人落点的概率，有m个物资站，落地后要去最近的站。问如何安排这些物资站，使得伞兵落地后行走的期望距离的和最小。（所有落点最多1000个）。

显然是个dp题，我们可以先预处理下，对每个落点点求出他的概率总和，代表伞兵落在这点的权。可以直到物资站一定悬在伞兵落下的那些点上，所以我们就可以用dp[i][j]表示前i个落地点中选择j个作为物资点，则很容易想到转移方程dp[i][j]=min{dp[k][j-1]+dis[k][i]}，其中dis[k][i]表示在[k,i]区间的落地点选则一个作为物资点所走距离最小值的期望(就是每点到物资点的距离乘该点概率的总和)。

现在关键就是求dis，其实我们注意到  假设对于[i,j]，假设选取k作为物资点，则有

[code lang="cpp"]dis[i][j]=(a[k]-a[i])*p[i]+...(a[k]-a[k])*p[k]+(a[k+1]-a[k])*p[k+1]+...+(a[j]-a[k])*p[j];[/code]

而若选择k+1作为物资点，则有

[code lang="cpp"]
dis[i][j]'=(a[k+1]-a[i])*p[i]+...(a[k+1]-a[k])*p[k]+(a[k+1]-a[k])*p[k+1]+...+(a[j]-a[k+1])*p[j];
[/code]
则相减并化简得
[code lang="cpp"]
dis[i][j]'-dis[i][j]=(a[k+1]-a[k])*(∑p[i...k]-∑p[k+1...j])=(a[k+1]-a[k])*(sum[i][k]-sum[k+1][j]);
[/code]
设tmp=dis[i][j]'-dis[i][j],sum可以很容易求出，这样很显然，当k增加时，tmp的值也在增加，所以，若选取k作为物资点，则要tmp>=0，否则我们可以选取k+1作为物资点，这样，可以对dis进行预处理，然后就可以得出答案

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;map&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

struct prog{
	double p;
	int k;
}pos[1005];
bool cmp(prog a,prog b)
{
	return a.k&lt;b.k;
}
double dis[1005][1005];
double sum[1005][1005];
double dp[1005][1005];
int main()
{
	int kx,m;
	while(scanf(&quot;%d%d&quot;,&amp;kx,&amp;m),kx||m)
	{
		int i,j,k;
		int pos_num=0;
		map&lt;int,int&gt;mp;

		for(i=0;i&lt;kx;i++)
		{
			int n;
			scanf(&quot;%d&quot;,&amp;n);
			//cout&lt;&lt;1&lt;&lt;endl;
			for(j=0;j&lt;n;j++)
			{
				int t;
				double p;
				scanf(&quot;%d%lf&quot;,&amp;t,&amp;p);
				if(mp.count(t)==0)
				{
					mp[t]=pos_num;
					pos[pos_num].p=p;
					pos[pos_num++].k=t;
				}
				else
				{
					pos[mp[t]].p+=p;
				}
			}
		}

		sort(pos,pos+pos_num,cmp);

		zero(sum);
		for(i=0;i&lt;pos_num;i++)
		{
			sum[i][i]=pos[i].p;
			for(j=i+1;j&lt;pos_num;j++)
			{
				sum[i][j]=sum[i][j-1]+pos[j].p;
			}
		}

		zero(dis);
		for(i=0;i&lt;pos_num;i++)
		{
			for(j=i+1;j&lt;pos_num;j++)
			{
				dis[i][j]=0.0;
				for(k=i+1;k&lt;=j;k++)
				{
					dis[i][j]+=(pos[k].k-pos[i].k)*pos[k].p;
				}

				double tmp=dis[i][j];
				for(k=i+1;k&lt;=j;k++)
				{
					tmp=(pos[k].k-pos[k-1].k)*(sum[i][k-1]-sum[k][j])+dis[i][j];
					if(tmp&lt;dis[i][j])
						dis[i][j]=tmp;
					else
						break;
				}
				//cout&lt;&lt;dis[i][j]&lt;&lt;endl;
			}
		}

		for(i=0;i&lt;pos_num;i++)
		{
			//dp[i][0]=0;
			dp[i][1]=dis[0][i];
			for(j=2;j&lt;=m;j++)
			{
				dp[i][j]=1000000000.0;
				for(k=0;k&lt;=i;k++)
				{
					dp[i][j]=min(dp[i][j],dp[k][j-1]+dis[k+1][i]);
				}
			}
		}

		printf(&quot;%.2lf\n&quot;,dp[pos_num-1][m]);
	}
    return 0;
}
[/code]