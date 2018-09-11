title: "POJ2262Goldbach's Conjecture 简单的素数判定"
toc: true
tags:
  - poj
  - 枚举
  - 素数
categories:
  - 算法竞赛
id: 967
date: 2012-01-01 01:31:00
---

题目大意就是输入一个不小于6的合数，把它表示成两个质数的和，如果有多个，数出相差最大的一组

这题就是简单的枚举+素数判定，没什么技巧

行开始时分解合数时到sqrt（n）时停止，WA了一次，应该是n/2

{% include_code poj2262 Goldbach's Conjecture lang:cpp poj/2262.cpp %}