title: hdu4162 Shape Number 解题报告
toc: true
tags:
  - hdu
  - 后缀数组
  - 数据结构
  - 旋转
  - 枚举
categories:
  - 算法竞赛
id: 1036
date: 2010-01-01 00:13:00
---

<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;原题地址：[http://acm.hdu.edu.cn/showproblem.php?pid=4162](http://acm.hdu.edu.cn/showproblem.php?pid=4162)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;题目大意就是定义出方向如原题描述，单由于起点和旋转的不确定性，对于同一幅图有多种描述方法，为了统一，定义一种新的描述</font>
<font color="cc6666">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(1)以旋转方向为基础，每逆时针旋转45度，描述+1（也可以是之前描述的相邻位想减，若小于0则+8）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(2)然后对所有转换后的描述中选择一个值最小的描述作为他的唯一描述</font>
<font size=3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;第一步转换很简单，和上一题类似，详细看[HDU4161 Iterated Difference 解题报告](/archives/828 "HDU4161 Iterated Difference 解题报告")，但对于第二部，如果直接枚举每种情况，绝对超时。多亏ACM群的[cup] taozifish帮忙，原来是要用后缀数组做，不会，搜模板：串的最小表示模板，然后水过。以后有时间就把这个空缺补上，详细看代码</font>

{% include_code hdu4162 Shape Number lang:cpp hdu/4162.cpp %}