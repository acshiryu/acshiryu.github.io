title: poj1088记忆化搜索
tags:
  - poj
  - 记忆化搜索
categories:
  - 算法竞赛
date: 2018-09-16 10:18:00
---

就是从各点进行搜索，并用以数组记录搜索的结果，一遍下次搜索该处时再用
然后遍历一下该数组，找到最大的一个元素

{% include_code poj1088 滑雪 lang:cpp poj/1088.cpp %}