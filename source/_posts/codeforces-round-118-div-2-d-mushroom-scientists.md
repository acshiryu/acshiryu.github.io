title: "Codeforces Round #118 (Div. 2) :D. Mushroom Scientists"
tags:
  - codeforces
  - 数论
categories:
  - 算法竞赛
date: 2018-09-16 11:00:00
---

题目就是给出$a,b,c$和$S$，求出一组非负数$x,y,z$ 使得$x+y+z=S$,并且要求${x^a}{y^b}{z^c}$最大
有公式，可以直接套用
但要注意$a=b=c=0$的情况，要特殊处理，否则当$x=\frac{Sa}{a+b+c}$ $y=\frac{Sb}{a+b+c}$ $z=\frac{Sc}{a+b+c}$时${x^a}{y^b}{z^c}$最大
可以证明，此处证明略，有兴趣的可以参考[这篇文章](http://www.science-mathematics.com/Mathematics/201110/16848.htm "Multi-Variable Optimization (Calc III) help!")
{% include_code D. Mushroom Scientists lang:cpp codeforces/118-div2-d.cpp %}