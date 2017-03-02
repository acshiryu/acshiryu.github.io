title: 《算法竞赛入门经典训练指南》高效算法设计举例2
toc: true
tags:
  - 离散
  - 动态规划
  - 二分
  - 算法竞赛入门经典训练指南
categories:
  - 算法竞赛
id: 1964
date: 2017-01-04 00:00:00
---

# 高效算法设计举例(2)

## 例题21 子序列（Subsequence, SEERC 2006, [LA 2678](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=679 "2678 - Subsequence")）

简单题

{% include_code LA 2678 - Subsequence lang:cpp la/2678.cpp %}
<!--more-->

## 例题22 最大子矩阵（City Game, SEERC 2004, [LA 3029](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1030 "3029 - City Game")）

DP46题之一，算是DP系列的入门题

{% include_code LA 3029 - City Game lang:cpp la/3029.cpp %}

## 例题23 遥远的银河（Distant Galaxy, Shanghai 2006, [LA 3695](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696 "3695 - Distant Galaxy")）

和上一题(City Game)类似，但这题略复杂。明显每个点的坐标相差太大，第一步需要对坐标进行离散化，然后记录每一个点上面和左面点的个数，最后四个循环解决问题。

{% include_code LA 3695 - Distant Galaxy lang:cpp la/3695.cpp %}

## 例题24 废料堆（Garbage Heap, [UVa 10755](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696 "10755 - Garbage Heap")）

和前两题类似，这题只是将题目维度增加到三维，求立方体的最大价值和，做法差不多，详看白书及代码

{% include_code uva 10755 - Garbage Heap lang:cpp uva/10755.cpp %}

## 例题25 侏罗纪（Jurassic Remains, SEERC 2003, [POJ 1903](http://poj.org/problem?id=1903 "Jurassic Remains"), [LA 2965](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=966 "2965 - Jurassic Remains")）

最好想的办法是穷举，但复杂度是$O({2}^{n})$，有点大。这题就可以用中途相遇法，先求前$n/2$个字符串能得到的值，再求剩余字符串能得到的值，最后二分判断是否可以相遇

{% include_code poj 1903 - Jurassic Remains lang:cpp poj/1903.cpp %}