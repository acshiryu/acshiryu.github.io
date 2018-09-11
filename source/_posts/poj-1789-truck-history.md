title: POJ 1789 Truck History 解题报告
toc: true
tags:
  - poj
  - Prim
  - 图论
  - 生成树
categories:
  - 算法竞赛
id: 947
date: 2012-01-01 01:24:00
---

题目大意是就是给出n个长度为7的字符串，每个字符串代表一个车，定义车的距离是两个字符串间不同字母的个数，题目要求的数不同的车的距离的最小值，即所求的就是最小生成树

关于数据的输入和输出详见样例，要注意输出完数据后还有个'.'，这题是一个稠密图，用Prim算法比较好，关于Prim算法详见：
http://www.nocow.cn/index.php/Prim%E7%AE%97%E6%B3%95

{% include_code poj1789 Truck History lang:cpp poj/1789.cpp %}