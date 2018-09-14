title: poj 2891 Strange Way to Express Integers 扩展欧几里得
tags:
  - poj
  - 最大公约数
  - 扩展欧几里得
  - 欧几里得
  - 数论
categories:
  - 算法竞赛
date: 2018-09-14 21:15:00
---

题目大意就是给出$a$和$r$，求$c$,其中$c \bmod a_i = r_i$ 这题就是扩展欧几里得的一个简单应用

首先我们可以假设$c=a_0x+r_0=a_1y+r_1$则$a_0x-a_1y=r_1-r_0$;此时可以求出$x$，故可以求出$c$。

假设$A= \mathrm{lcm} (a_0,a_1)$,则$A=a_0t_1=a_1t_1$；那么可以推出$C'=Az+C=a_0tz+a_0x+r_0=a_0(t_0z+x)+r_0=a_1(t_1z+y)+r_1$

故这时再将这两个式子合并写成$C'= \mathrm{lcm} (a_0,a_1)z+C$再与接下来的$a_i$和$r_i$合并即可

{% include_code poj2891 Strange Way to Express Integers lang:cpp poj/2891.cpp %}