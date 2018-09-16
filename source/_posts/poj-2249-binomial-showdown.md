title: POJ2249--一道简单的排列组合题
tags:
  - poj
  - 排列
  - 数论
  - 组合数学
categories:
  - 算法竞赛
date: 2018-09-16 09:55:00
---

题目大意就是从n个数中取k个数的情况种数，就是求$C^k_n$；
刚开始时用递推，RE了几次，最后改成数组来，但有些细节没注意到，WA了几次，总的说来，这是一道比较简单的组合数学的基本功是的运用
排列组合的基本公式：
![](/assets/image/poj/2249-1.jpg)
Pascal公式
![](/assets/image/poj/2249-2.png)
和一些恒等式
![](/assets/image/poj/2249-3.png)

要解答出这道题主要运用的就是恒等式(1)

{% include_code poj2249 Binomial Showdown lang:cpp poj/2249.cpp %}