title: USACO3.1.5 Contact 解题报告
toc: true
tags:
  - STL
  - usaco
  - 字典树
categories:
  - 算法竞赛
id: 1397
date: 2012-05-10 20:52:28
---

USACO卡题有一段时间了，没想到今天连A三题，看来有进步了？？？？不过，马上要数据库考试了，美国奶牛3.2要暂停了

这题做好很简单，但是输入输出不好处理，输入我是通过
[code lang="cpp"]
while(~scanf(&quot;%s&quot;,s+strlen(s)));
[/code]
来处理的，但是在输出上wa了几次，主要是那个回车和空格的处理，还有输出六个的问题

这题可以用map来做，每次取出s中长度a~b的一段给map中，并计数+1,最后再排序，对排序的问题不怎么会用，我是再从考一个pair数组给解决的，C++的STL不是很熟，详看代码
[code lang="cpp"]

[/code]