title: POJ1258 Agri-Net 解题报告
toc: true
tags:
  - Prim
  - 图论
  - 生成树
categories:
  - 算法竞赛
id: 949
date: 2012-03-09 17:21:21
---

题目给出了n个农场之间的距离，先要让这n个农场全部覆盖网络，求所用网线的最小长度，典型的最小生成树问题，比较简单，因为是稠密图，可直接用Prim算法解，我提交1次就A了，详情见代码.

{% include_code poj1258 Agri-Net lang:cpp poj/1258.cpp %}