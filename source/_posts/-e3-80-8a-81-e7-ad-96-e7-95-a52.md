title: 《算法竞赛入门经典训练指南》问题求解常见策略2
toc: true
tags:
  - DFS
  - 二分
categories:
  - 学习笔记
id: 1904
date: 2013-07-22 16:18:56
---

# 问题求解常见策略(2)

#### 例题12 组装电脑（Assemble，[LA3971](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1972 "3971 - Assemble")，[POJ3497](http://poj.org/problem?id=3497 "POJ3497 - Assemble")）

简单二分

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;

struct prog{
	char type[25];
	char name[25];
	int price;
	int quality;
}com[1010];
bool compare_type(prog a,prog b)
{
	if(strcmp(a.type,b.type)==0)
	{
		if(a.quality==b.quality)
			return a.price&lt;b.price;
		return a.quality&lt;b.quality;
	}
	if(strcmp(a.type,b.type)&gt;0)
		return 1;
	return 0;
}
int com_start[1010];
int com_type;
int n,b;
int erfen(int s,int t)
{
	if(s==t)
		return s;
	int m=(s+t)/2+1;
	int i,j;
	int sum=0;
	for(i=0;i&lt;com_type;i++)
	{
		int less=1000000;
		for(j=com_start[i];j&lt;com_start[i+1];j++)
		{
			if(com[j].quality&gt;=m)
			{
				less=min(less,com[j].price);
			}
		}
		sum+=less;
	}
	if(sum&lt;=b)
		return erfen(m,t);
	else
		return erfen(s,m-1);
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int i,j,k;
		scanf(&quot;%d%d&quot;,&amp;n,&amp;b);
		int max_quality,min_quality;
		max_quality=0;
		min_quality=1000000000;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%s%s%d%d&quot;,&amp;com[i].type,&amp;com[i].name,&amp;com[i].price,&amp;com[i].quality);
			max_quality=max(max_quality,com[i].quality);
			min_quality=min(min_quality,com[i].quality);
		}
		sort(com,com+n,compare_type);

		com_start[0]=0;
		for(j=1,i=1;i&lt;n;i++)
		{
			if(strcmp(com[i].type,com[i-1].type))
				com_start[j++]=i;
		}
		com_type=j;
		com_start[j]=n;
		printf(&quot;%d\n&quot;,erfen(min_quality,max_quality));
	}
    return 0;
}
[/code]

<!--more-->

#### 例题13 派（Pie，[LA3635](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=19&problem=1636&mosmsg=Submission+received+with+ID+1264444 "3635 - Pie")，[POJ3211](http://poj.org/problem?id=3122 "POJ3122 - Pie")）

二分题，和上题类似，注意精度问题

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;

const double pi=3.14159265359;
const double inf=0.00001;
double area[10005];
int n,f;

double erfen(double s,double t)
{
	double m=(s+t)/2+inf;
	if(fabs(s-t)&lt;inf)
		return s;
	int i,j;
	int sum=0;
	for(i=0;i&lt;n;i++)
	{
		sum+=(int)(area[i]/m);
	}
	if(sum&gt;=f)
		return erfen(m,t);
	else
		return erfen(s,m-inf);
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		scanf(&quot;%d%d&quot;,&amp;n,&amp;f);
		f++;
		int i,j;
		double sum=0.0;
		for(i=0;i&lt;n;i++)
		{
			int r;
			scanf(&quot;%d&quot;,&amp;r);
			area[i]=pi*r*r;
			sum+=area[i];
		}
		printf(&quot;%.4lf\n&quot;,erfen(0,sum/f));
	}
    return 0;
}
[/code]

#### 例题14 填充正方形（Fill the Square，[Uva11520](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2515 "11520 - Fill the Square")）

水题

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;

char mat[15][15];
int main()
{
	int T,cas=1;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n,i,j;
		scanf(&quot;%d&quot;,&amp;n);
		memset(mat,'.',sizeof(mat));
		for(i=1;i&lt;=n;i++)
			scanf(&quot;%s&quot;,mat[i]+1);
		for(i=1;i&lt;=n;i++)
		{
			for(j=1;j&lt;=n;j++)
			{
				if(mat[i][j]=='.')
				{
					for(char c='A';c&lt;='Z';c++)
					{
						if(c!=mat[i][j-1]&amp;&amp;c!=mat[i][j+1]&amp;&amp;c!=mat[i-1][j]&amp;&amp;c!=mat[i+1][j])
						{
							mat[i][j]=c;
							break;
						}
					}
				}
			}
		}
		printf(&quot;Case %d:\n&quot;,cas++);
		for(i=1;i&lt;=n;i++)
			printf(&quot;%s\n&quot;,mat[i]+1);
	}
    return 0;
}
[/code]

#### 例题15 网络（Network，[LA3902](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1903 "3902 - Network")）

深搜的题，看着白书过的

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;vector&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

const int maxn=1000+10;
vector&lt;int&gt;link[maxn],node[maxn];
bool vis[maxn];
int fa[maxn];
int n,s,k;
void init()
{
	for(int i=0;i&lt;=n;i++)
	{
		link[i].clear();
		node[i].clear();
	}
}
void build(int root,int father,int dep)
{
	int i,j;
	fa[root]=father;
	if(link[root].size()==1&amp;&amp;dep&gt;k)
		node[dep].push_back(root);
	for(i=0;i&lt;link[root].size();i++)
	{
		int knode=link[root][i];
		if(knode!=father)
		{
			build(knode,root,dep+1);
		}
	}
}
void dfs(int root ,int fat,int dep)
{
//	cout&lt;&lt;root&lt;&lt;' '&lt;&lt;dep&lt;&lt;endl;
	vis[root]=true;
	if(dep==k)
		return ;
	for(int i=0;i&lt;link[root].size();i++)
	{
		int knode=link[root][i];
		if(knode!=fat)
		{
			dfs(knode,root,dep+1);
		}
	}
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		scanf(&quot;%d%d%d&quot;,&amp;n,&amp;s,&amp;k);
		int i,j;
		init();
		for(i=1;i&lt;n;i++)
		{
			int a,b;
			scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
			link[a].push_back(b);
			link[b].push_back(a);
		}
		build(s,-1,0);
		int ans=0;
		zero(vis);
		for(i=n-1;i&gt;k;i--)
		{
			for(j=0;j&lt;node[i].size();j++)
			{
				int knode=node[i][j];
				if(vis[knode])
					continue;

				for(int d=0;d&lt;k;d++)
				{
					knode=fa[knode];
				}

				dfs(knode,-1,0);
				ans++;
			}
		}
		printf(&quot;%d\n&quot;,ans);
	}
    return 0;
}
[/code]

#### 例题16 长城守卫（Beijing Guards，[LA3177](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1178 "3177 - Beijing Guards")）

二分，当n为偶数时，很容易输出答案，唯一麻烦的就是n为基数的情况，详看白书

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

int n;
const int maxn=100000+10;
int r[maxn];
int erfen(int a,int c)
{
	int b=(a+c)/2;
	if(a==c)
		return a;
	int i,j;
	int left,right;
	left=right=0;
	left=r[0];
	for(i=1;i&lt;n-1;i++)
	{
		if(i%2==0)
		{
			right=b-r[0]-right;
			if(right&gt;r[i])
			{
				right=r[i];
				left=0;
			}
			else
			{
				left=r[i]-right;
			}
		}
		else
		{
			left=r[0]-left;
			if(left&gt;r[i])
			{
				left=r[i];
				right=0;
			}
			else
			{
				right=r[i]-left;
			}
		}
	}
//	cout&lt;&lt;left&lt;&lt;' '&lt;&lt;right&lt;&lt;' '&lt;&lt;b&lt;&lt;endl;
	int all=r[0]+right+r[n-1];
	if(all&gt;b)
	{
		return erfen(b+1,c);
	}
	else
	{
		return erfen(a,b);
	}
}
int main()
{
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j;
		int l,m;
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;r[i]);
		if(n==1)
		{
			printf(&quot;%d\n&quot;,r[0]);
			continue;
		}
		l=m=0;
		for(i=0;i&lt;n;i++)
		{
			l=max(l,r[i]+r[(i+1)%n]);
			m=max(m,3*r[i]);
		}

		if(n%2==0)
		{
			printf(&quot;%d\n&quot;,l);
		}
		else
		{
			printf(&quot;%d\n&quot;,erfen(l,m));
		}

	}
    return 0;
}
[/code]