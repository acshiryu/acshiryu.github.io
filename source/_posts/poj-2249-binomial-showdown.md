title: POJ2249--一道简单的排列组合题
toc: true
tags:
  - 排列
  - 数学
  - 组合
categories:
  - 算法竞赛
id: 971
date: 2012-03-10 01:13:17
---

题目大意就是从n个数中取k个数的情况种数，就是求C（n，k）；
刚开始时用递推，RE了几次，最后改成数组来，但有些细节没注意到，WA了几次，总的说来，这是一道比较简单的组合数学的基本功是的运用
排列组合的基本公式：
![](http://pic002.cnblogs.com/images/2011/315754/2011080511033233.jpg)
Pascal公式
![](http://pic002.cnblogs.com/images/2011/315754/2011080511105573.png)
和一些恒等式
![](http://pic002.cnblogs.com/images/2011/315754/2011080511121821.png)

要解答出这道题主要运用的就是恒等式（1）

[code lang="cpp"]
[/code]