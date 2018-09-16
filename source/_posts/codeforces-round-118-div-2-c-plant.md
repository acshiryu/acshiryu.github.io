title: "Codeforces Round #118 (Div. 2) :C. Plant"
tags:
  - codeforces
  - 矩阵快速幂
categories:
  - 算法竞赛
date: 2018-09-16 11:01:00
---

就是求第$n$个图形的上三角的个数
设$f_n$为第$n$个图形的上三角的个数  $g_n$为第$n$个图形的下三角的个数
那么$f_n = 3f_{n-1}+g_{n-1}$ 并且$g_n = 3g_{n-1}+f_{n-1}$
则可以构造矩阵 用矩阵快速幂解决
{% include_code C. Plant lang:cpp codeforces/118-div2-c.cpp %}
