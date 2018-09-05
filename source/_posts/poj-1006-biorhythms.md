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

{% include_code poj1006 Biorhythms lang:cpp poj/1006.cpp %}