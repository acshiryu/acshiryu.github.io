title: 从poj2356来体会 抽屉原理 的妙用
tags:
  - poj
  - 抽屉原理
  - 数论
categories:
  - 算法竞赛
date: 2018-09-15 12:09:00
---

题目大意就是先给出一个数N，接着再给出N个数，要你从这N个数中任意选择1个或多个数，使得其和是N的倍数

如果找不到这样的答案 则输出0

答案可能有多个，但智勇任意输出一个解就行。

输出的第一行是选择元素的个数M，接着M行分别是选择的元素的值

刚开始的时候并不同为什么这一题回事抽屉原理，分析后才明白，昨晚后更有体会

实际上此题一定有解，不存在输出0的结果

证明如下

> 我们可以依次求出a[0],a[0]+a[1],a[0]+a[1]+a[2],......,a[0]+a[1]+a[2]...+a[n]；
> 假设分别是sum[0],sum[1],sum[2],......,sum[n]
> 如果在某一项存在是N的倍数，则很好解，即可直接从第一项开始直接输出答案
> 但如果不存在，则sum[i]%N的值必定在[1,N-1]之间，又由于有n项sum，有抽屉原理：
>
>  > 把多于n个的物体放到n个抽屉里，则至少有一个抽屉里有2个或2个以上的物体。
>  > 则必定有一对i，j，使得sum[i]=sum[j]，其中i！=j，不妨设j>i
>
> 则（sum[j]-sum[i]）%N=0，故sum[j]-sum[i]是N的倍数

则只要输出从i+1～j的所有的a的值就是答案

然后就利用这个思路就可以直接的解出该题的答案

刚开始时是因为第一次做这题，代码写的过长，实际上第一种情况和第二种情况可以算一种情况考虑，关于简化后的的代码可以参考 {% post_link poj-3370-halloween-treats %}

{% include_code poj2356 Find a multiple lang:cpp poj/2356.cpp %}