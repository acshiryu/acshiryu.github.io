title: POJ2251 Dungeon Master 解题报告
tags:
  - poj
  - 广度优先搜索
  - 数据结构
  - 搜索
  - 队列
categories:
  - 算法竞赛
date: 2018-09-15 12:12:00
---

题目大意：这题是一个三维的迷宫题目，其中用`·`表示空地，`#`表示障碍物，`S`表示起点，`E`表示终点，求从起点到终点的最小移动次数，解法和二维的类似，只是在行动时除了东南西北移动外还多了上下。

对于题目给出数据的含义就是输入l，r，c，分别代表迷宫有l层，每层长宽分别是c，r。

对于数据一可以这样移动
(1,1,1)->(1,1,2)->(1,1,3)->(1,1,4)->(1,1,5)->(1,2,5)->(1,3,5)->(1,3,4)->(1,4,4)->(2,4,4)->(2,4,5)->(3,4,5)
共11步就可以到达终点 

对于数据二明显不能到达，则输出Trapped

这题用BFS解，每次去队首元素，如果是终点则输出结果移动的次数，否则，从该点开始分别向东南西北上下移动（如果可以走的话）并继续搜，如果到队列为空还没搜到解法，则说明无解。

{% include_code poj2251 Dungeon Master lang:cpp poj/2251.cpp %}