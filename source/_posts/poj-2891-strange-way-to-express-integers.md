title: poj 2891 Strange Way to Express Integers 扩展欧几里得
toc: true
tags:
  - poj
  - gcd
  - 扩展欧几里得
  - 欧几里得
categories:
  - 算法竞赛
id: 1457
date: 2012-01-01 01:44:00
---

题目大意就是给出a和r，求c,其中c mod ai = ri；这题就是扩展欧几里得的一个简单应用

首先我们可以假设c=a0*x+r0=a1*y+r1;则a0*x-a1*y=r1-r0;此时可以求出x，故可以求出c。

假设A=lcm(a0,a1),则A=a0*t1=a1*t1；那么可以推出C'=A*z+C=a0*t*z+a0*x+r0=a0*(t0*z+x)+r0=a1*(t1*z+y)+r1;故这时再将这两个式子合并写成C'=lcm(a0,a1)*z+C；再与接下来的ai和ri合并即可

{% include_code poj2891 Strange Way to Express Integers lang:cpp poj/2891.cpp %}