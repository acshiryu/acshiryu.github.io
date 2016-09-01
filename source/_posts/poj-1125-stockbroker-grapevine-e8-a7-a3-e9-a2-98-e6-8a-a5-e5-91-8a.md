title: POJ 1125 Stockbroker Grapevine 解题报告
toc: true
tags:
  - Floyd
  - 图论
  - 最短路
categories:
  - 算法竞赛
id: 941
date: 2012-03-09 17:17:24
---

题目大意是股票经纪人要在一群人中散布一个谣言，而谣言只能在亲密的人中传递，题目各处了人与人之间的关系及传递谣言所用的时间，要求程序给出应以那个人为起点，可以在最短的时间内让所有的人都得知这个谣言。要注意从a到b传递的时间不一定等于从b到a的时间，如果没有方案能够让每一个人都知道谣言，则输出"disjoint"。（有关图的连通性，你懂得！但好像不用考虑这种情况一样能AC，只能说测试数据有点小水！）

题目数据的输入第一行为n，代表总人数，当n=0时结束程序，接着n行，第i+1行的第一个是一个整数t，表示第i个人与t个人的关系要好，接着有t对整数，每对的第一个数是j，表示i与j要好，第二个数是从i直接传递谣言到j所用的时间，数据的输出是两个整数，第一个为选点的散布谣言的起点，第二个整数时所有人得知谣言的最短时间

例如，对于数据1，可知如果从3开始传播，则1，2得知谣言的时间都是2，所用的时间比从1，2开始传播所用的时间要短，故程序的输出时3 2；

[code lang="cpp"]
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 const int inf = (1 &lt;&lt; 20);    //最大值
 int d[105][105];
 struct prog
 {
     int x,y,d;    //定义起点，终点，所用时间
 };
 int main()
 {
     int n;
     while(cin&gt;&gt;n,n)
     {
         int i,j;

         //先将路径初始化，让d[i][i]=0,d[i][j]=inf;i =/= j;
         for(i=0;i&lt;105;i++)
         {
             for(j=0;j&lt;105;j++)
             {
                 if(i==j)
                     d[i][j]=0;
                 else
                     d[i][j]=inf;
             }
         }

         //根据输入的数据构造路径，注意题目的起点和终点范围是1……N，而数组是从0开始的，故要把所给的节点-1
         for(i =0;i&lt;n;i++)
         {
             int m;    //从i出发亲密人的个数
             cin&gt;&gt;m;
             for ( j = 0 ; j &lt; m ; j ++)
             {
                 int a, b ;        //与i亲密的人及传递谣言的时间
                 cin&gt;&gt;a&gt;&gt;b;
                 d[i][a-1]=b;
             }
         }

         //Floyd算法，你懂的
         for ( int k = 0 ; k &lt; n ; k ++ )
         {
             for(i = 0 ; i &lt; n ; i ++)
             {
                 for ( j = 0 ; j &lt; n ; j ++ )
                 {
                     if(d[i][j]&gt;d[i][k]+d[k][j])
                         d[i][j]=d[i][k]+d[k][j];
                 }
             }
         }

         prog dij ,pij;//保存谣言散布的地点，终点，及时间，其中dij表示的是题目要求的，而pij表示的从固定点出发散布到某点的最长时间
         dij.d=inf;//初始时将时间初始化为最大（因为要求的是从任意点出发让所有人知道谣言的最短时间）
         for ( i = 0 ; i &lt; n ; i ++ )
         {
             pij.d=0;//将从i散布谣言所用的时间初始化为0（因为此处要求的是从i出发散布谣言的最大时间）
             for ( j = 0 ; j &lt; n ; j ++ )
             {
                 if(pij.d&lt;d[i][j])
                 {//如果找到从i到j所用的时间要长与目前找到的从i出发用时的时间，则更新pij
                     pij.d=d[i][j];
                     pij.x=i;
                     pij.y=j;
                 }

             }
             //如果从i出发用的时间比目前找到的用的最长时间还要短，则更新dij
             if(dij.d&gt;pij.d)
                 dij=pij;
         }
         if(dij.d&gt;=inf)//如果dij还一直是最大值，说明并不能让全部人得知谣言，则输出disjoint。但数据比较水，这个判断可省略 Orz
             cout&lt;&lt;&quot;disjoint&quot;&lt;&lt;endl;
         else//输出起点和时间，注意要将起点标号+1
             cout&lt;&lt;dij.x+1&lt;&lt;' '&lt;&lt;dij.d&lt;&lt;endl;
     }
     return 0;
 }
[/code]