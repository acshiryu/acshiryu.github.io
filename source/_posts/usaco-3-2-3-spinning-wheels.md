title: USACO 3.2.3 Spinning Wheels
toc: false
tags:
  - usaco
  - 枚举
categories:
  - 算法竞赛
date: 2018-09-14 12:23:47
---

随便写的，估计明天我就会忘了每个函数的意思

简单枚举，明显每个齿轮的周期都有360  然后就枚举360秒  然后枚举360个角度，判断每一秒的每一个角度是否都有空缺，

{% include_code usaco 3.2.3 Spinning Wheels lang:cpp usaco/3-2-3.cpp %}