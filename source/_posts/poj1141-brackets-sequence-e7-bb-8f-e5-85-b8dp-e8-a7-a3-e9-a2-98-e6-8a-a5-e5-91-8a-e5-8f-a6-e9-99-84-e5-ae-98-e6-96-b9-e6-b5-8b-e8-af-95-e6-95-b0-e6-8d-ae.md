title: poj1141 Brackets Sequence(经典DP) 解题报告另附官方测试数据
toc: true
tags:
  - DP
  - 字符串
  - 字符串匹配
categories:
  - 算法竞赛
id: 1330
date: 2012-05-03 22:20:06
---

好久没写解题报告了！
这题的意思很简单，lrj的《算法艺术和信息学竞赛》里动态规划篇的第一个例题。就是给出一个括号串，求出最小的一个规格串，使得括号串是规格串的字串，如果有多个，因为是Special Judge，只用写出一个。一个串属于规格串要求满足下列条件之一

这题一眼就可以看出是DP，因为根据定义，一个问题可以划分为更小的子问题，如果对dp比较熟的话，求加括号数的转移方程可以很容写出，关键是括号家的位置怎么处理记录。我事这样处理的：
另开一个数组，记录dp分成更小的子问题的过程，这个数组的值分两部分，xxxy，我们用个位数表示划分子问题的情况，如果y是-1，表示是去掉两边的括号，y是8表示分裂成两部分。而前面的xxx部分表示划分的区域，最后，开始递推，输出括号的位置。这题有一个trick，就是最后一组数据是空串，而用scanf读取字符串会wa。详细看代码和测试数据
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

char s[200];
int dp[200][200];
int ac[200][200];//记录放的位置  表示是xxxy  xxx表示参照点 y表示方的括号种类和具体方位 
				//  当y为-1时表示两边去括号  当为8时分开  党为0-3表示括号的种类  详看printto函数
char to[255];	//括号对应转换成整数  方便存储
void printto(int k)
{
	switch(k)
	{
	case 0:printf(&quot;)&quot;);break;
	case 1:printf(&quot;(&quot;);break;
	case 2:printf(&quot;]&quot;);break;
	case 3:printf(&quot;[&quot;);break;
	}
}
void print(int i,int j)
{
	if(j&lt;i)
		return ;
	if(ac[i][j]==-1)
	{//属于(S)或[S]类型    则先打印正括号 在打印S  最后打印反括号
		printf(&quot;%c&quot;,s[i]);
		print(i+1,j-1);
		printf(&quot;%c&quot;,s[j]);
		return ;
	}
	if(ac[i][j]%10==8)
	{//属于AB  分别打印AB
		print(i,ac[i][j]/10);
		print(ac[i][j]/10+1,j);
		return ;
	}

	//其他就属于(S ,[S ,S] ,S)类型  根据括号的位置打印
	if(ac[i][j]/10==i)
	{//属于(S ,[S 类型  先打印正反括号 再打印S
		if(to[s[i]]&lt;2)
			printf(&quot;()&quot;);
		else
			printf(&quot;[]&quot;);
		print(i+1,j);

	}
	else
	{//属于S] ,S)类型 先打印S 再打印正反括号
		print(i,j-1);
		if(to[s[j]]&lt;2)
			printf(&quot;()&quot;);
		else
			printf(&quot;[]&quot;);
	}
	return ;

}
int main()
{
	to['(']=0;to[')']=1;to['[']=2;to[']']=3;
	while(gets(s))
	{//因为测试数据中有空串  不能用scanf读取字符串，很多人就是wa在这里
		int i,j,k;
		int len=strlen(s);
		zero(dp);
		zero(ac);
		for(i=0;i&lt;len;i++)
		{//初始化
			dp[i][i]=1;
			ac[i][i]=i*10+to[s[i]];
		}
		for(j=1;j&lt;len;j++)
		{
			for(i=0;i+j&lt;len;i++)
			{
				if((to[s[i]]^to[s[i+j]])==1&amp;&amp;((to[s[i]]%2)==0))
				{//如果能够表示成（S）和[S]情况的话
					if(j!=1)
						dp[i][i+j]=dp[i+1][i+j-1];
					else
						dp[i][i+j]=0;
					ac[i][i+j]=-1;
				}
				else
				{
					//表示成(S或者[S  则需要在i位置补全为()S或者[]S
					dp[i][i+j]=dp[i+1][i+j]+1;
					ac[i][i+j]=(i)*10+to[s[i]];
					if(dp[i][i+j]&gt;dp[i][i+j-1]+1)
					{//表示成S)或者S]  则需要在i位置补全为S()或者S[]  ac记录最后一位的数字
						dp[i][i+j]=dp[i][i+j-1]+1;
						ac[i][i+j]=(i+j)*10+to[s[i+j]];
					}
				}
				//划分成A B 两部分向更小的部分递推  此时ac数组记录分开的位置
				for(k=i+1;k&lt;i+j-1;k++)
				{
					if(dp[i][i+j]&gt;dp[i][k]+dp[k+1][i+j])
					{
						dp[i][i+j]=dp[i][k]+dp[k+1][i+j];
						ac[i][i+j]=k*10+8;
					}
				}
			}
		}
		//打印结果
		print(0,len-1);
		printf(&quot;\n&quot;);
	}
    return 0;
}
[/code]

## <font color="red">另测试数据下载地址：</font>

[http://down.qiannao.com/space/file/ftyyl2009/share/2012/5/3/poj1141.zip/.page](/golinks.php?url=http://down.qiannao.com/space/file/ftyyl2009/share/2012/5/3/poj1141.zip/.page "poj测试数据")