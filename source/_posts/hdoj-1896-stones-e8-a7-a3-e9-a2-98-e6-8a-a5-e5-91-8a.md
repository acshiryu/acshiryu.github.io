title: HDOJ 1896 Stones 解题报告
toc: true
tags:
  - STL
  - 优先队列
categories:
  - 算法竞赛
id: 921
date: 2012-03-08 23:35:00
---

题目大意是路上有很多石头，当你遇到奇数序列的石头就把他向前仍，偶数的不动他，如果两个石头一起，先考虑可以仍的比较近的石头仍也就是比较大的石头，这样一直下去，直到前面所有的石头都不可以仍了为止，求最远的石头距离起点多少题目这题用优先队列非常方便.

分析；可以定义一个结构体，分别存储石头现在的位置和能能出去的距离到优先队列中，然后每次取“最小的”，如果取得是偶数个就不动，取得是奇数个就要更新该石头的位置并重新存到优先队列中，直到队列空，输出最后一个石头的位置

数据分析：程序的时间复杂度是O（nlogn）,数据量最大为100,000，不会超时。要特别注意多个石头的x一样的情况,要优先考虑y值最小的那块石头

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 #include&lt;queue&gt;
 using namespace std;
 struct Stone{
     int x;    //石头的初始地
     int y;    //石头能扔的最远距离
 };
 bool operator&lt;( Stone a, Stone b )
 { //重载小于，按照结构体中x小的在队顶，如果x一样，则按照y的最小的在//队顶
     if( a.x== b.x ) return a.y &gt; b.y;  
     return a.x &gt; b.x;   
 }  
 int main()
 {
     int t;
     scanf(&quot;%d&quot;,&amp;t);//测试数据个数
     while(t--)
     {
         int n;
         int i ;
         priority_queue&lt;Stone&gt;que;     //定义一个Stone成员的优先//队列
         scanf(&quot;%d&quot;,&amp;n);
         Stone tmp;
         for(i =0;i&lt; n ; i++ )
         {
             scanf(&quot;%d%d&quot;,&amp;tmp.x,&amp;tmp.y);
             que.push(tmp);//入队
         }
         int sum =1;//判断碰到的是第几个石头的标记
         while(!que.empty())//当队列为空就跳出循环，也就是说再//向前就没有石头可以遇到
         {
         tmp = que.top();//去队顶元素，也就是在后面的所有//石头中第一个碰到的石头
             que.pop();//出对
             if(sum%2)
             {//如果是奇数号石头，则处理，否则不做处理
                 tmp . x+=tmp.y;//则向前扔y单位长度
                 que.push(tmp);//扔出去的石头入队
             }
             sum++;//石头计数+1
         }
         printf(&quot;%d\n&quot;,tmp.x);//打印最后一块石头的坐标就是所求//的最远距离
     }
     return 0;
 }[/code]