title: 《算法竞赛入门经典训练指南》动态规划习题2
toc: true
tags:
  - 动态规划
  - 算法竞赛入门经典训练指南
categories:
  - 算法竞赛
id: 1002
date: 2017-01-02 00:00:00
---

# 动态规划习题(2)

## 划分成回文串（Partitioning by Palindromes, [Uva 11584](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2631 "11584 - Partitioning by Palindromes")）

简单动态规划，用dp[i]表示前i部分的划分情况。记录每个点j，以j为中点的回文串长度，然后dp[i]=min(dp[i-s-1]|其中a[i-s~i]为回文串)

{% include_code Uva 11584 Partitioning by Palindromes uva/11584.cpp %}
<!--more-->

## 商人（Salesmen, [LA 4256](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2257 "4256 - Salesmen")）

简单动态规划

{% include_code LA 4256 Salesmen la/4256.cpp %}

# 波浪子序列（Wavio Sequence, [Uva 10534](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1475 "10534 - Wavio Sequence")）

做两次最长上升子序列就可以了

{% include_code Uva 10534 Wavio Sequence uva/10534.cpp %}
