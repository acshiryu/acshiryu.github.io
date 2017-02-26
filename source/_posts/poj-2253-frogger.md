title: POJ 2253 Frogger 解题报告
toc: true
tags:
  - 图论
  - 最短路
  - 生成树
categories:
  - 算法竞赛
id: 945
date: 2012-03-09 17:19:40
---

题目大意，有两只青蛙，分别在两个石头上，青蛙A想要到青蛙B那儿去，他可以直接跳到B的石头上，也可以跳到其他石头上，再从其他石头跳到B那儿，求青蛙从A到B的所有路径中最小的Frog Distance，我们定义Frog Distance为从A到B的一条路径中所跳的最大距离，例如，如果从A到B某条路径跳的距离是2，5，6，4，则Frog Distance就是6，题目输入的第一行代表石头的个数，当个数为0时结束程序，接着有n行，其中第2，3行分别代表A，B青蛙的坐标，其他n-2行分别代表空的石头的坐标，输出一个小数（保留三位），具体格式参见样例，注意没输出一个答案还要再空一行。

题目数据1很明显为5.000

对于数据2青蛙有两种方案

*   方案1：1-2则经过距离为2.000故此时Frog Distance=2.000
*   方案2：1-3-2 则经过距离分别是1.414 1.414 故此时Frog Distance=1.414

故所求的最小的Frog Distance=1.414

这道题和POJ1797比较类似，那个是求最大生成树的最小权，这个是求最小生成树的最大权，哪题是用Kruskal+并查集做的，比较麻烦，则此从网上搜了小Prim算法，果然比较方面，开始时从图中取出点0（数组从0开始），入集合，然后搜索集合外的点到集合的距离，找出距离最小的点，入集合，重复该步骤，直到点1也进入了集合，则此时的权值就是所求的值。

刚开始输出没注意，WA了一次，这还是要提醒我们要小心注意题目的输入输出，别遗漏，确保万无一失才能交；

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 pair&lt;int ,int&gt; a[200];            //保存n个石头的坐标
 double lowcost[200],closet[200];//Prim算法必备，lowcost[i]表示i距离集合的最近距离，closet[i]表示i距离集合最近的点
 double map[200][200];            //两点之间的距离
 int main()
 {
     int n;
     int k=1;
     while(cin&gt;&gt;n,n)
     {
         int i,j;
         for (i = 0 ;i &lt; n ; i++ )
             cin&gt;&gt;a[i].first&gt;&gt;a[i].second;    //输入n个点的坐标，从0开始，也就是说题目编程求0-1的最小Frog Distance
         memset(lowcost,0,sizeof(lowcost));    //清零
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             for ( j = 0 ; j &lt; n ; j ++ )
             {//求任意两点的距离，保存到map中
                 map[i][j]=1.0*sqrt(pow(1.0*abs(a[i].first-a[j].first),2)+pow(1.0*abs(a[i].second-a[j].second),2));
             }
         }
         double ans=0.0;//所要求的答案，初始化为0
         for ( i = 0 ; i&lt; n ; i++ )
         {//把0放入集合，则点到集合的距离此时是点到0的距离
             lowcost[i]=map[0][i];
             closet[i]=0;
         }

         for ( i = 0 ; i &lt; n - 1 ; i ++ )
         {
             double mindis=1.0*(1&lt;&lt;20);        //点到集合最小距离，初始化为最大
             int minone;                        //到集合最小距离对应的点
             for ( j = 0 ; j &lt; n ; j ++ )
             {
                 if(lowcost[j]&amp;&amp;mindis&gt;lowcost[j])
                 {//j点不在集合中，并且j到集合的距离比最小距离还小，则更新最小距离
                     mindis=lowcost[j];
                     minone=j;
                 }
             }
             if(ans&lt;mindis)        //如果答案并不比更新的最小距离大
                 ans=mindis;        //更新答案
             lowcost[minone]=0.0;//将该点入集合
             if(minone==1)        //如果改点是1，则水明义江找到了答案
                 break;
             for ( j = 0 ; j &lt; n ; j ++ )
             {//更新各点到集合的最小距离
                 if(map[j][minone]&lt;lowcost[j])
                 {//如果minone到某点j的距离比原来的j到集合的距离要小，则更新该点到集合的距离为改点到minone的距离
                     lowcost[j]=map[j][minone];
                     closet[j]=minone;
                 }
             }
         }
         cout&lt;&lt;&quot;Scenario #&quot;&lt;&lt;k&lt;&lt;endl;
         printf(&quot;Frog Distance = %.3f\n\n&quot;,ans);
         k++;
     }
     return 0;
 }
[/code]