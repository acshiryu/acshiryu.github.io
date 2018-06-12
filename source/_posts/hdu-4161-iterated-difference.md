title: hdu4161 Iterated Difference 解题报告
toc: true
tags:
  - hdu
  - 枚举
categories:
  - 算法竞赛
id: 1035
date: 2010-01-01 00:12:00
---

原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4161](http://acm.hdu.edu.cn/showproblem.php?pid=4161)

题目大意就是给出一段序列，然后生成一段新的序列，使新序列的第i个元素是原序列第i+1个元素与第i个元素差的绝对值(最后一个是第一个与最后一个差的绝对值),问如此经过多少步，可以得到一个元素全部一样的序列，当然，当要的步骤大于1000时我们认为不可能得到这样的序列，输出not attained

解决办法很简单，就是枚举循环操作，对于每次生成的序列进行判断是否满足，详细看代码

{% include_code hdu4161 Iterated Difference lang:cpp hdu/4161.cpp %}