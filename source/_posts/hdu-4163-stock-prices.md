title: hdu4163 Stock Prices 解题报告
tags:
  - hdu
  - 排序
categories:
  - 算法竞赛
date: 2018-09-16 10:38:00
---

原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4163](http://acm.hdu.edu.cn/showproblem.php?pid=4163)

这题就是一个排序题，比较纠结。题目大意就是就是给出n个数，每个数对应着唯一的编号，就是他所处的序号，然后求出前k1小的元素对应的位置，升序输出，如果有相同的元素，选择和最小的，求出前k2大的元素对应的位置，升序输出，如果有相同的元素，选择和最大的。实际上就是一个稳定排序问题，可以用STL里的stable_sort，后续我会发一些关于STL模板库常用算法。详情看代码

{% include_code hdu4163 Stock Prices lang:cpp hdu/4163.cpp %}