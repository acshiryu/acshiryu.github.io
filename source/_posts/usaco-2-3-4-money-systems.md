title: USACO 2.3.4 Money Systems 解题报告
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 914
date: 2012-03-08 23:28:45
---

题目大意很简单，就是给出钱币系统，求能拼出V的情况总数

可以用DP求解，注意到 money [ j ] [ i ] += money [ j - k * sys [ i - 1 ] ] [ i - 1 ] ;

其中money [ j ] [ i ] 表示用前i种币拼出j的情况总数，明显题目要求的是money [ n ] [ v ]

{% include_code usaco 2.3.4 Money Systems lang:cpp usaco/2-3-4.cpp %}