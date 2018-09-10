title: poj1191棋盘分割(动态规划)
toc: true
tags:
  - DP
  - 动态规划
categories:
  - 算法竞赛
id: 1338
date: 2012-05-05 15:26:12
---

黑书上面动态规划篇的第二道例题，题目大意很简单，可以记忆化搜索或dp做。最近在训练dp，直接dp做了，但记忆化搜索更简单。黑书上面的动态规划转移方程也写得很简单，用五层for循环嵌套。我的方程和他的略有不同，但大体意思是一样的！
`dp[k x1 y1 x2 y2]=min{
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dp[k-1 x1 y1 a y2]+dp[0 a+1 y1 x2 y2] , dp[k-1 a+1 y1 x2 y2]+dp[0 x1 y1 a y2] ,  （x1≤a﹤x2）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dp[k-1 x1 y1 x2 a]+dp[0 x1 a+1 x2 y2] , dp[k-1 x1 a+1 x2 y2]+dp[0 x1 y1 x2 a] ,  （y1≤a﹤y2）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;};`
然后就是5个嵌套的for循环，这题还有一个问题，不知道为什么，我之前用int和__int64都wa了，改成long double才ac了，难道卡在精度上？

{% include_code poj1191 棋盘分割 lang:cpp poj/1191.cpp %}