title: "ZOJ月赛解题报告-ZOJ Monthly, February 2012(ZOJ3571-3580)"
tags:
 - zoj
 - 最大公约数
 - 数论
 - 数据结构
 - 矩阵
categories:
 - 算法竞赛
date: 2018-09-14 12:12:12
---
### A: Good Rectangle(zoj3571)
等待更新......

### B：Getting Meal(zoj3572)
等待更新......

### C：Under Attack(zoj3573)
C题可以说是本次比赛最简单的一题，题目大意是，每一个炸弹可以毁坏公路的一定区域，问投了多个炸弹后，从南到北和从北到南的公路上第一个毁坏最严重的是在哪一点。
例如，对于测试数据，在一个长10的公路，第一个炸弹，毁坏了公路的长从1到5的区域，毁坏程度是2，同理，第二个炸弹，毁坏了公路的长从6到9的区域，毁坏程度是2.所以，南到北和从北到南的公路上第一个毁坏最严重的点分别是1和9
没什么好说的，开一个适当大小的数组，我们可以对每一个炸弹的起点和终点分别加上毁坏程度和减少毁坏程度，这样，当炸弹全部投放完毕后，然后遍历这个数组，并用sumk求前面k的数组的和，则sumk就是第k个点的最后毁坏程度，详情看代码
<!--more-->
{% include_code zoj 3573 Under Attack lang:cpp zoj/3573.cpp %}

### D: Under Attack II(zoj3574)
{% post_link zoj-3574-under-attack-ii %}

### E: Under Attack III(zoj3575)
等待更新......

### F: Count the Length(zoj3576)
F题是一个找规律题目，可以多列几组数据进行查看。题目意思很简单，$n \ times m$个边长为1的正方形，排成$n \ times m$的矩形，其中左下角的是红色，然后红蓝交替摆放正方形，然后一条对角线横穿矩形的左下角和右上角，最后就对角线红色部分的总长度。
由于只想到找规律，所以只有多找几组数据进行测试。注意，对于数据4 6和2 3其实是一样的，所以可以将a,b约分后再探索。很容易发现当a=b时，红色占全部。当a和b中有且仅有一个是偶数时，则红色部分一直占用1/2。而当是1、3时红色部分是2/3，3、5时是8/15，5、7时是18/35，3、7时是11/21;这时很容易想到分母就是$a \ times b$,然后就是分子的规律，多亏convey提醒，向上取整，果然符合所有的数据，至于是为什么，本人不才，暂时还没有想到证明办法，如果有哪位ACMer愿意提供，那就在此多谢了。具体详见代码
{% include_code zoj 3576 Count the Length lang:cpp zoj/3576.cpp %}

### G: Max Damage Export(zoj3577)
等待更新......

### H: Matrix(zoj3578)
H题刚开始以为是二维的线段树或者是树状数组，但悲剧的是我连一维的都不会，更何况做二维，直接放弃。请教laputa大神，大神直接说和C题有点像Orz，讨论了一下，感觉就是C题的二维，然后，大神立刻去码代码，到码得差不多大神突然说题目看错了，Orz！到最后没兴趣了，直接不做了。
题目大意差不多就是定义了一个$n \times m$的0矩阵，然后定义了一组操作(a,b,h,x,y)，意思就是先求出子矩阵[(x,y)~(x+a,y+b)]的最大值max，然后对该子矩阵的每一个元素赋值为max+h，问，对于$n \ times m$的矩阵C步操作后，其中的元素最大值是多少
这题其实我也不会做，但看了一个日本人写的代码，再加上谷歌那渣的翻译，我竟然看懂了，Orz!原文地址:http://goo.gl/Cxafk
方法很简单，就是每一次判断两个矩阵是否相交，如果不相交就什么事都没有，如果相交的话，就比较两个矩阵的最大值，取最大的一个并加上h。最后遍历每个矩阵，求出max，也可以边比较变遍历，详细看代码。刚开始看的时候一直不明白相交后的操作，为什么只更新后一个矩阵而前一个相交的部分为什么不更新。想了半天，终于明白了。因为更新最后一个矩阵的值也同时把前一个矩阵相交部分也给更新了，只不过虽然在前一个矩阵中还是原来那个数，但最后还是要比较到大的那个矩阵，对结果没影响。
{% include_code zoj 3578 Matrix lang:cpp zoj/3578.cpp %}

### I: Gao the variable(zoj3579)
等待更新......

### J: Angry Birds(zoj3580)
等待更新......


