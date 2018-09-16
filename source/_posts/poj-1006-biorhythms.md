title: poj1006 中国剩余定理
tags:
  - poj
  - 中国剩余定理
  - 数论
categories:
  - 算法竞赛
date: 2018-09-16 10:24:00
---

很明显这题要求的是使等式 $x + d = p \bmod 23 = e \bmod 28 = i \bmod 33$ 成立的最小的x，注意x不能为0

注意，有几组特殊数据供参考
 - 24 29 34 0 1
 - 24 29 34 1 21252
 - 24 29 34 2 21251
 - 0 0  0  0 21252

关于中国剩余定理，我理解的也不是很好，直接套的模板

{% include_code poj1006 Biorhythms lang:cpp poj/1006.cpp %}