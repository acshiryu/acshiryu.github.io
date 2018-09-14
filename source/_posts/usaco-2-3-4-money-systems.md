title: USACO 2.3.4 Money Systems 解题报告
tags:
  - usaco
  - 动态规划
categories:
  - 算法竞赛
date: 2018-09-14 18:11:45
---

题目大意很简单，就是给出钱币系统，求能拼出V的情况总数

可以用DP求解，注意到 money [ j ] [ i ] += money [ j - k * sys [ i - 1 ] ] [ i - 1 ] ;

其中money [ j ] [ i ] 表示用前i种币拼出j的情况总数，明显题目要求的是money [ n ] [ v ]

{% include_code usaco 2.3.4 Money Systems lang:cpp usaco/2-3-4.cpp %}