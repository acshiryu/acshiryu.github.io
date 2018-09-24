title: poj2478 又一欧拉公式的运用
tags:
  - poj
  - 数论
  - 欧拉函数
categories:
  - 算法竞赛
date: 2018-09-15 12:04:00
---

题目大意就是求Fi集合中元素的个数，其中Fi集合的元素满足下列条件

形如a/b，且0 < a < b <= i, gcd(a,b)=1 

很明显，这题就是欧拉公式的运用，关于欧拉公式可查看下这篇文章 {% post_link poj-2407-relatives %}

对于这题，可以先求出以每一个小于m的数为分母的数的个数，即也是与该数互素的数的个数，也就是求的phi[i]；

然后再每一个phi都加起来

题目就是比较简单的欧拉运用，1A

{% include_code poj2478 Farey Sequence lang:cpp poj/2478.cpp %}