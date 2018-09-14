title: USACO 3.2.5 Magic Squares (BFS+康托展开)
tags:
  - usaco
  - 广度优先搜索
  - 康托展开
categories:
  - 算法竞赛
date: 2018-09-14 12:21:41
---

好久没写搜索，今天一写，好多问题。这题直接可以BFS做，但因为要保存的状态太多，直接用$10^8$的数组不行，但可以洗发现，$10^8$的数据中有很多都没有用到，实际要保存的只有$8!$，则可以考虑康托展开。把满足$1 \leq P < (n+1)!$的数写成$P=an!+b(n-1)!+......+x \times 1!$的形式。具体看代码

{% include_code usaco 3.2.5 Magic Squares lang:cpp usaco/3-2-5.cpp %}