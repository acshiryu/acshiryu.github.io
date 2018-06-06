title: "Codeforces Round #118 (Div. 2) :B. Growing Mushrooms"
toc: true
tags:
  - codeforces
categories:
  - 算法竞赛
id: 1012
date: 2016-09-15 21:45:32
---

水题，就是对每组的$max(\frac{at_1(100-k)}{100.0}+b{t_2},\frac{bt_1(100-k)}{100.0}+a{t_2})$排序，如果相等，再让序号排
{% include_code B. Growing Mushrooms lang:cpp codeforces/118-div2-b.cpp %}
