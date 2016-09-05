title: HDU4162 Shape Number 解题报告
toc: true
tags:
  - 串的最小表示
  - 后缀数组
  - 数据结构
  - 旋转
  - 暴力
  - 枚举
  - 题解
categories:
  - 算法竞赛
id: 830
date: 2012-03-03 09:12:17
---

<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4162](http://acm.hdu.edu.cn/showproblem.php?pid=4162)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;题目大意就是定义出方向如原题描述，单由于起点和旋转的不确定性，对于同一幅图有多种描述方法，为了统一，定义一种新的描述</font>
<font color="cc6666">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(1)以旋转方向为基础，每逆时针旋转45度，描述+1（也可以是之前描述的相邻位想减，若小于0则+8）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(2)然后对所有转换后的描述中选择一个值最小的描述作为他的唯一描述</font>
<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;第一步转换很简单，和上一题类似，详细看[HDU4161 Iterated Difference 解题报告](/archives/828 "HDU4161 Iterated Difference 解题报告")，但对于第二部，如果直接枚举每种情况，绝对超时。多亏ACM群的[cup] taozifish帮忙，原来是要用后缀数组做，不会，搜模板：串的最小表示模板，然后水过。以后有时间就把这个空缺补上，详细看代码</font>
[code lang="cpp"]
#include&lt;iostream&gt;
#include&lt;cstring&gt;
#include&lt;cstdio&gt;
using namespace std;
char s[300005];
int MinimumRepresentation(char *s, int l)  
{  
    int i = 0, j = 1, k = 0, t;  
    while(i &lt; l &amp;&amp; j &lt; l &amp;&amp; k &lt; l) {  
        t = s[(i + k) &gt;= l ? i + k - l : i + k] - s[(j + k) &gt;= l ? j + k - l : j + k];  
        if(!t) k++;  
        else{  
            if(t &gt; 0) i = i + k + 1;  
            else j = j + k + 1;  
            if(i == j) ++ j;  
            k = 0;  
        }  
    }  
    return (i &lt; j ? i : j);  
}  
int main()
{
	while(cin&gt;&gt;s)
	{
		char t=s[0];
		int i=strlen(s);
		s[i]=t;
		for(i=0;s[i+1];i++)
		{
			s[i]=s[i+1]-s[i]+'0';
			if(s[i]&lt;'0')
				s[i]+=8;
		}
		s[i]=0;
		int n=strlen(s);
		int k=MinimumRepresentation(s,n);
		for(i=k;i&lt;k+n;i++)
		{
			cout&lt;&lt;s[i%n];
		}
		cout&lt;&lt;endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}
[/code]