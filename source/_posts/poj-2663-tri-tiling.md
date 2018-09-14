title: poj2663 Tri Tiling 解题报告
tags:
  - poj
  - 数论
  - 递归
categories:
  - 算法竞赛
date: 2018-09-14 21:24:00
---

题目地址：[http://poj.org/problem?id=2663](http://poj.org/problem?id=2663 "Tri Tiling")

递推题，推导有点复杂，可能还有更好的办法吧，下面是我的想法

用$f_n$表示铺成$3 \times n$没铺满，还有一个空缺，$g_n$表示铺成$3 \times n$没铺满，有两个空缺，用$a_n$表示铺成$3 \times n$时全部铺满。

则很容易知道如果要铺成$a_n$，只需要$g_n$再加一块或者$f_{n-1}$再加两块，故$a_n=g_n+f_{n-1}$ 

同理，可知只要$f_{n-1}$再加一块就是$g_n$，而$f_n$则是只需要$a_{n-1}$再加一块或者$g_{n-1}$上加（需要点空间想像），综上，就可以推出递推公式了

{% include_code poj2663 Tri Tiling lang:cpp poj/2663.cpp %}