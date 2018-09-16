title: 《算法竞赛入门经典训练指南》动态规划专题1
tags:
  - 算法竞赛入门经典训练指南
  - 动态规划
  - 递归
  - 状态压缩
categories:
  - 算法竞赛
date: 2018-09-16 11:07:00
---

# 动态规划专题(1)

## 例题26 约瑟夫环的变形（And Then There Was One, Japan 2007, [LA 3882](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1883 "3882 - And Then There Was One"), [POJ 3517](http://poj.org/problem?id=3517 "And Then There Was One")）

经典问题，递推解决

{% include_code poj 3517 lang:cpp poj/3517.cpp %}

## 例题27 王子和公主（Prince and Princess, [Uva 10635](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1576 "10635 - Prince and Princess")）

LCS问题，可转为LIS问题

{% include_code Uva 10635 lang:cpp uva/10635.cpp %}
<!--more-->

## 例题28 Sum游戏（Game of Sum, [Uva 10891](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1832 "10891 - Game of Sum")）

动态规划，用dp[i][j]表示第i~j个元素组成的子元素先手能拿的最大分，则后手能拿的最大分就是sum[i][j]-dp[i][j]

{% include_code Uva 10891 lang:cpp uva/10891.cpp %}

## 例题29 黑客的攻击（Hackers' Crackdown, [Uva 11825](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925 "11825 - Hackers")）

状态dp，用二进制表示状态。通过这题学习到原来枚举集合S的子集的一个好方法，详看代码

{% include_code Uva 11825 lang:cpp uva/11825.cpp %}