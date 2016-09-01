title: POJ 1797 Heavy Transportation 解题报告
toc: true
tags:
  - 图论
  - 并查集
  - 最短路
  - 生成树
categories:
  - 算法竞赛
id: 943
date: 2012-03-09 17:18:47
---

题目大意是就是何处一个图，n个顶点和m条边，每个边都有最大承载量，现在我要从1点运送货物到n点，求能运送货物的最大重量。

对于数据，第一行为t代表测试数据个数，第二行为n和m（意义见上），接着m行，每行三个整数分别是代表一条边的起点，终点及最大承重量。输出能运送货物的最大重量，格式见样例。注意数据输完后还要再多输一个空行。

对于数据，从1运到3有两种方案

*   方案1：1-2-3，其中1-2承重为3，2-3承重为5，则可以运送货物的最大重量是3（当大于3时明显1到不了2）
*   方案2：1-3，可知1-3承重为4，故此路可运送货物的最大重量是4，故答案输出4

因为此前也没做过图论题，对一些算法都不熟，再刚开始题意理解有问题，WA了几次，看懂题意后，搜了下别人的解题报告，说是Dijkstra的变形或这求最大生成树。也许对Dijkstra运用（压根就没用过）的不是很熟，一直不知道怎么下手，连样列都过不了。后就直接转到求最大生成树上去了，网上大部分代码是Prim算法，由于《算法入门竞赛经典》书没介绍该算法，暂时还没看，所以就选择Kruskal求最大生成树。然后选择Kruskal的一个问题就是连通分量的处理，《入门经典》是用的并查集来处理，因为对生成树算法不是很熟，就直接套的上面的模板。然后题目就是编程了求最大生成树，并找出从1-n的最小权值的边。当然，这棵树不用搜完，因为，你从1到n不一定会每一个节点都走过，当将1-n连通时此时的权值就是所求的值；转换用Kruskal时因为数组开大了MLE一次，开小了RE一次，最后决定还是动态分配靠谱些。不过因为一个小细节又WA了一次，最后改正，终于AC了，你说，AC一题我容易不！！！总之ACM搞图论的上辈子都是折翼的天使！！！

如果有时间，这题还会再做一遍的，用Prim算法和Dijkstra试一下！

[code lang="cpp"]
//第一次提交的代码基本是套模板的，和自己写的出入较大，不习惯，将代码修改下感觉也许更好！，第一次提交的代码见最下面
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 const int inf = (1&lt;&lt;20);
 int p[1005];        //p是用于并查集的，r是用来存储边序号的
 struct prog {
     int w,v,u;        //记录起点，终点，权值
 };
 bool cmp(prog a,prog b)
 {//间接排序函数，
     return a.w&gt;b.w;
 }
 int find(int x)
 {//并查集里的find函数，你懂的
     return p[x]==x?x:p[x]=find(p[x]);
 }
 int main()
 {
     int t;
     cin &gt;&gt; t;
     int k = 1;
     while(t--)
     {
         int n ,m;
         cin &gt;&gt; n &gt;&gt; m;
         prog *r;
         r=new prog[m];
         int i ;
         for ( i = 0 ; i &lt; m ; i ++ )
             cin&gt;&gt;r[i].u&gt;&gt;r[i].v&gt;&gt;r[i].w;    //输入边的信息

         for ( i =1 ; i &lt;= n; i ++ )
             p[i]=i;//初始化并查集

         sort(r,r+m,cmp);//根据边的权值的大小将边的序号进行排序，r[i]表示第i+1大的边存储在u，v，w数组中的序号
         int ans=inf;    //将答案初始化为最大值
         for ( i = 0 ; i &lt; m ; i ++ )
         {
             int x=find(r[i].u);
             int y=find(r[i].v);
             if(x!=y)
             {//如果该边所在的两边不在同一个连通分量里，则连接该边
                 if(ans&gt;r[i].w)//如果该边的权值比ans小（实际上一定不会比ans大），则更新ans
                     ans=r[i].w;
                 p[x]=y;//连接该边
                 if(find(1)==find(n))//当1和n连通时，则说明找到了一条从1到n的路，并且可知该路的所有边的权值都是最大的，故边的最小权值就是答案
                     break;
             }
         }
         //输出答案，格式如题所述
         cout&lt;&lt;&quot;Scenario #&quot;&lt;&lt;k&lt;&lt;&quot;:&quot;&lt;&lt;endl;
         cout&lt;&lt;ans&lt;&lt;endl&lt;&lt;endl;
         k++;
     }
     return 0;
 }
[/code]
　　附：第一次参考代码
[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 const int inf = (1&lt;&lt;20);
 int *p,*r;        //p是用于并查集的，r是用来存储边序号的
 int *u,*v,*w;    //分别代表边的起点，终点，和权值，明显不是我的风格，先熟悉下模板，不得不这样写
 bool cmp(const int a,const int b)
 {//间接排序函数，
     return w[a]&gt;w[b];
 }
 int find(int x)
 {//并查集里的find函数，你懂的
     return p[x]==x?x:p[x]=find(p[x]);
 }
 int main()
 {
     int t;
     cin &gt;&gt; t;
     int k = 1;
     while(t--)
     {
         int n ,m;
         cin &gt;&gt; n &gt;&gt; m;
         int i ;
         u=new int[m];
         v=new int[m];
         w=new int[m];
         r=new int[m];//动态分配
         for ( i = 0 ; i &lt; m ; i ++ )
         {
             int a , b , c ;
             cin&gt;&gt;a&gt;&gt;b&gt;&gt;c;
             u[i]=a;
             v[i]=b;
             w[i]=c;//加入边
         }
         p=new int[n+1];
         for ( i =1 ; i &lt;= n; i ++ )
             p[i]=i;//初始化并查集
         for ( i = 0 ;i &lt; m ; i ++ )
             r[i]=i;//初始化边序号
         sort(r,r+m,cmp);//根据边的权值的大小将边的序号进行排序，r[i]表示第i+1大的边存储在u，v，w数组中的序号
         int ans=inf;    //将答案初始化为最大值
         for ( i = 0 ; i &lt; m ; i ++ )
         {
             int e=r[i];//找到第i+1大的边
             int x=find(u[e]);
             int y=find(v[e]);
             if(x!=y)
             {//如果该边所在的两边不在同一个连通分量里，则连接该边
                 if(ans&gt;w[e])//如果该边的权值比ans小（实际上一定不会比ans大），则更新ans
                     ans=w[e];
                 p[x]=y;//连接该边
                 if(find(1)==find(n))//当1和n连通时，则说明找到了一条从1到n的路，并且可知该路的所有边的权值都是最大的，故边的最小权值就是答案
                     break;
             }
         }
         //输出答案，格式如题所述
         cout&lt;&lt;&quot;Scenario #&quot;&lt;&lt;k&lt;&lt;&quot;:&quot;&lt;&lt;endl;
         cout&lt;&lt;ans&lt;&lt;endl&lt;&lt;endl;
         k++;
     }
     return 0;
 }
[/code]