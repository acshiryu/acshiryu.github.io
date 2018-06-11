title: hdu2971 Tower 矩阵快速幂
toc: true
tags:
  - hdu
  - 快速幂
  - 矩阵
  - 递推
categories:
  - 算法竞赛
id: 1034
date: 2010-01-01 00:11:00
---

从题意中可得出两个递推关系：
![](/wp-content/uploads/2012/09/2971_13.png "2971_1")

要求Sn，显然这题是矩阵快速幂的问题，所以我们首先要将两个递推公式合并成一个只含有Sn递推的公式

显然，第二个式子含有平方项，所以，首先我们要将第一式平方并带入Sn中
![](/wp-content/uploads/2012/09/2971_2.png "2971_2")

这样就可以运用矩阵快速幂求Sn了

{% include_code hdu2971 Tower lang:cpp hdu/2971.cpp %}