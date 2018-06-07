title: 《算法竞赛入门经典训练指南》思维的体操
toc: true
tags:
  - 算法竞赛入门经典训练指南
  - 贪心
  - 数论
categories:
  - 算法竞赛
id: 1009
date: 2017-01-09 00:00:00
---

# 思维的体操

## 例题1 勇者斗恶龙（The Dragon of Loowater，Uva 11292）

贪心水题

{% include_code Uva 11292 lang:cpp uva/11292.cpp %}

<!--more-->

## 例题2 突击战（Commando War，Uva 11729）

比较简单的贪心题

{% include_code Uva 11729 lang:cpp uva/11729.cpp %}

## 例题3 分金币（Spreading the Wealth，Uva 11300）

这题有点意思，初看起来不知道怎么下手，但可以发现一个人得到的金币来自于其两边的人，或者他只能将金币转手给旁边的人，于是我们就可以假设${A}_{i}$从${A}_{i-1}$处得到${x}_{i-1}$的金币，并转手给${A}_{i+1}$有${x}_{i}$的金币（注意是圆桌），于是就有${A}_{i}+{x}_{i-1}-{x}_{i}=average$，最后可以得出${x}_{i}$关于${x}_{1}$的表达式，依据题意，求的是$\sum_{1}^{n}|{x}_{i}|$的和，就可以借助数轴解决问题

{% include_code Uva 11300 lang:cpp uva/11300.cpp %}

## 例题4 墓地雕塑（Graveyard，LA3708，POJ3154）

比较简单的一题，算出每个点的初始位置和移动后的位置，每个点向最近的地方移动即可。lrj书上介绍的方法更巧妙

{% include_code poj 3154 lang:cpp poj/3154.cpp %}

## 例题5 蚂蚁（Piotr's Ants，Uva10881）

如果能注意到蚂蚁“碰撞”实际上是没有改变蚂蚁最终的位置，只是改变了蚂蚁的序号的话，那这题就很容易了

{% include_code Uva 10881 lang:cpp uva/10881.cpp %}

## 例题6 立方体成像（Image Is Everything，[LA2995](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996 "2995 - Image Is Everything")）

较麻烦的一道模拟题，看了lrj的白书后才过的，书上讲的较详细，此处略过

{% include_code LA 2995 lang:cpp la/2995.cpp %}