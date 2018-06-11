title: hdu4300 Clairewd’s message 多校第一场
toc: true
tags:
  - hdu
  - kmp
categories:
  - 算法竞赛
id: 1468
date: 2012-08-09 10:25:02
---

简单KMP，下面是官方题解

这道题问的就是将1个串如何变为stringA+stringB的形式，使得stringA是stringB经过映射得到相同的串。映射那步其实没有什么价值，假设str为原串s经过映射后得到的串，我们可以以str为模式串，以s为原串做一次扩展KMP，得到extend数组，extend[i]表示原串以第i开始与模式串的前缀的最长匹配。经过O(n)的枚举，我们可以得到,若extend[i]+i=len且i>=extend[i]时，表示stringB即为该点之前的串，stringA即为该点之前的str串，最后输出即可。

我的代码
{% include_code hdu4300 Clairewd’s message lang:cpp hdu/4300.cpp %}