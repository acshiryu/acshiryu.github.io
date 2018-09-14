title: ZOJ 2562 More Divisors 反素数
tags:
  - zoj
  - 反素数
  - 素数
categories:
  - 算法竞赛
date: 2018-09-14 12:18:06
---

题目大意就是求N之内的最大反素数（一个正整数N满足在1..N 中,N有最多的约数，则它是一个反素数）；

根据反素数定义，可以得出反素数的两个性质
* 反素数可以表示成$2^{t_1} \times 3^{t_2} \times 5^{t_3}...$这样连续的素数的幂的乘积
* 若用上面的表示方法，一定有$t_1 \geq t_2 \geq t_3 \geq ...$

故可以根据这两个性质通过搜索可以很容易的找到反素数

{% include_code zoj 2562 More Divisors lang:cpp zoj/2562.cpp %}