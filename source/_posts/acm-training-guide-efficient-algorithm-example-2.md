title: 《算法竞赛入门经典训练指南》高效算法设计举例2
toc: true
tags:
  - 中途想遇法
  - 动态规划
categories:
  - 学习资料
id: 1964
date: 2013-08-09 15:27:31
---

# 高效算法设计举例(2)

#### 例题21 子序列（Subsequence, SEERC 2006, [LA 2678](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=679 "2678 - Subsequence")）

简单题

[code lang="cpp"]
#include&lt;cstdio&gt;
#include&lt;iostream&gt;
using namespace std;
int a[100005];
const int inf=200000;
int main()
{
	int n,s;
	while(~scanf(&quot;%d%d&quot;,&amp;n,&amp;s))
	{
		int i,j;
		int sum=0;
		int len=inf;
		int k=-1;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%d&quot;,&amp;a[i]);
			sum+=a[i];
			while(sum&gt;=s)
			{
				len=min(len,i-k);
				sum-=a[++k];
			}
			if(sum&lt;0)
			{
				len=1;
				k=i;
				sum=0;
			}
		}
		if(len==inf)
			printf(&quot;0\n&quot;);
		else
			printf(&quot;%d\n&quot;,len);
	}
}
[/code]
<!--more-->

#### 例题22 最大子矩阵（City Game, SEERC 2004, [LA 3029](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1030 "3029 - City Game")）

DP46题之一，算是DP系列的入门题

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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

char mp[1005][1005];
int sd[1005][1005];
int dp[1005];
int main()
{
	int T;
	int m,n;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		zero(dp);
		zero(mp);
		zero(sd);
		scanf(&quot;%d%d&quot;,&amp;n,&amp;m);
		int i,j,k;
		for(i=0;i&lt;n;i++)
		{
			for(j=0;j&lt;m;j++)
			{
				char s[5];
				scanf(&quot;%s&quot;,s);
				mp[i][j]=s[0];
			}
		}

		for(i=0;i&lt;m;i++)
		{
			k=-1;
			for(j=0;j&lt;n;j++)
			{
				if(mp[j][i]=='R')
				{
					sd[j][i]=j;
					k=j;
				}
				else if(mp[j][i]=='F')
				{
					sd[j][i]=k;
				}
			}
		}
		int mj=0;
		for(i=0;i&lt;n;i++)
		{
			k=-1;
			dp[0]=-1;
			for(j=1;j&lt;m;j++)
			{
				k=j-1;
				while(k!=-1&amp;&amp;sd[i][k]&lt;=sd[i][j])
					k=dp[k];
				dp[j]=k;
			}
			for(j=0;j&lt;m;j++)
				mj=max(mj,(j-dp[j])*(i-sd[i][j]));

			k=m;
			dp[m-1]=m;
			for(j=m-2;j&gt;=0;j--)
			{
				k=j+1;
				while(k!=m&amp;&amp;sd[i][k]&lt;=sd[i][j])
					k=dp[k];
				dp[j]=k;
			}
			for(j=0;j&lt;m;j++)
				mj=max(mj,(dp[j]-j)*(i-sd[i][j]));
		}
		printf(&quot;%d\n&quot;,3*mj);
	}

    return 0;
}
[/code]

#### 例题23 遥远的银河（Distant Galaxy, Shanghai 2006, [LA 3695](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696 "3695 - Distant Galaxy")）

和上一题(City Game)类似，但这题略复杂。明显每个点的坐标相差太大，第一步需要对坐标进行离散化，然后记录每一个点上面和左面点的个数，最后四个循环解决问题。

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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

struct prog
{
	int tx,ty;
	int x,y;
	int i;
}p[105];
bool cmpx(prog a,prog b)
{
	return a.tx&lt;b.tx;
}
bool cmpy(prog a,prog b)
{
	return a.ty&lt;b.ty;
}

int x_num;
int y_num;
int sumx[205][205];
int sumy[205][205];
bool mp[205][205];
int main()
{
	int n;
	int cas=1;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j,k;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%d%d&quot;,&amp;p[i].tx,&amp;p[i].ty);
			p[i].i=i;
		}

		//离散化
		x_num=y_num=1;
		sort(p,p+n,cmpx);
		p[0].x=0;
		for(i=1;i&lt;n;i++)
		{
			if(p[i].tx==p[i-1].tx)
				p[i].x=p[i-1].x;
			else
				p[i].x=p[i-1].x+1;
			x_num=p[i].x+1;
		}

		sort(p,p+n,cmpy);
		p[0].y=0;
		for(i=1;i&lt;n;i++)
		{
			if(p[i].ty==p[i-1].ty)
				p[i].y=p[i-1].y;
			else
				p[i].y=p[i-1].y+1;
			y_num=p[i].y+1;
		}

		zero(mp);
		for(i=0;i&lt;n;i++)
			mp[p[i].x][p[i].y]=1;

		for(i=0;i&lt;x_num;i++)
		{
			sumy[i][0]=0;
			for(j=1;j&lt;=y_num;j++)
			{
				sumy[i][j]=sumy[i][j-1]+mp[i][j-1];
			}
		}

		for(i=0;i&lt;y_num;i++)
		{
			sumx[0][i]=0;
			for(j=1;j&lt;=x_num;j++)
			{
				sumx[j][i]=sumx[j-1][i]+mp[j-1][i];
			}
		}	
		int num=0;
		for(i=0;i&lt;x_num;i++)
			for(j=0;j&lt;y_num;j++)
			{
				num=max(num,sumy[i][y_num]);
				num=max(num,sumx[x_num][i]);
			}
		for(i=0;i&lt;x_num;i++)
		{
			for(j=i+1;j&lt;x_num;j++)
			{
				for(int s=0;s&lt;y_num;s++)
				{
					for(int t=s+1;t&lt;y_num;t++)
					{
						int shang=sumx[j][s]-sumx[i+1][s];
						int xia=sumx[j][t]-sumx[i+1][t];
						int zuo=sumy[i][t]-sumy[i][s+1];
						int you=sumy[j][t]-sumy[j][s+1];
						num=max(num,shang+xia+zuo+you+mp[i][s]+mp[i][t]+mp[j][s]+mp[j][t]);
					}
				}
			}
		}
		printf(&quot;Case %d: %d\n&quot;,cas++,num);
	}
    return 0;
}
[/code]

#### 例题24 废料堆（Garbage Heap, [UVa 10755](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696 "10755 - Garbage Heap")）

和前两题类似，这题只是将题目维度增加到三维，求立方体的最大价值和，做法差不多，详看白书及代码

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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

long long mp[25][25][25];
long long sum[25][25][25];
long long dp[25];
const long long inf=(1LL)&lt;&lt;55;
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int a,b,c;
		scanf(&quot;%d%d%d&quot;,&amp;a,&amp;b,&amp;c);
		int i,j,k;
		zero(mp);
		zero(sum);
		for(i=1;i&lt;=a;i++)
		{
			for(j=1;j&lt;=b;j++)
			{
				for(k=1;k&lt;=c;k++)
				{
					scanf(&quot;%lld&quot;,&amp;mp[i][j][k]);
				}
			}
		}

		int h,ia,ib,ja,jb;
		for(h=1;h&lt;=c;h++)
		{
			for(i=1;i&lt;=a;i++)
			{
				for(j=1;j&lt;=b;j++)
				{
					sum[i][j][h]=mp[i][j][h]+sum[i-1][j][h]+sum[i][j-1][h]-sum[i-1][j-1][h];
				}
			}
		}

		long long ans=-inf;

		for(ia=0;ia&lt;a;ia++)
		{
			for(ja=0;ja&lt;b;ja++)
			{
				for(ib=ia+1;ib&lt;=a;ib++)
				{
					for(jb=ja+1;jb&lt;=b;jb++)
					{
						long long maxk=0;
						for(h=1;h&lt;=c;h++)
						{
							long long tmp=sum[ib][jb][h]+sum[ia][ja][h]-sum[ib][ja][h]-sum[ia][jb][h];
							ans=max(ans,maxk+tmp);
							maxk=max(maxk+tmp,0LL);
						}
					}
				}
			}
		}
		printf(&quot;%lld\n&quot;,ans);
		if(T)
			printf(&quot;\n&quot;);
	}
    return 0;
}
[/code]

#### 例题25 侏罗纪（Jurassic Remains, SEERC 2003, [LA 2965](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=966 "2965 - Jurassic Remains"), [POJ 1903](http://poj.org/problem?id=1903 "Jurassic Remains")）

最好想的办法是穷举，但复杂度是$$O({2}^{n})$$，有点大。这题就可以用中途想遇法，先求前$$n/2$$个字符串能得到的值，再求剩余字符串能得到的值，最后二分判断是否可以相遇

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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

string s[30];
int num[30][30];
int num2[30];
struct prog{
	int num;
	int len;
	int xh;
}qian[5000],hou[5000];
void mycount(int l,int r,bool zl)
{
	prog *tmp;
	if(zl==0)
	{
		tmp=qian;
	}
	else
	{
		tmp=hou;
	}
	zero(tmp);

	int i,j;
	int len2=1;
	int len=0;
	for(i=0;i&lt;(1&lt;&lt;(r-l));i++)
	{

		int k=i;
		j=l;
		int ans=0;
		int len=0;
		while(k)
		{
			if(k%2==1)
			{
				ans=ans^num2[j];
				len++;
			}
			j++;
			k/=2;
		}
		tmp[i].num=ans;
		tmp[i].len=len;
		tmp[i].xh=i;
	}
}
int erfen(int l,int r,int k)
{
	if(l+1==r)
	{
		if(hou[l].num==k)
			return l;
		else
			return -1;
	}
	int m=(l+r)/2;
	if(hou[m].num&lt;=k)
		return erfen(m,r,k);
	else
		return erfen(l,m,k);
}

bool cmp(prog a,prog b)
{
	if(a.num==b.num)
		return a.len&lt;b.len;
	return a.num&lt;b.num;
}
int main()
{
	int n;
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		int i,j;
		for(i=0;i&lt;n;i++)
			cin&gt;&gt;s[i];
		zero(num);
		for(i=0;i&lt;n;i++)
		{
			for(j=0;j&lt;s[i].length();j++)
			{
				num[i][s[i][j]-'A']=(!num[i][s[i][j]-'A']);
			}
		}
		for(i=0;i&lt;n;i++)
		{
			num2[i]=0;
			for(j=0;j&lt;26;j++)
			{
				num2[i]=2*num2[i]+num[i][j];
			}
		}
		mycount(0,n/2,0);
		mycount(n/2,n,1);
		sort(hou,hou+(1&lt;&lt;(n-n/2)),cmp);
		int ans=0;
		int ansi,ansj;
		for(i=0;i&lt;(1&lt;&lt;(n/2));i++)
		{
			j=erfen(0,(1&lt;&lt;(n-n/2)),qian[i].num);
			if(j==-1)
				continue;
			int qianhou=qian[i].len+hou[j].len;
			if(qianhou&gt;ans)
			{
				ansi=qian[i].xh;
				ansj=hou[j].xh;
				ans=qianhou;
			}
		}
		cout&lt;&lt;ans&lt;&lt;endl;
		if(ans==0)
			continue;
		bool sp=0;
		int t=0;
		while(ansi)
		{
			if(ansi%2==1)
			{
				if(sp)
					cout&lt;&lt;' ';
				cout&lt;&lt;t+1;
				sp=1;
			}
			t++;
			ansi/=2;
		}

		t=n/2;
		while(ansj)
		{
			if(ansj%2==1)
			{
				if(sp)
					cout&lt;&lt;' ';
				cout&lt;&lt;t+1;
				sp=1;
			}
			t++;
			ansj/=2;
		}
		cout&lt;&lt;endl;
	}
    return 0;
}
[/code]