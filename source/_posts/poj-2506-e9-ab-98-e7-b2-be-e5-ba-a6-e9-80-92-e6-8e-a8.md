title: POJ 2506 高精度+递推
toc: true
tags:
  - 递推
  - 高精度
categories:
  - 算法竞赛
id: 992
date: 2012-03-10 01:23:10
---

题目大意就是有2×1和2×2两种规格的地板，现要拼2×n的形状，共有多少种情况，首先要做这道题目要先对递推有一定的了解。
假设我们已经铺好了2×（n-1）的情形，则要铺到2×n则只能用2×1的地板
假设我们已经铺好了2×（n-2）的情形，则要铺到2×n则可以选择1个2×2或两个2×1，故可能有下列三种铺法

![](http://pic002.cnblogs.com/images/2011/315754/2011080615045389.png)

![](http://pic002.cnblogs.com/images/2011/315754/2011080615051645.png)

![](http://pic002.cnblogs.com/images/2011/315754/2011080615052834.png)

其中要注意到第三个会与铺好2×（n-1）的情况重复，故不可取，故可以得到递推式

a[i]=2*a[i-2]+a[i-1];

然后就是高精度部分，可直接用高精度的模板

直接套用模板就1A了，只是简单的递推题，算是练习套模板能力或验证模板的正确性吧！

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;string&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 #include &lt;deque&gt;
 #include &lt;vector&gt;
 using namespace std;

 const int Base=1000000000;  
 const int Capacity=100;  
 typedef long long huge;    

 struct BigInt{  
      int Len;  
      int Data[Capacity];  
      BigInt() : Len(0) {}  
      BigInt (const BigInt &amp;V) : Len(V.Len) { memcpy (Data, V.Data, Len*sizeof*Data);}  
      BigInt(int V) : Len(0) {for(;V&gt;0;V/=Base) Data[Len++]=V%Base;}  
      BigInt &amp;operator=(const BigInt &amp;V) {Len=V.Len; memcpy(Data, V.Data, Len*sizeof*Data); return *this;}  
      int &amp;operator[] (int Index) {return Data[Index];}  
      int operator[] (int Index) const {return Data[Index];}  
 };

 BigInt operator+(const BigInt &amp;A,const BigInt &amp;B){  
      int i,Carry(0);  
      BigInt R;  
      for(i=0;i&lt;A.Len||i&lt;B.Len||Carry&gt;0;i++){  
          if(i&lt;A.Len) Carry+=A[i];  
          if(i&lt;B.Len) Carry+=B[i]; 
          R[i]=Carry%Base;  
          Carry/=Base;  
      }  
      R.Len=i;  
      return R;  
 }

 ostream &amp;operator&lt;&lt;(ostream &amp;Out,const BigInt &amp;V){  
      int i;  
      Out&lt;&lt;(V.Len==0 ? 0:V[V.Len-1]);  
      for(i=V.Len-2;i&gt;=0;i--) for(int j=Base/10;j&gt;0;j/=10) Out&lt;&lt;V[i]/j%10;  
      return Out;  
 }

 BigInt ans[300];

 int main()
 {
     ans[0]=1;
     ans[1]=1;
     int i;
     for ( i = 2  ; i &lt;= 250 ; i ++ )
     {
         ans[i]=ans[i-2]+ans[i-1]+ans[i-2];
     }
     int n ;
     while ( cin &gt;&gt; n )
         cout&lt;&lt;ans[n]&lt;&lt;endl;
     return 0;
 }[/code]