title: USACO 2.3.2 Cow Pedigrees 解题报告
toc: true
tags:
  - DP
  - 二叉树
  - 动态规划
categories:
  - 算法竞赛
id: 908
date: 2012-03-08 23:24:30
---

题目意思很简单，就是给出N和K，找出满足只有N个节点，并且每个节点的度为0或2，深度为K的二叉树的总数。

很显然可以的得到这个公式 a[i+j+1][max(h1+h2)+1]+=a[i][h1]*a[j][h2];

四个循环就可以解决，求出a[N][K]；

但要注意a[i][h1]*a[j][h2]和a[j][h2]*a[i][h1]是一样的，所以我们不妨设i>=j，h1>=h2;

则可以解决问题

还要注意临界情况，当i=j或者h1=h2出现时

数据分许：时间复杂度为O（n^2*k^2）,题目还可发现当n为偶数时，题目的答案是0又题目中n和k的数据不是很大，每次循环都是加2，故应该不会超时

[code lang="cpp"]
 /* 
 ID:shiryuw1 
 PROG:nocows 
 LANG:C++ 
 */ 
 #include&lt;iostream&gt; 
 #include&lt;cstdlib&gt; 
 #include&lt;cstdio&gt; 
 #include&lt;cstring&gt; 
 #include&lt;algorithm&gt; 
 #include&lt;cmath&gt; 
 usingnamespace std; 
 int a[222][111]={0};//表示i个节点构造题目要求的深度为j的二叉树的个数
 int main() 
 { 
     freopen(&quot;nocows.in&quot;,&quot;r&quot;,stdin); 
     freopen(&quot;nocows.out&quot;,&quot;w&quot;,stdout); 
 int n,m; 
 int i,j,h1,h2; 
     cin&gt;&gt;n&gt;&gt;m; 
     a[1][1]=1; //1个节点构造深度为一的二叉树只有1中情况
 for(i=1;i&lt;=n;i+=2) 
 { //i代表左子树的节点数，故要小于n
 for(j=1;j&lt;=i&amp;&amp;i+j&lt;n;j+=2) 
         { // j代表右子树的节点数，故要i+j&lt;n
 //又由分析，左右可以交换，故规定j&lt;=i
 for(h1=1;h1&lt;m;h1++) 
             { //h1表示左子树的深度，可知;h1&lt;m
 for(h2=1;h2&lt;=h1;h2++) 
                 {  //h2表示右子树的深度，又左右可以交换，故规定;h2&lt;=h1
 int ii=i+j+1; //左右子树的节点加上根节点
 int h=h1+1;//由规定知h1&gt;=h2，故h=max{h1,h2}+1=h1+1
 if(i==j&amp;&amp;h1==h2) 
 //如果有i=j和h1=h2，则不能交换左右子树
                         a[ii][h]=((a[ii][h]+a[i][h1]*a[j][h2]))%9901; 
 elseif(h1==h2||i==j) 
 //当只有h1=h2或i=j时可以交换左右子树的节点数
                         a[ii][h]=(a[ii][h]+2*a[i][h1]*a[j][h2])%9901; 
 else 
 //否则既要交换i和j也要交换左右深度a[ii][h]=(a[ii][h]+2*a[i][h1]*a[j][h2]+2*a[i][h2]*a[j][h1])%9901; 
                 } 
             } 
         } 
     } 
     cout&lt;&lt;a[n][m]&lt;&lt;endl; //输出n个节点构造shendu为m的满足条件的二叉树个数
 return0; 
 }
[/code]