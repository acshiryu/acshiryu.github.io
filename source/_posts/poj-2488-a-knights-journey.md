title: POJ2488 A Knight's Journey 解题报告
tags:
  - poj
  - 深度优先搜索
  - 搜索
categories:
  - 算法竞赛
date: 2018-09-14 21:27:00
---

题目大意是给出一个规格小于8*8的棋盘，判断一个只能走“日”的骑士能否不重复的走遍整个棋盘，如果能，按字典序输出走的路径，否则输出“impossible”

这题是一道搜索题，可以用DFS直接解决。每次从左到右，从上到下进行搜索，并标记搜索过的地方；

{% include_code poj2488 Snakes lang:cpp poj/2488.cpp %}