title: hdu4419 Colourful Rectangle  搜索+矩形分割  杭州赛区网赛最后一题
toc: true
tags:
  - DFS
  - 搜索
  - 矩形
  - 矩形切割
categories:
  - 算法竞赛
id: 1612
date: 2012-09-23 17:24:58
---

这题就是一个矩阵分割，因为之前做过USACO上类似的一题，所以最开始就看了这题

矩阵分割，有多种情况，具体可以参考我的[USACO3.1.4 Shaping Regions 搜索+矩形切割](/archives/1367 "USACO3.1.4 Shaping Regions 搜索+矩形切割")

但这题略有不同，USACO上面是颜色覆盖，这里是颜色相加，所以对于相交的区域不能那个直接计算面积，还要继续递推直到最后一个矩形

但有一个问题，矩形太多，递推超时，注意到颜色只有三种，所以我们可以对颜色进行一次一次排序（让R,G,B顺序），如果到分割第t个矩形时，当前所加的颜色含有第t个矩形的颜色，则我们可以直接跳转到下一个颜色区域，这样就可以避免重复搜索

还有一个问题，就是颜色的处理，因为颜色的相加，可以用位运算来解决，R-1,G-2,B-4，这样就对颜色的相加转化成或运算，具体可看我的代码（刚用我的代码提交了下，发现不论时间还是空间排行暂时第一，第一次啊！）

[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

__int64 ans[10];
struct rect{
    int llx,lly,urx,ury,c;
}cfx[10005];
const int sx[]={1,2,4,3,5,6,7};
int color[5];
int color_rank[3];
void DFS(int lx,int ly,int rx,int ry,int t,int c)
{
	if(lx==rx||ly==ry)
		return ;
        if(t==-1)
	{
		if(c!=0)
			ans[c]+=((__int64)(rx-lx))*(ry-ly);
                return ;
	}
	if(t&gt;=0&amp;&amp;t&lt;color_rank[0]&amp;&amp;((c|1)==c))
	{
		DFS(lx,ly,rx,ry,-1,c);
		return ;
	}
	else if(t&gt;=color_rank[0]&amp;&amp;t&lt;color_rank[1]&amp;&amp;((c|2)==c))
	{
		DFS(lx,ly,rx,ry,color_rank[0]-1,c);
		return ;
	}
	else if(t&gt;=color_rank[1]&amp;&amp;t&lt;color_rank[2]&amp;&amp;((c|4)==c))
	{

		DFS(lx,ly,rx,ry,color_rank[1]-1,c);
		return ;
	}

    if(cfx[t].llx&gt;=rx||cfx[t].lly&gt;=ry||cfx[t].urx&lt;=lx||cfx[t].ury&lt;=ly)
    {
        DFS(lx,ly,rx,ry,t-1,c);
    }
    else
    {
        int k1,k2,k3,k4;
        k1=max(lx,cfx[t].llx);
        k2=min(rx,cfx[t].urx);
        if(lx&lt;k1)
            DFS(lx,ly,k1,ry,t-1,c);
        if(rx&gt;k2)
            DFS(k2,ly,rx,ry,t-1,c);

        k3=max(ly,cfx[t].lly);
        k4=min(ry,cfx[t].ury);
        if(ly&lt;k3)
            DFS(k1,ly,k2,k3,t-1,c);
        if(ry&gt;k4)
            DFS(k1,k4,k2,ry,t-1,c);
		if(k1!=k2&amp;&amp;k3!=k4)
			DFS(min(k1,k2),min(k3,k4),max(k1,k2),max(k3,k4),t-1,cfx[t].c|c);
    }
}
bool cmp(rect a,rect b)
{
	return a.c&lt;b.c;
}

int main()
{
	int T,cnt=1;
	scanf(&quot;%d&quot;,&amp;T);
	while(T--)
	{
		int x,y,n,i;
		scanf(&quot;%d&quot;,&amp;n);
		x=y=0;
		zero(ans);
		zero(color);
		for(i=0;i&lt;n;i++)
		{
			char str[3];
			scanf(&quot;%s&quot;,str);
			if(str[0]=='R')
				cfx[i].c=1;
			else if(str[0]=='G')
				cfx[i].c=2;
			else if(str[0]=='B')
				cfx[i].c=4;

			scanf(&quot;%d%d%d%d&quot;,&amp;cfx[i].llx,&amp;cfx[i].lly,&amp;cfx[i].urx,&amp;cfx[i].ury);
			x=max(x,cfx[i].urx);
			y=max(y,cfx[i].ury);
			color[cfx[i].c]++;
		}
		sort(cfx,cfx+n,cmp);
		color_rank[0]=color[1];
		color_rank[1]=color_rank[0]+color[2];
		color_rank[2]=color_rank[1]+color[4];

		DFS(0,0,x,y,n-1,0);

		printf(&quot;Case %d:\n&quot;,cnt++);
		for(i=0;i&lt;7;i++)
			printf(&quot;%I64d\n&quot;,ans[sx[i]]);
	}
    return 0;
}
[/code]