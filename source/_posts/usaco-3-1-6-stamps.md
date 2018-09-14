title: USACO 3.1.6 Stamps（动态规划）解题报告
tags:
  - usaco
  - 动态规划
  - 背包
categories:
  - 算法竞赛
date: 2018-09-14 18:08:23
---

题目大意很简单，就是给出n中邮票的价值，求从 1 分开始连续的可用集合中不多于 K 张邮票贴出的邮资数。就是一个背包问题，

用dp[i]表示贴出价值为i的邮资所用的最少的邮票数，可得转移方程 dp[i]=max(dp[i-a[x]]+1,dp[i])  其中a[x]为给出的n张邮票中的一种

最后，就顺序遍历dp数组，找出中断点。没什么难度

{% include_code usaco 3.1.6 Stamps lang:cpp usaco/3-1-6.cpp %}