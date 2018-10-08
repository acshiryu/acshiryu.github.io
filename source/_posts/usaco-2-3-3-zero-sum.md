title: USACO 2.3.3 Zero Sum 解题报告
tags:
  - usaco
  - 深度优先搜索
  - 枚举
categories:
  - 算法竞赛
date: 2018-09-14 18:12:53
---

题目意思很简单个，就是在序列1…N中每两个连续的数字间指定一个操作符（+、-或空格），使得最后的结果为0 输出这样的结果（有多个就按ASCII 码的顺序输出）

这题可以用DFS直接求解，通过在每两个连续的数间指定可能的运算符（按空格，+，-的顺序指定）。当运算到最后一个数时如果结果为0，则输出

{% include_code usaco 2.3.3 Zero Sum lang:cpp usaco/2-3-3.cpp %}