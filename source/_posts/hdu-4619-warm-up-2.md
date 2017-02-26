title: HDU4619Warm up 2 二分图匹配 2013多校第二场1009
toc: true
tags:
  - 二分图
  - 图论
  - 最大匹配
  - 贪心
categories:
  - 算法竞赛
id: 1937
date: 2013-07-26 09:30:02
---

实际上就是求的二分图最大匹配
[code lang="cpp"]
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

struct prog{
	int x;int y;
}h[1010],s[1010];
bool map[1010][1010];
int link[1010];
bool vis[1010];
int n,m;
bool check(int i,int j)
{
	if(h[i].x==s[j].x&amp;&amp;h[i].y==s[j].y)
		return 1;
	if(h[i].x+1==s[j].x&amp;&amp;h[i].y==s[j].y)
		return 1;
	if(h[i].x==s[j].x&amp;&amp;h[i].y==s[j].y+1)
		return 1;
	if(h[i].x+1==s[j].x&amp;&amp;h[i].y==s[j].y+1)
		return 1;
	return 0;
}

bool find ( int k ) 
{//对k寻找匹配，如果找到就记录匹配，并返回true,否则返回false
    int i , j ;
    for ( i = 1 ; i &lt;= m ; i ++ )
    {//对所有节点遍历一遍，寻找没有访问过并且与i连同的点
        if ( map [k][i] ==true &amp;&amp; ! vis[i] )
        {
            vis [i] = true ;    //记录改点以被访问
            if ( link [i] == 0 || find ( link [i] ) )
            {//如果该点还未与其他点匹配，或还能找到其他点能与该点匹配的点j进行匹配，即存在增广路
                link [ i ] = k ;    //将i与k进行匹配
                return true;
            }
        }
    }
    return false;
}

int main()
{

	while(~scanf(&quot;%d%d&quot;,&amp;n,&amp;m),n||m)
	{
		int i,j;
		for(i=1;i&lt;=n;i++)
			scanf(&quot;%d%d&quot;,&amp;h[i].x,&amp;h[i].y);
		for(i=1;i&lt;=m;i++)
			scanf(&quot;%d%d&quot;,&amp;s[i].x,&amp;s[i].y);

		zero(map);
		zero(link);
		for(i=1;i&lt;=n;i++)
		{
			for(j=1;j&lt;=m;j++)
			{
				map[i][j]=check(i,j);
			//	if(map[i][j]==1)
				//	cout&lt;&lt;i&lt;&lt;' '&lt;&lt;j&lt;&lt;endl;
			}
		}

		int ans = 0 ;    //最大匹配数
        for ( i = 1 ; i &lt;= n ; i ++ )
        {
            memset ( vis , false , sizeof ( vis ) ) ;//对所有数据都初始为0，表明数据还没有试探
            if ( find ( i ) ) //如果对i找到一个匹配
                ans ++ ;
        }
	//	cout&lt;&lt;ans&lt;&lt;endl;
		printf(&quot;%d\n&quot;,m+n-ans);
	}
    return 0;
}
[/code]