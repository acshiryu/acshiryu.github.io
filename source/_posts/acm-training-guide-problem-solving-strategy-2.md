title: 《算法竞赛入门经典训练指南》问题求解常见策略2
tags:
  - 算法竞赛入门经典训练指南
  - 深度优先搜索
  - 二分
categories:
  - 算法竞赛
date: 2018-09-16 11:08:00
---

# 问题求解常见策略(2)

## 例题12 组装电脑（Assemble，[LA3971](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1972 "3971 - Assemble")，[POJ3497](http://poj.org/problem?id=3497 "POJ3497 - Assemble")）

简单二分

{% include_code POJ 3497 - Assemble lang:cpp poj/3497.cpp %}

<!--more-->

## 例题13 派（Pie，[LA3635](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=19&problem=1636&mosmsg=Submission+received+with+ID+1264444 "3635 - Pie")，[POJ3211](http://poj.org/problem?id=3122 "POJ3122 - Pie")）

二分题，和上题类似，注意精度问题

{% include_code POJ 3211 - Pie lang:cpp poj/3211.cpp %}

## 例题14 填充正方形（Fill the Square，[Uva11520](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2515 "11520 - Fill the Square")）

水题

{% include_code Uva 11520 Fill the Square lang:cpp uva/11520.cpp %}

## 例题15 网络（Network，[LA3902](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1903 "3902 - Network")）

深搜的题，看着白书过的

{% include_code LA 3902 Network lang:cpp la/3902.cpp %}

## 例题16 长城守卫（Beijing Guards，[LA3177](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1178 "3177 - Beijing Guards")）

二分，当n为偶数时，很容易输出答案，唯一麻烦的就是n为基数的情况，详看白书

{% include_code LA 3177 Beijing Guards lang:cpp la/3177.cpp %}