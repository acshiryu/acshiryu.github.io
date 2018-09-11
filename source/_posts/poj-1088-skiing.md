title: poj1088记忆化搜索
toc: true
tags:
  - poj
  - 记忆化搜索
categories:
  - 算法竞赛
id: 1000
date: 2012-01-01 01:06:00
---

就是从各点进行搜索，并用以数组记录搜索的结果，一遍下次搜索该处时再用
然后遍历一下该数组，找到最大的一个元素

{% include_code poj1088 滑雪 lang:cpp poj/1088.cpp %}