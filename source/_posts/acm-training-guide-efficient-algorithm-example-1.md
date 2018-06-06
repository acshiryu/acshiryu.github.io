title: 《算法竞赛入门经典训练指南》高效算法设计举例1
toc: true
tags:
  - 排序
  - 计算几何
  - 贪心
  - 算法竞赛入门经典训练指南
categories:
  - 算法竞赛
id: 1003
date: 2017-01-03 00:00:00
---

# 高效算法设计举例(1)

## 例题17 年龄排序（Age Sort，[Uva11462](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2457 "11462 - Age Sort")）

计数排序

{% include_code Uva 11462 Age Sort lang:cpp uva/11462.cpp %}
<!--more-->

## 例题18 开放式学分制（Open Credit System，[Uva11078](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2019 "11078 - Open Credit System")）

简单贪心

{% include_code Uva 11078 Open Credit System lang:cpp uva/11078.cpp %}

## 例题19 计算器谜题（Calculator Conundrum，[Uva11549](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2544 "11549 - Calculator Conundrum")）

找循环节，输出寻找过程中出现最大的值。用STL来判断每个值是否出现过

关于判重，训练指南上有一个更巧妙的方法，空间复杂度瞬间降为O(1)，使用floyd判圈算法

{% include_code Uva 11549 Calculator Conundrum lang:cpp uva/11549.cpp %}

## 例题20 流星（Meteor，[LA3905](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1906 "3905 - Meteor")）

计算几何,代码和白书差不多

{% include_code LA 3905 Meteor lang:cpp la/3905.cpp %}