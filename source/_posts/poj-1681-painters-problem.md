title: "POJ1681 Painter's Problem 解题报告"
toc: true
tags:
  - poj
  - 位运算
  - 枚举
  - 高斯消元
categories:
  - 算法竞赛
id: 1429
date: 2012-01-01 01:23:00
---

题目意思很简单，很poj 1222其实是一模一样的，只是要会判断是否存在无解的情况，思路可参考[POJ1222EXTENDED LIGHTS OUT 解题报告](/archives/1427 "POJ1222EXTENDED LIGHTS OUT 解题报告")。可以位运算枚举，也可以高斯消元

{% include_code poj1681 Painter's Problem lang:cpp poj/1681.cpp %}