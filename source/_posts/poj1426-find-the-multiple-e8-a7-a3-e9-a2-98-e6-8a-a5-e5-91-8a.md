title: POJ1426 Find The Multiple 解题报告
toc: true
tags:
  - DFS
  - 搜索
  - 数学
categories:
  - 算法竞赛
id: 939
date: 2012-03-09 17:16:13
---

题目大意是给出一个数n，找出一个数要求是n的倍数，并且这个数的十进制只由1和0组成，明显这样的数不止一个（如果，满足条件一定会有m×10也满足，故不止一种），题目要求输出任意一个满足该条件的m

对于数据1，可知2×5=10，故答案可以得出是10（当然，100，1000...也满足，但是special judge，只用输出一个满足条件的解），其他数据也同理。
刚开始时被这题给吓住了，因为n最大200，以为最后的结果会非常大，但看了discuss后了解到64位无符号整数可以存下结果，过可以用深搜（刚开始用广搜+STL给MLE了，才改的深搜），如果搜到m则输出，否则搜索m×10和m×10+1直到得出答案

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 #include&lt;queue&gt;
 using namespace std;
 bool found;
 void DFS(unsigned __int64 t ,int n,int k)
 {
     if(found)
         return ;//如果已经发现了答案就没搜的必要了
     if(t%n==0)
     {//发现答案，输出，标记变量该true
         printf(&quot;%I64u\n&quot;,t);
         found=true;
         return ;
     }
     if(k==19)//到第19层，回溯
         return ;
     DFS(t*10,n,k+1);    //搜索×10
     DFS(t*10+1,n,k+1);    //搜索×10+1
 }
 int main()
 {
     int n;
     while(cin&gt;&gt;n,n)
     {
         found=false;//标记变量，当为true代表搜到了题意第一的m
         DFS(1,n,0);    //从1开始搜n的倍数，第三个参数代表搜的层数，当到第19层时返回（因为第20层64位整数存不下）
     }
     return 0;
 }
[/code]