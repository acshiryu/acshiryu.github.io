title: 欧拉函数模板
toc: true
tags:
  - 欧拉函数
  - 素数
  - 筛选
categories:
  - 模板编程
id: 1017
date: 2018-06-06 00:00:00
---

对正整数n，欧拉函数是少于或等于n的数中与n互质的数的数目。例如euler(8)=4，因为1,3,5,7均和8互质。

Euler函数表达通式：euler(x)=$x\sum_{1}^{n}\frac{1}{1-\frac{1}{p_i}}$,其中$p_1,p_2 …… p_n$为$x$的所有素因数，$x$是不为$0$的整数。euler(1)=1（唯一和1互质的数就是1本身）。 

欧拉公式的延伸：一个数的所有质因子之和是$\frac{n}{2}$euler(n)。

那么如何变成实现欧拉函数呢？下面通过两种不同的方法来实现。第一种方法是直接根据定义来实现，同时第一种方法也是第二种筛法的基础，当好好理解。

{% include_code 欧拉函数模板 lang:cpp template/euler-function.cpp %}

原文转载自：http://blog.csdn.net/once_hnu/article/details/6302868