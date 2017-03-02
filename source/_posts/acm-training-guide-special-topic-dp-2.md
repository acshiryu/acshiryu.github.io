title: 《算法竞赛入门经典训练指南》动态规划专题2
toc: true
tags:
  - 算法竞赛入门经典训练指南
  - 动态规划
  - 状态压缩
categories:
  - 算法竞赛
id: 1986
date: 2017-01-08 00:00:00
---

# 动态规划专题(2)

## 例题30 放置街灯（Placing Lampposts, [Uva 10859](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1800 "10859 - Placing Lampposts")）

动态规划，比较复杂的一题。通过这题，学到一个技巧

一般来说，如果题目要求两个量v1,v2，若要求满足v1最大或最小的时候，v2同事也要最大或最小。则可以把v1和v2合成一个量x=M*v1+v2.其中M要是比v2的理论值与v1理论值之差还要大的数,最后就求出v1=x/M，v2=x%M。因为要v1和v2同增或同减，则对于此题，M可取2000，v1为点灯数，v2为只被一盏灯照到的边的数。

解决此题，首先将无根树转换成有根树，用dp[i][j]来表示对于节点i父节点点灯状态为j时的最小x值，注意当i为根的时候的特殊情况，详细看代码

{% include_code Uva 10859 lang:cpp uva/10859.cpp %}

<!--more-->

## 例题31 捡垃圾的机器人（Robotruck, SWERC 2007, [LA 3983](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1984 "3983 - Robotruck")）

动态规划，设计的转移方程比较简单，用dp[i][j]表示捡到了第i个垃圾后重量为j时走了多少步，特别的dp[i][0]表示剪完1~i的垃圾并丢到垃圾箱走的步子数，则有两种绝策

(1)捡完第i-1个垃圾后继续捡第i个垃圾，则有方程：dp[i][j]=dp[i-1][j-lj[i].w]+juli(i-1,i)，特别的dp[i][0]=min(dp[i][j]+juli(i,0))

(2)捡完第i-1个垃圾并扔到垃圾桶里再捡第i个垃圾，则有方程：dp[i][lj[i].w]=dp[i-1][0]+juli(i,0)，特别的dp[i][0]=dp[i][lj[i].w]+juli(i,0)

时间和空间复杂度都是O(NC)，但利用滚动数组可以把空间复杂度降到O(C)

{% include_code LA 3983 lang:cpp la/3983.cpp %}

这题关于时间上的复杂度仍然可以继续优化，利用单调队列，可将复杂度降为$O(N)$，详细可参考《训练指南》第73页。

## 例题32 分享巧克力（Sharing Chocolate, World Finals 2010, [LA 4794](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2795 "4794 - Sharing Chocolate")）

状态DP，转移方程很好想到，但需要继续优化，可参考《训练指南》

{% include_code LA 4794 lang:cpp la/4794.cpp %}