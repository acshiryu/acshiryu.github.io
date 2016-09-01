title: USACO3.1.4 Shaping Regions 搜索+矩形切割
toc: true
tags:
  - DFS
  - 搜索
  - 矩形切割
categories:
  - 算法竞赛
id: 1367
date: 2012-05-10 14:00:43
---

好久没做USACO了，都是因为这题，矩形切割之前完全不会，但看了04年薛矛的论文《[解决动态统计问题的两把利刃——剖析线段树与矩形切割](/go.php?url=http://down.qiannao.com/space/file/ftyyl2009/share/2012/5/10/-859b-77db.pdf/.page   "解决动态统计问题的两把利刃 ——剖析线段树与矩形切割")》 顺利1A,关于矩形切割部分，他的论文讲的很仔细，推荐去看看

下面部分引用自薛矛的论文

矩形集合中已有矩形(x1,y1,x2,y2)，现加入矩形(x3,y3,x4,y4)。它们的位置关系可以有很多种（有17种之多），这里就不一一列举了。但无论它们的位置关系如何复杂，运用线段切割的思想来进行矩形切割，就会变得十分明了。我们将矩形的切割正交分解，先进行x方向上的切割，再进行y方向的切割。如下图所示：![矩形切割](/app/pic/archives/1367/1367.jpg)

插入矩形(x3,y3,x4,y4)后，对矩形(x1,y1,x2,y2)进行切割。

*   Step 1:首先从x方向上切。把线段(x1,x2)切成(x1,x3)，(x4,x2)两条线段。于是相应地，我们就把两个矩形切了出来——(x1,y1,x3,y2)，(x4,y1,x2,y2)。把它们加到矩形集合中。去掉了这两个矩形后，我们要切的矩形就变为(x3,y1,x4,y2)。
*   Step 2:接着我们再进行y方向上的切割。把线段(y1,y2)切成(y1,y3)。相应地又得到一个矩形(x3,y1,x4,y2)。把它放入矩形集合。
*   Step 3:剩下的矩形为(x3,y3,x4,y2)，这个矩形已经被矩形(x3,y3,x4,y4)覆盖了，因此直接把它删掉。
我们可以归纳出矩形切割的思想：

*   1、先对被切割矩形进行x方向上的切割。取(x1,x2)，(x3,x4)的交集(k1,k2)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;①若x1＜k1，则加入矩形(x1,y1,k1,y2)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;②若k2＜x2，则加入矩形(k2,y1,x2,y2)
*   2、再对切剩的矩形(k1,y1,k2,y2) 进行y 方向上的切割。取(y1,y2)，(y3,y4)的交集(k3,k4)
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;① 若y1＜k3，则加入矩形(k1,y1,k2,k3)

    	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;②若k4＜y2，则加入矩形(k1,k4,k2,y2)

*   3、把矩形(x1,y1,x2,y2)从矩形集合中删除。
切割过程的代码如下（PASCAL描述）：
[code lang="pascal"]
Procedure Cut(x1,y1,x2,y2,Direction)
Var k1,k2
	Begin
		Case Direction of
		1:Begin
			k1 ← Max(x1,x3) ｛计算线段(x1,x2)，(x3,x4)交集的左边界｝
			k2 ← Min(x2,x4) ｛计算线段(x1,x2)，(x3,x4)交集的右边界｝
			if x1&lt;k1 then Add(x1,y1,k1,y2)
			if k2&lt;x2 then Add(k2,y1,x2,y2)
			Cut(k1,y1,k2,y2,Direction+1)
		End
		2:Begin
			k1 ← Max(y1,y3)
			k2 ← Min(y2,y4)
			if y1&lt;k1 then Add(x1,y1,x2,k1)
			if k2&lt;y2 then Add(x1,k2,x2,y2)
		End
	End
End
[/code]
其中Add是加入矩形的过程。
<center>-----------------------------------------acshiryu.com专用切割线  引用结束-----------------------------------------</center>
我的代码
[code lang="cpp"]
/*
ID:shiryuw1
PROG:rect1
LANG:C++
*/
#include&lt;iostream&gt;
#include&lt;cstdlib&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
#include&lt;cmath&gt;
using namespace std;
int ans[2505]={0};
struct prog{
	int llx,lly,urx,ury,color;
}rect[1005];
int area;
void DFS(int lx,int ly,int rx,int ry,int t)
{
	if(t==0)
		return ;
	if(rect[t].llx&gt;=rx||rect[t].lly&gt;=ry||rect[t].urx&lt;=lx||rect[t].ury&lt;=ly)
	{
		DFS(lx,ly,rx,ry,t-1);
	}
	else
	{
		int k1,k2,k3,k4;
		k1=max(lx,rect[t].llx);
		k2=min(rx,rect[t].urx);
		if(lx&lt;k1)
			DFS(lx,ly,k1,ry,t-1);
		if(rx&gt;k2)
			DFS(k2,ly,rx,ry,t-1);

		k3=max(ly,rect[t].lly);
		k4=min(ry,rect[t].ury);
		if(ly&lt;k3)
			DFS(k1,ly,k2,k3,t-1);
		if(ry&gt;k4)
			DFS(k1,k4,k2,ry,t-1);
		//cout&lt;&lt;k1&lt;&lt;' '&lt;&lt;k2&lt;&lt;' '&lt;&lt;k3&lt;&lt;' '&lt;&lt;k4&lt;&lt;endl;
		ans[rect[t].color]+=abs(k2-k1)*abs(k4-k3);
		area-=abs(k2-k1)*abs(k4-k3);
	}

}
int main()
{
	freopen(&quot;rect1.in&quot;,&quot;r&quot;,stdin);
	freopen(&quot;rect1.out&quot;,&quot;w&quot;,stdout);
	int a,b,n;
	scanf(&quot;%d%d%d&quot;,&amp;a,&amp;b,&amp;n);
	int i,j;
	memset(ans,0,sizeof(ans));
	for(i=1;i&lt;=n;i++)
		scanf(&quot;%d%d%d%d%d&quot;,&amp;rect[i].llx,&amp;rect[i].lly,&amp;rect[i].urx,&amp;rect[i].ury,&amp;rect[i].color);
	area=a*b;
	DFS(0,0,a,b,n);
	ans[1]+=area;
	for(i=1;i&lt;2505;i++)
		if(ans[i])
			printf(&quot;%d %d\n&quot;,i,ans[i]);
	return 0;
}
[/code]