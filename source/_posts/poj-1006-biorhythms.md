title: poj1006 中国剩余定理
toc: true
tags:
  - 中国剩余定理
  - 数学
  - 数论
categories:
  - 算法竞赛
id: 981
date: 2012-03-10 01:18:52
---

很明显这题要求的是使等式 （x+d）= p mod 23 = e mod 28 = i mod 33 成立的最小的x，注意x不能为0

`有几组特殊数据供参考
24 29 34 0      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;    1
24 29 34 1      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     21252
24 29 34 2      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     21251
&nbsp;0 &nbsp; 0&nbsp;  0&nbsp;  0      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     21252`

关于中国剩余定理，我理解的也不是很好，直接套的模板

[code lang="cpp"]
#include &lt;iostream&gt;  
 using namespace std;  

 int Extended_Euclid(int a,int b,int &amp;x,int &amp;y)    //扩展欧几里得算法  
 {  
     int d;  
     if(b==0)  
     {  
         x=1;y=0;  
         return a;  
     }  
     d=Extended_Euclid(b,a%b,y,x);  
     y-=a/b*x;  
     return d;  
 }  

 int Chinese_Remainder(int a[],int w[],int len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数  
 {  
     int i,d,x,y,m,n,ret;  
     ret=0;  
     n=1;  
     for (i=0;i&lt;len;i++)  
         n*=w[i];  
     for (i=0;i&lt;len;i++)  
     {  
         m=n/w[i];  
         d=Extended_Euclid(w[i],m,x,y);  
         ret=(ret+y*m*a[i])%n;  
     }  
     return (n+ret%n)%n;  
 }  

 int main()  
 {  
     int n;  
     int w[3],a[]={23,28,33};
     int k = 1;
     while (~scanf(&quot;%d%d%d%d&quot;,&amp;w[0],&amp;w[1],&amp;w[2],&amp;n))     
     {  
         if ( w[0]==-1&amp;&amp;w[1]==-1&amp;&amp;w[2]==-1&amp;&amp;n==-1)
             break;
         int t = Chinese_Remainder(w,a,3) - n ;    //引用中国剩余定理
         t=t % ( 23 * 28 * 33 ) ;
         if ( t &lt;= 0 )
             t += 23 * 28 * 33 ;
         printf(&quot;Case %d: the next triple peak occurs in &quot;,k) ;
         printf(&quot;%d days.\n&quot;,t);  
         k++;
     }  
     return 0;  
 }[/code]