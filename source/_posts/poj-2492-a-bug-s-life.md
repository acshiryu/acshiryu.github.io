title: poj 2492 并查集
toc: true
tags:
  - 并查集
  - 数据结构
categories:
  - 算法竞赛
id: 1013
date: 2012-03-11 00:03:40
---

题目有点怪，就是告诉你有n只虫子，m条信息，每一条信息的i和j有JQ，求出根据所给的信息能否判断出有搞基的虫子，并按照题目要求信息输出这题用并查集解决起来很方便，当然搜索也可以解

首先分析第一组数据，则可知1和2异性，2和3也异性，可是1和3竟然也有JQ ，这是怎么回事？只能说他们在搞基，则输出Suspicious bugs found!

然后就是这题的处理办法，首先应该想到的是并查集，对于每一对有JQ的虫子，可以将他们分入到两个不同的并查集中，并记录跟这只虫子有JQ的虫子如果加入后存在冲突，则说明有搞基的虫子，没办法，这样就可以不用再考虑以后的虫子JQ了。

上面是大体思路，但有些小细节要考虑

如果那两只虫子之前都没有对象，都是处虫，则更新他们的对象信息；

如果只有其中的一个有对象，假设是a，而b没对象，则将b的对象更新为a，并且让a的对象和b同性，也就是入同一个并查集；

如果a和b都有对象，则有两种情况：

*   a和b在同一个并查集里，则说明a和b有JQ，则可以不必考虑后面的虫子了；
*   否则，将a和b之前的对象入同一个并查集，b和a之前的对象入同一个并查集；

这就是解这题我的思路，虽不是最优！

开始时因为很久没写并查集了，竟然写错了，WA了一个，然后就是对a和b都有对象的情况考虑不完整，也WA了一次，修正后果然AC了！

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 int pre[2005];    //并查集常用
 int com[2005];    //保存i的对象
 int find(int x)
 {//并查集的find
     return pre[x]==x?x:pre[x]=find(pre[x]);
 }
 void join(int x , int y)
 {//并查集的join
     int px=find(x);
     int py=find(y);
     if(px!=py)
         pre[px]=py;
 }
 int main()
 {
     int t ;
     scanf(&quot;%d&quot;,&amp;t);
     int cas=1;
     while (t--)
     {
         int n , m ;
         scanf(&quot;%d%d&quot;,&amp;n,&amp;m);
         int i ;
         for (i=0;i&lt;2005;i++)
         {//pre初始化
             pre[i]=i;
         }
         memset(com,-1,sizeof(com));

         bool found = false;        //判断是否找到搞基的虫子
         for(i=0;i&lt;m;i++)
         {
             int a,b;
             scanf(&quot;%d%d&quot;,&amp;a,&amp;b);
             if(found)            //如果找到搞基的虫子，则不用考虑后面了
                 continue;
             if (com[a]!=-1)
             {//如果a有对象
                 if(com[b]!=-1)
                 {//b也有对象
                     if (find(a)==find(b))
                     {//并且a和b也在同一个并查集，则a和b在搞基
                         found=true;
                     }
                     //否则，将a和b之前的对象入同一个并查集，b和a之前的对象入同一个并查集
                     join(a,com[b]);
                     join(b,com[a]);
                     continue;
                 }

                 //b没对象，则将b的对象更新为a，并且让a的对象和b同性，也就是入同一个并查集
                 join(com[a],b);
                 com[b]=a;
             } 
             else
             {//a没对象
                 if(com[b]!=-1)
                 {//b有对象，则将a的对象更新为b，并且让b的对象和a同性，也就是入同一个并查集
                     join(a,com[b]);
                     com[a]=b;
                 }
                 else
                 {//a和b都没对象，则更新他们的对象信息
                     com[a]=b;
                     com[b]=a;
                 }
             }
         }
         printf(&quot;Scenario #%d:\n&quot;,cas++);
         if (found)
         {
             printf(&quot;Suspicious bugs found!\n&quot;);
         } 
         else
         {
             printf(&quot;No suspicious bugs found!\n&quot;);
         }
         printf(&quot;\n&quot;);
     }
     return 0;
 }[/code]