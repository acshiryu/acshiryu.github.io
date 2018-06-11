title: hdu2955 Robberies 教你怎样抢银行划算！
toc: true
tags:
  - hdu
  - DP
  - 动态规划
  - 背包问题
categories:
  - 算法竞赛
id: 998
date: 2012-03-10 23:53:37
---

题目大意是有n家银行，每家银行可抢mi的金钱，被抓的分险是pi，当你的分险和大于p时就会被抓，求你在不被抓的前提下怎样才能抢到最多的钱,这题，就是01背包的小数形式，我们可以用pi表示抢到i金币时的最大逃脱率

{% include_code hdu2955 Robberies lang:cpp hdu/2955.cpp %}