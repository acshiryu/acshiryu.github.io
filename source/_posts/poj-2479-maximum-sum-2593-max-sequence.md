title: "poj2479与poj2593,同一道DP题"
toc: true
tags:
  - DP
  - 动态规划
  - 连续子串
categories:
  - 算法竞赛
id: 1005
date: 2012-03-10 23:56:37
---

这两道题的题目的题目大意如上，对于输入的n个数，求出最大的S,这是一个简单的DP题，开两个数组，DP[i][0],DP[i][1];,其中DP[i][0]表示的是从0～i中连续子串的最大和,DP[i][1]表示i～n-1中连续子串的最大和,则题目就变成求max{DP[i][0]+DP[i+1][1]}

参考代码：
poj2479
[code lang="cpp"]
 [/code]
　　poj2593
[code lang="cpp"]
[/code]