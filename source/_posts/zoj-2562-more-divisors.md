title: ZOJ 2562 More Divisors 反素数
toc: true
tags:
  - zoj
  - 反素数
  - 素数
categories:
  - 算法竞赛
id: 1461
date: 2012-07-22 10:52:06
---

题目大意就是求N之内的最大反素数（一个正整数N满足在1..N 中,N有最多的约数，则它是一个反素数）；

根据反素数定义，可以得出反素数的两个性质

故可以根据这两个性质通过搜索可以很容易的找到反素数

{% include_code zoj 2562 More Divisors lang:cpp zoj/2562.cpp %}