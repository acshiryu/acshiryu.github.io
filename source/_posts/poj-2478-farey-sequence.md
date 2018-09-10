title: poj2478 又一欧拉公式的运用
toc: true
tags:
  - 数学
  - 数论
  - 欧拉公式
categories:
  - 算法竞赛
id: 985
date: 2012-03-10 01:20:29
---

题目大意就是求Fi集合中元素的个数，其中Fi集合的元素满足下列条件

形如a/b，且0<a<b<=i, gcd(a,b)=1 

很明显，这题就是欧拉公式的运用，关于欧拉公式可查看下这篇文章

http://www.cnblogs.com/ACShiryu/archive/2011/08/04/poj2407.html

对于这题，可以先求出以每一个小于m的数为分母的数的个数，即也是与该数互素的数的个数，也就是求的phi[i]；

然后再每一个phi都加起来

题目就是比较简单的欧拉运用，1A

{% include_code poj2478 Farey Sequence lang:cpp poj/2478.cpp %}