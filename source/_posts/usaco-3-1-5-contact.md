title: USACO 3.1.5 Contact 解题报告
tags:
  - usaco
  - 字典树
categories:
  - 算法竞赛
date: 2018-09-14 18:09:28
---

USACO卡题有一段时间了，没想到今天连A三题，看来有进步了？？？？不过，马上要数据库考试了，美国奶牛3.2要暂停了

这题做好很简单，但是输入输出不好处理，输入我是通过
```c++
while(~scanf("%s" , s+strlen(s)));
```
来处理的，但是在输出上wa了几次，主要是那个回车和空格的处理，还有输出六个的问题

这题可以用map来做，每次取出s中长度a~b的一段给map中，并计数+1,最后再排序，对排序的问题不怎么会用，我是再从考一个pair数组给解决的，C++的STL不是很熟，详看代码
{% include_code usaco 3.1.5 Contact lang:cpp usaco/3-1-5.cpp %}