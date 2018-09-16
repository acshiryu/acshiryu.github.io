title: poj1080 人类基因配对
tags:
  - poj
  - 动态规划
categories:
  - 算法竞赛
date: 2018-09-16 10:19:00
---

是就是求两基因的相似度，先要在每个基因对中加入若干空格，然后再依次加上匹配度，详见上表，则相似度就是最大的匹配度和

例如对于测试数据一，加上空格则变成

> AGTGAT--G
> -GT----TAG

则相似度就是$(-3)+5+5+(-2)+5+(-1)+5=14$，可以证明这是最大的，故为所求

此题为dp,详见代码

{% include_code poj1080 Human Gene Functions lang:cpp poj/1080.cpp %}