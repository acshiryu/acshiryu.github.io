title: POJ1681 Painter's Problem 解题报告
tags:
  - poj
  - 位运算
  - 枚举
  - 高斯消元
categories:
  - 算法竞赛
date: 2018-09-16 10:02:00
---

题目意思很简单，很poj 1222其实是一模一样的，只是要会判断是否存在无解的情况，思路可参考{% post_link poj-1222-extended-lights-out %}。可以位运算枚举，也可以高斯消元

{% include_code poj1681 Painter's Problem lang:cpp poj/1681.cpp %}