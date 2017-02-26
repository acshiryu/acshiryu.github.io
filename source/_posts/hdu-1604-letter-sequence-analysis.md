title: HDU1604Deque  2013多校第一场1005
toc: true
tags:
  - DP
  - 动态规划
  - 多校
categories:
  - 算法竞赛
id: 1917
date: 2013-07-24 12:30:15
---

多校的时候数据太水了，竟然让我过了。

题目实际上就是求的从某个点开始到终点的非升非降序列长度和的最大值，其中要排除重复的元素，就是DP

> 官方解题报告
>     考虑题目的一个简化版本：使双端队列单调上升。对于序列A和队列Q，找出队列中最早出现的数字Ax，则Ax将Q分成的两个部分分别是原序列中以Ax开始的最长上升和最长下降序列，答案即为这两者之和的最大值。而对于本体，由于存在相同的元素，所以只要找到以Ax为起点的最长不下降序列和最长不上升序列的和，然后减去两个里面出现Ax次数的最小值即可。

<!--more-->
我的代码
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

const int maxn=100010;
int a[maxn];
int jia[maxn];
int jian[maxn];
int dp[2][maxn];
int jia_num;
int jian_num;
int erfenjia(int s,int t,int k)
{
	if(s==t)
		return s;
	int m=(s+t)/2;

	if(k&gt;=jia[m])
		return erfenjia(m+1,t,k);
	else
		return erfenjia(s,m,k);
}

int erfenjian(int s,int t,int k)
{
	if(s==t)
		return s;
	int m=(s+t)/2;

	if(k&lt;=jian[m])
		return erfenjian(m+1,t,k);
	else
		return erfenjian(s,m,k);
}
int erfen(int*a ,int s,int t,int k,bool x)
{
	if(s==t)
		return s;
	int m=(s+t)/2+1;
	if(x==0&amp;&amp;k&lt;=a[m])
		return erfen(a,s,m-1,k,x);
	else if(x==1&amp;&amp;k&gt;=a[m])
		return erfen(a,s,m-1,k,x);
	else
		return erfen(a,m,t,k,x);
}
int main()
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int n;
		int i,j;
		int ans=1;
		scanf(&quot;%d&quot;,&amp;n);
		zero(jia);
		zero(jian);
		jia_num=jian_num=0;
		for(i=0;i&lt;n;i++)
		{
			scanf(&quot;%d&quot;,&amp;a[i]);
		}
		for(i=0;i&lt;n;i++)
		{
			int tmp=a[n-i-1];
			if(i!=0)
			{
				int s,t;
				if(tmp&gt;=jia[jia_num-1])
					s=jia_num++;
				else
					s=erfenjia(0,jia_num-1,tmp);

				if(tmp&lt;=jian[jian_num-1])
					t=jian_num++;
				else
					t=erfenjian(0,jian_num-1,tmp);

				jia[s]=tmp;
				jian[t]=tmp;
				int sx=erfen(jia,0,jia_num-1,tmp,0);
				int sy=erfen(jian,0,jian_num-1,tmp,1);
				if(sx==0&amp;&amp;jia[sx]&lt;=tmp)
					sx=-1;
				if(sy==0&amp;&amp;jian[sy]&gt;=tmp)
					sy=-1;
				int com=s+1+t+1-min(s-sx,t-sy);
			//	cout&lt;&lt;min(s-sx,t-sy)&lt;&lt;endl;
			//	cout&lt;&lt;s&lt;&lt;' '&lt;&lt;t&lt;&lt;endl;
			//	cout&lt;&lt;sx&lt;&lt;' '&lt;&lt;sy&lt;&lt;endl;
				if(com&gt;ans)
					ans=com;
			}
			else
			{
				jia[jia_num++]=tmp;
				jian[jian_num++]=tmp;
			}
		}
		printf(&quot;%d\n&quot;,ans);
	}
    return 0;
}
[/code]

标程
[code lang="cpp"]
#include &quot;iostream&quot;
#include &quot;cstring&quot;
#include &quot;cstdio&quot;
#include &quot;vector&quot;
#include &quot;algorithm&quot;
#include &quot;map&quot;
using namespace std;
const int N = 100010;
int a[N];
int num_up[N],num_down[N];
int dp_up[N],dp_down[N];
int n;
void getdp(int dp[],int num[])
{
	dp[n]=1;
	vector&lt;int&gt; v;
	v.push_back(a[n]);
	vector&lt;int&gt;::iterator iter;
	for(int i=n-1;i&gt;=1;i--){
		int sz=v.size();
		if(a[i]&gt;v[sz-1]){
			v.push_back(a[i]);
			dp[i]=sz+1;
			num[i]=1;
		}else if(a[i]==v[sz-1]){
			iter=upper_bound(v.begin(),v.end(),a[i]);
			dp[i]=iter-v.begin()+1;
			v.push_back(a[i]);
			pair&lt;vector&lt;int&gt;::iterator,vector&lt;int&gt;::iterator&gt; bounds;
			bounds=equal_range(v.begin(),v.end(),a[i]);
			num[i]=bounds.second-bounds.first;
		}else{
			iter=upper_bound(v.begin(),v.end(),a[i]);
			dp[i]=iter-v.begin()+1;
			*iter=a[i];
			pair&lt;vector&lt;int&gt;::iterator,vector&lt;int&gt;::iterator&gt; bounds;
			bounds=equal_range(v.begin(),v.end(),a[i]);
			num[i]=bounds.second-bounds.first;
		}
	}		
}
void debug(int a[])
{
	for(int i=1;i&lt;=n;i++){
		printf(&quot;%d &quot;,a[i]);
	}
	printf(&quot;\n&quot;);
}
int main(void)
{
	int T;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--){
		int ans=0;
		scanf(&quot;%d&quot;,&amp;n);
		map&lt;int,int&gt; mp;
		mp.clear();
		for(int i=1;i&lt;=n;i++){
			scanf(&quot;%d&quot;,&amp;a[i]);
		}
		getdp(dp_up,num_up);
		for(int i=1;i&lt;=n;i++){
			a[i]=-a[i];
		}
		getdp(dp_down,num_down);
		for(int i=1;i&lt;=n;i++){
			mp[a[i]]++;
			ans=max(ans,dp_down[i]+dp_up[i]-min(num_up[i],num_down[i]));
		}
		printf(&quot;%d\n&quot;,ans);
	}
	return 0;
}

[/code]