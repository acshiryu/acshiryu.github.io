title: hdu4611 Balls Rearrangement gcd问题 2013多校2-1001
toc: true
tags:
  - hdu
  - gcd
  - 循环
  - 找规律
  - 数论
categories:
  - 算法竞赛
id: 1939
date: 2013-07-27 14:59:11
---

题目实际上就是求$$\sum_{i=0}^{n-1}\left | i \mod a-i \mod b \right |$$

既然有取余，明显会有循环节，很显然循环节是lcm(a,b)

那就求出循环节部分的值再乘以循环的次数再加上其余部分就可以了

多校的时候a,b都取的int，WA了  后来才弄对

{% include_code hdu4611 Balls Rearrangement lang:cpp hdu/4611.cpp %}