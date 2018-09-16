title: hdu4301 Divide Chocolate 动态规划解题报告（多校1）
tags:
  - hdu
  - 动态规划
categories:
  - 算法竞赛
date: 2018-09-16 10:34:00
---

下面是官方的解题报告

题意：

给定一个$2n$的矩形，求把这个矩形分割为$k$部分的方法，且对称的切割方法视为不同，输出时模上$100000007$。

($1 \leq n \leq 1000,1 \leq k \leq 2n$)

解法：

看到这个题目，很容易想到DP。

状态表示 
> $f_{i0j}$ :前$i$行已经出现了$j$部分且第$i$行的两个格子属于同一部分的方法数
> $f_{i1j}$ :前$i$行已经出现了$j$部分且第$i$行的两个格子属于不同部分的方法数

初始条件 
> $f_{101} = f_{112} = 1$

状态转移,下面使用$I$表示$i+1$,$J$表示$j+1$,$jj$表示$j+2$

> $f_{I0j}=f_{I0j}+f_{i0j}+2f_{i1j}$
> $f_{I0J}=f_{I0J}+f_{i0j}+f_{i1j}$
> $f_{I1j}=f_{I1j}+f_{i1j}$
> $f_{I1J}=f_{I1J}+2f_{i0j}+2f_{i1j}$
> $f_{I1jj}=f_{I1jj}+f_{i0j}+f_{i1j}$

共12种不同的状态转移（见下图）

![](/assets/image/hdu/4301.jpg)

我的代码
{% include_code hdu4301 Divide Chocolate lang:cpp hdu/4301.cpp %}