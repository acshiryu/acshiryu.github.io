title: POJ 2506 高精度+递推
tags:
  - poj
  - 递归
  - 高精度
categories:
  - 算法竞赛
date: 2018-09-14 21:25:00
---

题目大意就是有$2 \times 1$和$2 \times 2$两种规格的地板，现要拼$2 \times n$的形状，共有多少种情况，首先要做这道题目要先对递推有一定的了解。
假设我们已经铺好了$2 \times (n-1)$的情形，则要铺到$2 \times n$则只能用$2 \times 1$的地板
假设我们已经铺好了$2 \times (n-2)$的情形，则要铺到$2 \times n$则可以选择1个$2 \times 2$或两个$2 \times 1$，故可能有下列三种铺法

![](/assets/image/poj/2506-1.png) ![](/assets/image/poj/2506-2.png) ![](/assets/image/poj/2506-3.png)

其中要注意到第三个会与铺好$2 \times (n-1)$的情况重复，故不可取，故可以得到递推式$a_i=2a_{i-2}+a_{i-1}$

然后就是高精度部分，可直接用高精度的模板

直接套用模板就1A了，只是简单的递推题，算是练习套模板能力或验证模板的正确性吧！

{% include_code poj2506 Tiling lang:cpp poj/2506.cpp %}