title: USACO 2.2.2 Subset Sums解题报告
toc: true
tags:
  - DP
  - 记忆化搜索
  - 递推
categories:
  - 算法竞赛
id: 897
date: 2012-03-07 22:57:25
---

题目大意就是求讲数据1…N分成两组，使得两组中元素的和加起来相等，求这样分组的情况数

可以利用递推的方法求该题的解，注意：f(k,a)=(f(k-1,a+k)+f(k-1,a-k))/2；其中f(k,a)表示讲1…k元素分两组，使第一组比第二组多a；

因为k只可能分到第一组或第二组这两种情况，如果k加到第一组后使得第一组比第二组多a，则要原来的分组中第一组比第二组多a-k

同理如果k加到第二组后使得第一组比第二组多a，则要原来的分组中第一组比第二组多a+k。

因为交换两组元素后也满足条件，而只算一个解，故后面要除2；

很显然题目要求的是f（N，0）；

为节省递推时间，可使用记忆化搜索，考虑到数据不大，又a有正负之分，可加数组适当开大。

数据分析：N最大为39，32位整数可能存不下，故要使用64位扩展，故要将数据声明为long long .因为使用的是记忆化搜索，很大程度上减少了重复搜索的情况，时间复杂度为O（n^3），远优于O（2^n），不会超时.。

[code lang="cpp"]
/* 
 ID:shiryuw1 
 PROG:subset 
 LANG:G++ //64位整数要用long long
 */ 
 #include&lt;iostream&gt; 
 #include&lt;cstdlib&gt; 
 #include&lt;cstdio&gt; 
 #include&lt;cstring&gt; 
 #include&lt;algorithm&gt; 
 #include&lt;cmath&gt; 
 using namespace std; 
 int sum=0; 
 int n; 
 long long fid[40][2000]; //是否寻找过dp(k,a+1000),当为-1时为否
 long long dp(int k,int a) 
 { 
     if(k==0) 
     { //当为0时不合要求，故返回0
         return 0; 
     } 
     if(k==1) 
     { //当为1是可知只有可能两边的集合相差只能为1或-1
         if(abs(a)==1) 
             return 1; 当相差为1或-1时，则有一种情况符合
         return 0; 
     } 
     if(k==2) 
     { //理由同k=1时
         if(abs(a)==1||abs(a)==3) 
             return 1; 
         return 0; 
     } 
     if(fid[k][a+1000]==-1) //如果k,a没有访问过，则访问，并将访问结果存在该数组中，很明显该数组的结果不会再是-1否则直接返回fid[k][a+1000]，避免重复搜索。
         fid[k][a+1000]=dp(k-1,a+k)+dp(k-1,a-k); 
     return fid[k][a+1000]; 
 }

 int main() 
 { 
     freopen(&quot;subset.in&quot;,&quot;r&quot;,stdin); 
     freopen(&quot;subset.out&quot;,&quot;w&quot;,stdout); 
     cin&gt;&gt;n; 
     memset(fid,-1,sizeof(fid)); //初始化fid数组为-1
     printf(&quot;%lld\n&quot;,dp(n,0)/2); 寻找把1……N分成两组后使两组相差0的情况数
     return 0; 
 }
[/code]