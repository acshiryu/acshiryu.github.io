title: USACO 2.3.2 Cow Pedigrees 解题报告
tags:
  - usaco
  - 二叉树
  - 动态规划
categories:
  - 算法竞赛
date: 2018-09-14 18:13:30
---

题目意思很简单，就是给出N和K，找出满足只有N个节点，并且每个节点的度为0或2，深度为K的二叉树的总数。

很显然可以的得到这个公式 a[i+j+1][max(h1+h2)+1]+=a[i][h1]*a[j][h2];

四个循环就可以解决，求出a[N][K]；

但要注意a[i][h1] X a[j][h2]和a[j][h2] X a[i][h1]是一样的，所以我们不妨设i >= j，h1 >= h2;

则可以解决问题

还要注意临界情况，当i=j或者h1=h2出现时

数据分许：时间复杂度为O（n^2*k^2）,题目还可发现当n为偶数时，题目的答案是0又题目中n和k的数据不是很大，每次循环都是加2，故应该不会超时

{% include_code usaco 2.3.2 Cow Pedigrees lang:cpp usaco/2-3-2.cpp %}