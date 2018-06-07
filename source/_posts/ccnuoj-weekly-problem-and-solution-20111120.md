title: 20111120周赛解题报告
toc: true
tags:
  - 最大公约数
  - 数论
categories:
  - 算法竞赛
id: 1010
date: 2016-09-11 00:02:21
---

## Problem A: 不服气的数字

假设可以去的2数有k个

如果要求取得没有0,则答案为:$k^1+k^2+k^3+......+k^n$

如果要求取得数含有0,则答案为:$k+{(k-1)}k+(k-1)k^2+(k-1)k^3+...(k-1)k^{(n-1)}=k^n$（也可以看成k进制，直接得出答案）

{% include_code 不服气的数字参考代码 lang:cpp 20111120/A.cpp %}

&nbsp;

<!--more-->

## Problem B: 运动会

很明显,老师选人有三种情况

- 若$(M-K)>N/2$则只选男的，可组队数为$N/2$

- 若$(N-K)>2M$则只选女的，可组队数为$M$

- 其他情况则会男女搭配，那可组队数为$(M+N-K)/3$

那么很明显，最多可参加的组数是$min(N/2,M,(M+N-K)/3)$

{% include_code 运动会参考代码 lang:cpp 20111120/B.cpp %}

&nbsp;

## Problem C: 井底有一条蛇

明显 如果距离井口的距离小于A，则只需要1天，则明显答案是$\left\lfloor\frac{H-A}{A-B}\right\rfloor + 1$

{% include_code 井底有一条蛇参考代码 lang:cpp 20111120/C.cpp %}

&nbsp;

## Problem D: 话说实验室加了块白板

求最大 将所有的5或者6变成6

求最小 讲所有的5或者6变成5

然后atoi函数把字符串转化为数字

{% include_code 话说实验室加了块白板参考代码 lang:cpp 20111120/D.cpp %}

&nbsp;

## Problem E: 选卡片

假设小数部分是k  有n位  则答案显然是$\frac{10^n}{gcd(k,10^n)}$

注意不能用浮点数 有精度损失，用字符串代替小数的输入

{% include_code 选卡片参考代码 lang:cpp 20111120/E.cpp %}

&nbsp;

## 参考资料

比赛题目: [Problem.doc](/assets/code/20111120/Problem.doc)

比赛题解: [Solution.doc](/assets/code/20111120/Solution.doc)

## 讲题课件

简单数学题：[Mathematics.ppt](/assets/code/20111120/Mathematics.ppt)