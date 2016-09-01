title: USACO3.2.5 Feed Ratios 解题报告
toc: true
tags:
  - 高斯消元
categories:
  - 算法竞赛
id: 1436
date: 2012-07-11 10:04:00
---

高斯消元，套模板即可，也可暴力枚举，只需要枚举100*100*100种情况，然后选取符合条件的解

[code lang="cpp"]
/*
ID:shiryuw1
PROG:ratios
LANG:C++
*/
#include &lt;algorithm&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
using namespace std;
const int maxn = 5;
int equ, var; // 有equ个方程，var个变元。增广阵行数为equ, 分别为到equ - 1，列数为var + 1，分别为到var.
int a[maxn][maxn];
int x[maxn]; // 解集.
bool free_x[maxn]; // 判断是否是不确定的变元.
int free_num;
void Debug()
{
    int i, j;
    for (i = 0; i &lt; equ; i++)
    {
        for (j = 0; j &lt; var + 1; j++)
        {
            cout &lt;&lt; a[i][j] &lt;&lt; &quot; &quot;;
        }
        cout &lt;&lt; endl;
    }
    cout &lt;&lt; endl;
}
inline int gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
inline int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，-1表示无解，表示唯一解，大于表示无穷解，并返回自由变元的个数)
int Gauss(void)
{
    int i, j, k;
    int max_r; // 当前这列绝对值最大的行.
	int col; // 当前处理的列.
    int ta, tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    // 转换为阶梯阵.
    col = 0; // 当前处理的列.
    for (k = 0; k &lt; equ &amp;&amp; col &lt; var; k++, col++)
    { // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r = k;
        for (i = k + 1; i &lt; equ; i++)
        {
            if (abs(a[i][col]) &gt; abs(a[max_r][col])) max_r = i;
        }
        if (max_r != k)
        { // 与第k行交换.
            for (j = k; j &lt; var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if (a[k][col] == 0)
        { // 说明该col列第k行以下全是了，则处理当前行的下一列.
            k--; continue;
        }
        for (i = k + 1; i &lt; equ; i++)
        { // 枚举要删去的行.
            if (a[i][col] != 0)
			{
                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                ta = LCM / abs(a[i][col]), tb = LCM / abs(a[k][col]);
                if (a[i][col] * a[k][col] &lt; 0) tb = -tb; // 异号的情况是两个数相加.
                for (j = col; j &lt; var + 1; j++)
                {
                    a[i][j] = a[i][j] * ta - a[k][j] * tb;
                }
			}
        }
    }
//    Debug();
    // 1\. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for (i = k; i &lt; equ; i++)
    { // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
        if (a[i][col] != 0) return -1;
    }
    // 2\. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if (k &lt; var)
    {
        // 首先，自由变元有var - k个，即不确定的变元至少有var - k个.
        for (i = k - 1; i &gt;= 0; i--)
        {
            // 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.
            // 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            free_x_num = 0; // 用于判断该行中的不确定的变元的个数，如果超过个，则无法求解，它们仍然为不确定的变元.
            for (j = 0; j &lt; var; j++)
            {
                if (a[i][j] != 0 &amp;&amp; free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num &gt; 1) continue; // 无法求解出确定的变元.
            // 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
            temp = a[i][var];
            for (j = 0; j &lt; var; j++)
            {
                if (a[i][j] != 0 &amp;&amp; j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index]; // 求出该变元.
            free_x[free_index] = 0; // 该变元是确定的.
        }
        return var - k; // 自由变元有var - k个.
    }
    // 3\. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for (i = var - 1; i &gt;= 0; i--)
    {
        temp = a[i][var];
        for (j = i + 1; j &lt; var; j++)
        {
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0) return -2; // 说明有浮点数解，但无整数解.
        x[i] = temp / a[i][i];
    }
	return 0;
}

int tmp[5][5];
int main()
{
  freopen(&quot;ratios.in&quot;,&quot;r&quot;,stdin);
  freopen(&quot;ratios.out&quot;,&quot;w&quot;,stdout);
	int xx,yy,zz;
	cin&gt;&gt;xx&gt;&gt;yy&gt;&gt;zz;
	equ=var=3;
	int i,j;
	for(i=0;i&lt;3;i++)
		for(j=0;j&lt;3;j++)
			cin&gt;&gt;tmp[j][i];

	for(i=1;i&lt;105;i++)
	{
		for(int k=0;k&lt;3;k++)
			for(j=0;j&lt;3;j++)
				a[j][k]=tmp[j][k];
		a[0][3]=i*xx;
		a[1][3]=i*yy;
		a[2][3]=i*zz;

/*		for(int ii(0);ii&lt;3;ii++)
		{
			for(int jj(0);jj&lt;4;jj++)
				cout&lt;&lt;a[ii][jj]&lt;&lt;' ';
			cout&lt;&lt;endl;
		}*/
		 free_num = Gauss();
		 if(free_num&gt;=0)
		 {

			 if(free_num==0)
			 {
				 if(x[0]&lt;0||x[1]&lt;0||x[2]&lt;0)
					 continue;
				 printf(&quot;%d %d %d %d\n&quot;,x[0],x[1],x[2],i);
			 }
			 else
			 {

				 if((!free_x[0]&amp;&amp;x[0]&lt;0)||(!free_x[1]&amp;&amp;x[1]&lt;0)||(!free_x[2]&amp;&amp;x[2]&lt;0))
					 continue;

				 for(j=0;j&lt;3;j++)
				 {
					 if(free_x[j])
						 printf(&quot;0 &quot;);
					 else
						 printf(&quot;%d &quot;,x[j]);
				 }
				 printf(&quot;%d\n&quot;,i);
			 }
			 break;
		 }
	}
	if(i==105)
		printf(&quot;NONE\n&quot;);
    return 0;
}
[/code]