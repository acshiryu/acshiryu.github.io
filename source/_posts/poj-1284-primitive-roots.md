title: poj1284 欧拉函数的运用
toc: true
tags:
  - Fermat
  - gcd
  - 数学
  - 数论
  - 欧拉函数
categories:
  - 算法竞赛
id: 990
date: 2012-03-10 01:22:29
---

题目大意就是给出一个奇素数，求出他的原根的个数,定义n的原根x满足条件0<x<n,并且有集合{ (xi mod n) | 1 <= i <=n-1 } 和集合{ 1, ..., n-1 }相等

关于这道题。如果知道欧拉函数的话，看出的答案是phi(n-1)其实也不难

`定理：如果p有原根，则它恰有φ(φ(p))个不同的原根，p为素数，当然φ(p)=p-1,因此就有φ(p-1)个原根`

关于证明我也不会，这些都是在Discuss里搜索到的，证明过程也算来自那吧！

对于给出的素数p,首先要明确一点：p的元根必然是存在的(这一点已由Euler证明，此处不再赘述)，因此，不妨设其中的一个元根是a0(1<=a0<=p-1)
按照题目的定义，a0^i(1<=i<=p-1) mod p的值是各不相同的，再由p是素数，联系Fermat小定理可知：q^(p-1) mod p=1;(1<=q<=p-1)(这个在下面有用)

下面证明,如果b是p的一个异于a的元根，不妨令b与a0^t关于p同余，那么必然有gcd(t,p-1)=1,亦即t与p-1互质;反之亦然;

证明：

若d=gcd(t,p-1)>1,令t=k1*d,p-1=k2*d,则由Fermat可知(a0^(k1*d))^k2 mod p=(a0^(k2*d))^(k1) mod p=(a0^(p-1))^(k1) mod p=1

再由b=a0^t (mod p)，结合上面的式子可知：(a0^(k1*d))^k2 mod n=b^k2 mod p=1;

然而b^0 mod p=1,所以b^0=b^k2 (mod p),所以b^i mod p的循环节=k2<p-1，因此这样的b不是元根；

再证，

若d=gcd(t,p-1)=1,即t与p-1互质，那么b必然是元根；

否则假设存在1<=j<i<=p-1，使得b^j=b^i (mod p),即a0^(j*t)=a0^(i*t) (mod p),由a0是元根，即a0的循环节长度是(p-1)可知，(p-1) | (i*t-j*t)->(p-1) | t*(i-j),由于p与t互质，所以(p-1) | (i-j),但是根据假设,0<i-j<p-1,得出矛盾，结论得证；

由上面的两个证明可知b=a0^t (mod p)，是一个元根的充要条件是t与p-1互质，所有的这些t的总个数就是Phi(p-1);具体参见http://poj.org/showmessage?message_id=158630

然后直接套用那个求欧拉函数的模板1A了，我发现我最近好喜欢套模板啊，没办法，知道的太少了

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int phi[66000];
 int main()
 {
     int i , j ;
     for ( i = 2 ; i &lt;=  65536 ; i ++ )
         phi[i]=0;
     phi[1]=1;
     for ( i = 2 ; i &lt;=  65536 ; i ++ )
         if ( !phi[i] )
         {
             for ( j = i ; j &lt;=  65536 ; j += i )
             {
                 if ( !phi[j] )
                     phi[j] = j ;
                 phi[j] = phi[j] / i * (i - 1 ) ;
             }
         }

     int n ;
     while ( cin &gt;&gt; n )
         cout&lt;&lt;phi[n-1]&lt;&lt;endl;

     return 0;
 }[/code]