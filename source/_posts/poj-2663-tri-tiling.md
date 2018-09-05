title: poj2663 Tri Tiling 解题报告
toc: true
tags:
  - 数学
  - 递推
categories:
  - 算法竞赛
id: 1026
date: 2012-03-15 20:46:07
---

题目地址：[http://poj.org/problem?id=2663](http://poj.org/problem?id=2663 "Tri Tiling")

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;递推题，推导有点复杂，可能还有更好的办法吧，下面是我的想法
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;用f[n]表示铺成3*n没铺满，还有一个空缺，g[n]表示铺成3*n没铺满，有两个空缺，用a[n]表示铺成3*n时全部铺满。则很容易知道如果要铺成a[n]，只需要g[n]再加一块或者f[n-1]再加两块，故a[n]=g[n]+f[n-1]；同理，可知只要f[n-1]再加一块就是g[n]，而f[n]则是只需要a[n-1]再加一块或者g[n-1]上加。（需要点空间想像），综上，就可以推出递推公式了
[code lang="cpp"]

[/code]