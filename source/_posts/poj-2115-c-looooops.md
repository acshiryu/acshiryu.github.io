title: poj2115 同余方程与扩展欧几里得
tags:
  - poj
  - 中国剩余定理
  - 同余方程
  - 扩展欧几里得
categories:
  - 算法竞赛
date: 2018-09-16 09:58:00
---

题目意思给出A,B,C，问对于C语句语句
```c++
for (variable = A; variable != B; variable += C)
  statement;
```

循环的次数，如果是死循环，就输出FOREVER 。其中数据都在$2^k$内，且都为非负数,也就是说当数据大于$2^k$时就要对$2^k$取模

这题题目意思很好理解，细细观察发现假设循环执行了$t$次，则会有 $(A + Ct ) = B \bmod 2 ^ k$ 题目就是要求的最小的非负数$t$ 。

对于同余方程的解法，可以参考http://www.cnblogs.com/ACShiryu/archive/2011/08/03/2126676.html

题目数据虽然都是32位，但在中间算的时候有可能超int 故要用__int64 刚开始没注意到，WA了2次，有一次是对1左移时没强制转换。

{% include_code poj2115 C Looooops lang:cpp poj/2115.cpp %}