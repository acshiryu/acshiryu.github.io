title: 《算法竞赛入门经典训练指南》问题求解常见策略1
toc: true
tags:
  - DFS
  - 搜索
  - 枚举
  - 递推
categories:
  - 学习笔记
id: 1894
date: 2013-07-20 12:47:08
---

# 问题求解常见策略(1)

#### 例题7 偶数矩阵（Even Parity，[Uva11464](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2459 "11464 - Even Parity")）

枚举题，只需要枚举处第一行的最终状态就可以推出其他行，然后在判断是否满足变换规则。最后找出最小变动量

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
#define MAX 10000000
struct{
	int x,y;
}a[20][20];
int n;

int check(int k)
{
	int i;
	for(i=0;i&lt;n;i++)
		a[0][i].y=0;
	i=0;
	while(k)
	{
		a[0][i].y=k%2;
		k=k/2;
		i++;
	}

	for(i=0;i&lt;n;i++)
		if(a[0][i].x==1&amp;&amp;a[0][i].y==0)
			return -1;

	return 0;			
}
int fun()
{
	int i,j;
	for(i=1;i&lt;n;i++)
	{
		for(j=0;j&lt;n;j++)
		{
			int sum=0;
			if(i&gt;=2)
				sum+=a[i-2][j].y;
			if(j&gt;0)
				sum+=a[i-1][j-1].y;
			if(j&lt;n-1)
				sum+=a[i-1][j+1].y;
			if(sum%2==0)
				a[i][j].y=0;
			else
				a[i][j].y=1;
			if(a[i][j].y==0&amp;&amp;a[i][j].x==1)
				return MAX;
		}

	}

	int cnt=0;
	for(i=0;i&lt;n;i++)
		for(j=0;j&lt;n;j++)
			if(a[i][j].x==0&amp;&amp;a[i][j].y==1)
				cnt++;

	return cnt;
}
int main()
{
	int T;
	int cas=1;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		scanf(&quot;%d&quot;,&amp;n);
		int i,j;
		for(i=0;i&lt;n;i++)
		{
			for(j=0;j&lt;n;j++)
			{
				scanf(&quot;%d&quot;,&amp;a[i][j].x);
			}
		}

		int ans=MAX;

		for(i=0;i&lt;(1&lt;&lt;n);i++)
		{
			if(check(i)==-1)
				continue;
			ans=min(ans,fun());
		}
		if(ans!=MAX)
			printf(&quot;Case %d: %d\n&quot;,cas++,ans);
		else
			printf(&quot;Case %d: -1\n&quot;,cas++);
	}
     return 0;
}
[/code]
<!--more-->

#### 例题8 彩色立方体（Colored Cubes，[LA3401](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1402 "3401 - Colored Cubes"),[POJ2741](http://poj.org/problem?id=2741 "POJ2741 - Colored Cubes")）

枚举题，枚举每个立方体的24种旋转，然后求出最小填涂方案。注意，第一个立方体就不必枚举了

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
#define MAX 1000000

int xz[30][10];
int xz_cnt;
int n;
int ans;
struct prog{
	string color[6];
}a[10];
string cr[10];

void DFS(int k,int x[])
{
//	cout&lt;&lt;k&lt;&lt;endl;
	if(k==n)
	{
		int i,j,p;
		int sum=0;
		for(i=0;i&lt;6;i++)
		{

			int sum_tmp;
			sum_tmp=0;
			for(j=0;j&lt;n;j++)
			{
				int xt=1;

				cr[j]=a[j].color[xz[x[j]][i]];
				for(p=0;p&lt;j;p++)
				{
					if(cr[j].compare(cr[p])==0)
						xt++;
				}
				sum_tmp=max(sum_tmp,xt);
			}

			sum+=(n-sum_tmp);
			if(sum&gt;=ans)
				return ;
		}
		ans=sum;
	//	cout&lt;&lt;ans&lt;&lt;endl;
	}
	else
	{
		for(int i=0;i&lt;xz_cnt;i++)
		{
			x[k]=i;
			DFS(k+1,x);
		}
	}
}
void xuanzhuan(int ding,int di,int a,int b,int c,int d)
{
	int abcd[4];
	abcd[0]=a;
	abcd[1]=b;
	abcd[2]=c;
	abcd[3]=d;
	int i,j;
	for(i=0;i&lt;4;i++,xz_cnt++)
	{
		xz[xz_cnt][0]=ding;
		xz[xz_cnt][5]=di;
		for(j=1;j&lt;=4;j++)
			xz[xz_cnt][j]=abcd[(i+j)%4];
	}
}
void init()
{
	zero(xz);
	xz_cnt=0;
	//1的对面是6,2的对面是5,3的对面是4
	xuanzhuan(2,3,0,1,5,4);
	xuanzhuan(3,2,0,4,5,1);
	xuanzhuan(4,1,0,2,5,3);
	xuanzhuan(1,4,0,3,5,2);
	xuanzhuan(0,5,2,4,3,1);
	xuanzhuan(5,0,2,1,3,4);
}
int main()
{

	init();
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j;
		for(i=0;i&lt;n;i++)
			for(j=0;j&lt;6;j++)
				cin&gt;&gt;a[i].color[j];
	//	cout&lt;&lt;1&lt;&lt;endl;
		ans=MAX;
		int x[10];
		x[0]=0;
		DFS(1,x);
		printf(&quot;%d\n&quot;,ans);
	}

    return 0;
}
[/code]

#### 例题9 中国麻将（Chinese Mahjong，[Uva11210](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2151 "11210 - Chinese Mahjong")）

枚举题，先枚举出将，然后搜索对剩余的一张牌搜索出他的顺和刻

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

char mj[50][10];
int mj_num;
int a[50];
int own[15];
int own_num;
inline void init()
{
	mj_num=0;
	zero(mj);
	int i;
	for(i=1;i&lt;10;i++,mj_num++)
	{
		mj[mj_num][0]=i+'0';
		mj[mj_num][1]='T';
	}
	for(i=1;i&lt;10;i++,mj_num++)
	{
		mj[mj_num][0]=i+'0';
		mj[mj_num][1]='S';
	}
	for(i=1;i&lt;10;i++,mj_num++)
	{
		mj[mj_num][0]=i+'0';
		mj[mj_num][1]='W';
	}
	strcpy(mj[mj_num++],&quot;DONG&quot;);
	strcpy(mj[mj_num++],&quot;NAN&quot;);
	strcpy(mj[mj_num++],&quot;XI&quot;);
	strcpy(mj[mj_num++],&quot;BEI&quot;);
	strcpy(mj[mj_num++],&quot;ZHONG&quot;);
	strcpy(mj[mj_num++],&quot;FA&quot;);
	strcpy(mj[mj_num++],&quot;BAI&quot;);
}
int mj_num_cnt(char *s)
{
	if(s[1]=='T')
		return s[0]-'0'-1;
	if(s[1]=='S')
		return s[0]-'0'+8;
	if(s[1]=='W')
		return s[0]-'0'+17;
	int i;
	for(i=27;i&lt;34;i++)
		if(strcmp(s,mj[i])==0)
			return i;
}
int ans[50];
int ans_num;
void DFS(int mj_i,int sd)
{
	int i,j,k;
	if(ans_num&gt;0&amp;&amp;ans[ans_num-1]==mj_i)
		return ;
	if(sd==5)
	{
		ans[ans_num++]=mj_i;
		return ;
	}
	bool dt=true;
	for(i=0;i&lt;own_num;i++)
	{
		j=own[i];
		if(a[j]==0)
			continue;
		if(a[j]==3)
		{
			a[j]-=3;
			DFS(mj_i,sd+1);
			a[j]+=3;
		}
		if( (j&lt;9&amp;&amp;j&gt;1) ||(j&lt;18&amp;&amp;j&gt;10) ||(j&lt;27&amp;&amp;j&gt;19))
		{
			if(a[j-1]&gt;0&amp;&amp;a[j-2]&gt;0&amp;&amp;a[j]&gt;0)
			{
				a[j-1]--;
				a[j-2]--;
				a[j]--;
				DFS(mj_i,sd+1);
				a[j-1]++;
				a[j-2]++;
				a[j]++;
				dt=false;
			}
		}

		if( (j&lt;8&amp;&amp;j&gt;0) ||(j&lt;17&amp;&amp;j&gt;9) ||(j&lt;26&amp;&amp;j&gt;18))
		{
			if(a[j-1]&gt;0&amp;&amp;a[j+1]&gt;0&amp;&amp;a[j]&gt;0)
			{
				a[j-1]--;
				a[j+1]--;
				a[j]--;
				DFS(mj_i,sd+1);
				a[j-1]++;
				a[j+1]++;
				a[j]++;
				dt=false;
			}
		}

		if( (j&lt;7&amp;&amp;j&gt;=0) ||(j&lt;16&amp;&amp;j&gt;=9) ||(j&lt;25&amp;&amp;j&gt;=18))
		{
			if(a[j+2]&gt;0&amp;&amp;a[j+1]&gt;0&amp;&amp;a[j]&gt;0)
			{
				a[j+2]--;
				a[j+1]--;
				a[j]--;
				DFS(mj_i,sd+1);
				a[j+2]++;
				a[j+1]++;
				a[j]++;
				dt=false;
			}
		}
		if(dt==false)
			break;
	}

}
int main()
{
	int i,j;
	int cas=1;
	init();
	char s[10];
//	cout&lt;&lt;mj_num_cnt(&quot;FA&quot;)&lt;&lt;' '&lt;&lt;mj[32]&lt;&lt;endl;
	while(zero(a),~scanf(&quot;%s&quot;,s))
	{
		if(s[0]=='0')
			break;
		zero(own);
		j=mj_num_cnt(s);
		own[0]=j;
		own_num=1;
		a[j]++;
		for(i=1;i&lt;13;i++)
		{
			scanf(&quot;%s&quot;,s);
			j=mj_num_cnt(s);
			if(a[j]==0)
			{
				own[own_num++]=j;
			}
			a[j]++;
		}

		ans_num=0;
		for(i=0;i&lt;34;i++)
		{
			if(a[i]==4)
				continue;
			if(a[i]==0)
			{
				own[own_num++]=i;
			}
			a[i]++;

			for(j=0;j&lt;own_num;j++)
			{
				if(a[own[j]]&gt;=2)
				{
					a[own[j]]-=2;
					DFS(i,1);
					a[own[j]]+=2;
				}
			}
			if(a[i]==1)
				own_num--;
			a[i]--;
		}
		printf(&quot;Case %d: &quot;,cas++);
		if(ans_num==0)
		{
			printf(&quot;Not ready\n&quot;);
			continue;
		}
		for(i=0;i&lt;ans_num;i++)
		{
			if(i)
			{
				printf(&quot; &quot;);
			}
			printf(&quot;%s&quot;,mj[ans[i]]);
		}
		printf(&quot;\n&quot;);
	}
    return 0;
}
[/code]

#### 例题10 正整数序列（Help is needed for Dexter，[Uva11384](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2379 "11384 - Help is needed for Dexter")）

终于不是枚举题了，比较简单的一道递推，公式f(n)=f(n/2)+1

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

int f(int n)
{
	if(n==1)
		return 1;
	return f(n/2)+1;
}
int main()
{
	int n;
	while(~scanf(&quot;%d&quot;,&amp;n))
	{
		printf(&quot;%d\n&quot;,f(n));
	}
    return 0;
}
[/code]

#### 例题11 新汉诺塔问题（A Different Task，[Uva10795](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1736 "10795 - A Different Task")）

较复杂的一道递推题，方法还是和经典汉诺塔推理方法类似，详情还是看白书吧

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

int s[100];
int t[100];
long long f(int *p,int k,int zd)
{
	if(k&lt;0)
		return 0;
	if(p[k]==zd)
		return f(p,k-1,zd);
	return f(p,k-1,6-p[k]-zd)+((1LL)&lt;&lt;(k));
}
int main()
{
	int n;
	int cas=1;
	while(scanf(&quot;%d&quot;,&amp;n),n)
	{
		int i,j;
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;s[i]);
		for(i=0;i&lt;n;i++)
			scanf(&quot;%d&quot;,&amp;t[i]);

		for(i=n-1;i&gt;=0;i--)
			if(s[i]!=t[i])
				break;

		if(i==-1)
		{
			printf(&quot;Case %d: 0\n&quot;,cas++);
			continue;
		}

		long long ans=0;
		int k=6-s[i]-t[i];
		ans=f(s,i-1,k)+f(t,i-1,k)+1;
		printf(&quot;Case %d: %lld\n&quot;,cas++,ans);
	}
    return 0;
}
[/code]