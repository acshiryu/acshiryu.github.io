title: POJ1258 Agri-Net 解题报告
tags:
  - poj
  - prim
  - 图论
  - 生成树
categories:
  - 算法竞赛
date: 2018-09-16 10:11:00
---

题目给出了n个农场之间的距离，先要让这n个农场全部覆盖网络，求所用网线的最小长度，典型的最小生成树问题，比较简单，因为是稠密图，可直接用Prim算法解，我提交1次就A了，详情见代码.

{% include_code poj1258 Agri-Net lang:cpp poj/1258.cpp %}