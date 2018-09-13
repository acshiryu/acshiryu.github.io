title: USACO 3.2.3 Spinning Wheels
toc: true
tags:
  - usaco
  - 枚举
categories:
  - 算法竞赛
id: 1416
date: 2012-06-08 16:51:47
---

随便写的，估计明天我就会忘了每个函数的意思

简单枚举，明显每个齿轮的周期都有360  然后就枚举360秒  然后枚举360个角度，判断每一秒的每一个角度是否都有空缺，

{% include_code usaco 3.2.3 Spinning Wheels lang:cpp usaco/3-2-3.cpp %}