title: HDU4165 Pills 解题报告
toc: true
tags:
  - 卡特兰数
  - 数学
  - 数论
  - 比赛
  - 组合数学
  - 递推
  - 题解
categories:
  - 算法竞赛
id: 833
date: 2012-03-03 09:20:37
---

<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4161](http://acm.hdu.edu.cn/showproblem.php?pid=4161)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;题目大意是什么意思，还不是很明白，好像是每次从一个瓶子里取药，可以取全部，也可以取一半，如果取到的药是完整的，就把它分成两半，吃掉其中的一半，另一半重新放入瓶中，如果取到半粒药，则直接吃掉，现在有n粒药，要2n天内吃完，问有多少种吃药方法
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;不知道题目是不是理解对的，看了很久无想法，然后，laputa大神发消息过来说他A了，虽然他也没看懂题，Orz，原来这题是一个裸的卡特兰数（也译为卡塔兰数），关于该数不做过多介绍，详细可以看[<font color="cc0000">维基百科</font>](http://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0 "卡塔兰数 - 维基百科"),还说自己是搞数学的，给了这么多的测试数据都没看出猫腻，唉！然后向他要了模板，直接套用，AC了，不愧是大神！Orz！</font>
[code lang="cpp"]
#include&lt;iostream&gt;
using namespace std;
#define MAX 100
#define BASE 10000
void multiply(int a[],int Max,int b) 
{
	int i,array=0;
	for (i = Max-1; i &gt;= 0; i--)
	{
		array += b * a[i];
		a[i] = array % BASE;
		array /= BASE;
	}
}
void divide(int a[], int Max, int b) 
{
	int i, div = 0;
	for (i = 0; i &lt; Max; i++)
	{
		div = div * BASE + a[i];
		a[i] = div / b;
		div %= b;
	}
}
int main()
{
	int a[101][MAX],i, n;
	memset(a[1],0,MAX*sizeof(int));
	for (i=2, a[1][MAX-1] = 1; i &lt; 101; i++) 
        {
		memcpy(a[i], a[i-1], MAX * sizeof(int));
		multiply(a[i], MAX, 4 * i - 2);
		divide(a[i], MAX, i + 1);
	}
	while (cin &gt;&gt; n)
	{
		if(n==0) return 0;
		for (i = 0; i &lt; MAX &amp;&amp; a[n][i] == 0; i++);
			cout &lt;&lt; a[n][i++];
		for (; i &lt; MAX; i++)   
               {
			printf(&quot;%04d&quot;,a[n][i]);
		}
		cout &lt;&lt; endl;
	}
	return 0;
}
[/code]