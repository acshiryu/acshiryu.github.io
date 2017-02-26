title: 《算法竞赛入门经典训练指南》思维的体操
toc: true
tags:
  - 思维
  - 数学
  - 模拟
  - 贪心
categories:
  - 学习笔记
id: 1861
date: 2013-03-05 21:05:14
---

# 思维的体操

#### 例题1 勇者斗恶龙（The Dragon of Loowater，Uva 11292）

贪心水题

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;algorithm&gt;
using namespace std;
int d[20005],x[20005];
int main()
{
	int n,m;
	while(scanf(&quot;%d%d&quot;,&amp;n,&amp;m),n||m)
	{
		int i,j,k;
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;d[i]);
		for(i=0;i&lt;m;i++)
			scanf(&quot;%d&quot;,&amp;x[i]);

		sort(d,d+n);
		sort(x,x+m);

		j=0;
		int sum=0;
		for(i=0;i&lt;n;i++)
		{
			while(j&lt;m&amp;&amp;x[j]&lt;d[i])
				j++;
			if(j==m)
				break;
			if(j!=m)
				sum+=x[j++];
		}

		if(i!=n)
			printf(&quot;Loowater is doomed!\n&quot;);
		else
			printf(&quot;%d\n&quot;,sum);
	}
	return 0;
}
[/code]

<!--more-->

#### 例题2 突击战（Commando War，Uva 11729）

比较简单的贪心题

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;algorithm&gt;
using namespace std;
struct prog{
	int b,j;
}a[1005];
bool cmp(prog a,prog b)
{
	if(a.j==b.j)
		return a.b&gt;b.b;
	return a.j&gt;b.j;
}
int main()
{
	int n,cnt=1;;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j,k;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%d%d&quot;,&amp;a[i].b,&amp;a[i].j);
		}
		sort(a,a+n,cmp);

		int ans=0;
		int tmp=0;
		for(i=0;i&lt;n;i++)
		{
			ans=max(ans,tmp+a[i].b+a[i].j);
			tmp+=a[i].b;
		}
		printf(&quot;Case %d: %d\n&quot;,cnt++,ans);
	}
	return 0;
}
[/code]

#### 例题3 分金币（Spreading the Wealth，Uva 11300）

这题有点意思，初看起来不知道怎么下手，但可以发现一个人得到的金币来自于其两边的人，或者他只能将金币转手给旁边的人，于是我们就可以假设$${A}_{i}$$从$${A}_{i-1}$$处得到$${x}_{i-1}$$的金币，并转手给$${A}_{i+1}$$有$${x}_{i}$$的金币（注意是圆桌），于是就有$${A}_{i}+{x}_{i-1}-{x}_{i}=average$$，最后可以得出$${x}_{i}$$关于$${x}_{1}$$的表达式，依据题意，求的是$$\sum_{1}^{n}|{x}_{i}|$$的和，就可以借助数轴解决问题

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

long long money[1000005];
long long tmp[1000005];
int main()
{
	int n;
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		long long sum=0;
		int i,j;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%lld&quot;,&amp;money[i]);
			sum+=money[i];
		}
		int ave=sum/n;
		for(i=0;i&lt;n;i++)
		{
			money[i]=money[i]-ave;
		//	printf(&quot;%d\n&quot;,money[i]);
		}
		tmp[0]=0;
		for(i=1;i&lt;n;i++)
			tmp[i]=tmp[i-1]-money[i];
		sort(tmp,tmp+n);
		int mid=n/2;

		long long ans=0;
		for(i=0;i&lt;n;i++)
		{
			ans+=abs(-tmp[i]+tmp[mid]);
		}
		printf(&quot;%lld\n&quot;,ans);
	}
    return 0;
}
[/code]

#### 例题4 墓地雕塑（Graveyard，LA3708，POJ3154）

比较简单的一题，算出每个点的初始位置和移动后的位置，每个点向最近的地方移动即可。lrj书上介绍的方法更巧妙

[code lang="cpp"]
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;

double old_place[1005];
double new_place[2010];
int main()
{
	int n,m;
	while(~scanf(&quot;%d%d&quot;,&amp;n,&amp;m))
	{
		int mk=m+n;
		double old=10000.0/n;
		double now=10000.0/mk;
		int i;
		for(i=0;i&lt;n;i++)
			old_place[i]=old*i;

		for(i=0;i&lt;=mk;i++)
			new_place[i]=now*i;
		int j=0;
		double sum=0.0;
		for(i=0;i&lt;n;i++)
		{
			while(fabs(old_place[i]-new_place[j])&gt;fabs(old_place[i]-new_place[j+1]))
				j=j+1;
			sum+=fabs(old_place[i]-new_place[j]);
		}
		printf(&quot;%.4lf\n&quot;,sum);
	}
    return 0;
}
[/code]

#### 例题5 蚂蚁（Piotr's Ants，Uva10881）

如果能注意到蚂蚁“碰撞”实际上是没有改变蚂蚁最终的位置，只是改变了蚂蚁的序号的话，那这题就很容易了

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
	int x,i;
	char f;
	int rank;
}x[10010],y[10010];
bool operator&lt;(prog a,prog b)
{
	return a.x&lt;b.x;
}
bool cmpi(prog a,prog b)
{
	return a.i&lt;b.i;
}
int main()
{
	int TTT;
	scanf(&quot;%d&quot;,&amp;TTT);
	int cas=1;
	while(TTT--)
	{
		int l,t,n;
		scanf(&quot;%d%d%d&quot;,&amp;l,&amp;t,&amp;n);
		int i,j;
		for(i=0;i&lt;n;i++)
		{
			int a;
			char b[5];
			scanf(&quot;%d%s&quot;,&amp;a,b);
			x[i].x=a;
			x[i].i=i;
			if(b[0] == 'L')
			{
				x[i].f=b[0];
				y[i].x=a-t;
			}
			else
			{
				x[i].f=b[0];
				y[i].x=a+t;
			}
			y[i].f=x[i].f;
			y[i].i=x[i].i;
		}
		sort(x,x+n);
		sort(y,y+n);
		for(i=0;i&lt;n;i++)
		{
			x[i].rank=i;
			y[i].rank=i;
		}

		sort(x,x+n,cmpi);
		printf(&quot;Case #%d:\n&quot;,cas++);
		for(i=0;i&lt;n;i++)
		{
			int k=x[i].rank;
			if(y[k].x&lt;0||y[k].x&gt;l)
			{
				printf(&quot;Fell off\n&quot;);
			}
			else
			{
				if((k&gt;0&amp;&amp;y[k].x==y[k-1].x)||(k&lt;n-1&amp;&amp;y[k].x==y[k+1].x))
					printf(&quot;%d Turning\n&quot;,y[k].x);
				else
					printf(&quot;%d %c\n&quot;,y[k].x,y[k].f);
			}
		}
		puts(&quot;&quot;);
	}
    return 0;
}
[/code]

#### 例题6 立方体成像（Image Is Everything，[LA2995](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996 "2995 - Image Is Everything")）

较麻烦的一道模拟题，看了lrj的白书后才过的，书上讲的较详细，此处略过

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
char tx[15][15][15];
char kan[10][15][15];
void xyz(int k,int i,int j,int len,int&amp; x,int&amp; y , int&amp; z)
{
	switch(k)
	{
	case 0:
		x=len;
		y=j;
		z=i;
		break;
	case 1:
		x=n-1-j;
		y=len;
		z=i;
		break;
	case 2:
		x=n-1-len;
		y=n-1-j;
		z=i;
		break;
	case 3:
		x=j;
		y=n-1-len;
		z=i;
		break;
	case 4:
		x=n-1-i;
		y=j;
		z=len;
		break;
	case 5:
		x=i;
		y=j;
		z=n-1-len;
		break;
	default:break;
	}
}

int main()
{
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j,k,p,q;
		for(i=0;i&lt;n;i++)
			for(j=0;j&lt;n;j++)
				for(k=0;k&lt;n;k++)
					tx[i][j][k]='#';

		for(i=0;i&lt;n;i++)
			for(j=0;j&lt;6;j++)
				scanf(&quot;%s&quot;,kan[j][i]);
/*
		for(k=0;k&lt;6;k++)
		{
			for(i=0;i&lt;n;i++)
			{
				for(j=0;j&lt;n;j++)
					cout&lt;&lt;kan[k][i][j];
				cout&lt;&lt;endl;
			}
			cout&lt;&lt;endl;
		}
*/

		for(k=0;k&lt;6;k++)
		{
			for(i=0;i&lt;n;i++)
				for(j=0;j&lt;n;j++)
					if(kan[k][i][j]=='.')
					{
						for(p=0;p&lt;n;p++)
						{
							int x,y,z;
							xyz(k,i,j,p,x,y,z);
							tx[x][y][z]='.';
					//		cout&lt;&lt;x&lt;&lt;' '&lt;&lt;y&lt;&lt;' '&lt;&lt;z&lt;&lt;endl;
						}
					//	cout&lt;&lt;endl;
					}

		}
		while(1)
		{
			bool ok=true;
			for(k=0;k&lt;6;k++)
			{
				for(i=0;i&lt;n;i++)
					for(j=0;j&lt;n;j++)
						if(kan[k][i][j]!='.')
						{
							for(p=0;p&lt;n;p++)
							{
								int x,y,z;
								xyz(k,i,j,p,x,y,z);
								//cout&lt;&lt;x&lt;&lt;y&lt;&lt;z&lt;&lt;endl;
								//cout&lt;&lt;tuxing&lt;&lt;endl;
								if(tx[x][y][z]=='.')
									continue;
								if(tx[x][y][z]=='#')
								{
									tx[x][y][z]=kan[k][i][j];
									break;
								}
								if(tx[x][y][z]==kan[k][i][j])
								{
									break;
								}
								tx[x][y][z]='.';
								ok=false;
							}
						}
			}
			if(ok==true)
				break;
		}
		int sum=0;
		for(i=0;i&lt;n;i++)
			for(j=0;j&lt;n;j++)
				for(k=0;k&lt;n;k++)
					if(tx[i][j][k]!='.')
						sum++;

		printf(&quot;Maximum weight: %d gram(s)\n&quot;,sum);

	}
    return 0;
}
[/code]