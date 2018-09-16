title: 《算法竞赛入门经典训练指南》问题求解常见策略1
tags:
  - 算法竞赛入门经典训练指南
  - 深度优先搜索
  - 递归
categories:
  - 算法竞赛
date: 2018-09-16 11:09:00
---

# 问题求解常见策略(1)

## 例题7 偶数矩阵（Even Parity，[Uva11464](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2459 "11464 - Even Parity")）

枚举题，只需要枚举处第一行的最终状态就可以推出其他行，然后在判断是否满足变换规则。最后找出最小变动量

{% include_code Uva11464 lang:cpp uva/11464.cpp %}

<!--more-->

## 例题8 彩色立方体（Colored Cubes，[LA3401](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1402 "3401 - Colored Cubes"),[POJ2741](http://poj.org/problem?id=2741 "POJ2741 - Colored Cubes")）

枚举题，枚举每个立方体的24种旋转，然后求出最小填涂方案。注意，第一个立方体就不必枚举了

{% include_code POJ2741 lang:cpp poj/2741.cpp %}

## 例题9 中国麻将（Chinese Mahjong，[Uva11210](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2151 "11210 - Chinese Mahjong")）

枚举题，先枚举出将，然后搜索对剩余的一张牌搜索出他的顺和刻

{% include_code Uva11210 lang:cpp uva/11210.cpp %}

## 例题10 正整数序列（Help is needed for Dexter，[Uva11384](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2379 "11384 - Help is needed for Dexter")）

终于不是枚举题了，比较简单的一道递推，公式f(n)=f(n/2)+1

{% include_code Uva11384 lang:cpp uva/11384.cpp %}

## 例题11 新汉诺塔问题（A Different Task，[Uva10795](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1736 "10795 - A Different Task")）

较复杂的一道递推题，方法还是和经典汉诺塔推理方法类似，详情还是看白书吧

{% include_code Uva10795 lang:cpp uva/10795.cpp %}