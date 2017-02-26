title: POJ3278 Catch That Cow 解题报告
toc: true
tags:
  - BFS
  - STL
  - 搜索
categories:
  - 算法竞赛
id: 933
date: 2012-03-09 17:10:52
---

题目大意，就是给出a和b点的横坐标，求到a，b的最小行动次数，其中每次行动只能是下面两种情况之一

*   向左或向右移动一步，即横坐标加1或者减1
*   横坐标变成原来的两倍
对于题目给出的数据5 17 ， 可以这样进行行动  5 -- 10 -- 9 -- 18 -- 17  所以只需要四步就可以到达b

这题因为是求最小行动次数，故可以用BFS，调用STL里面的队列来实现。每次去队首元素，如果到达了b点，输出步子并结束搜索，否则，行动步子+1，并分别将改点的横坐标+1，-1，×2操作后压入队列，一直到寻找到解。<font color="red">注意到当位置的横坐标超过了b点就应该再向右走，故此时应该对其横坐标只有-1操作，还要注意到横坐标为0的特殊情况，此处应该只进行+1行走</font>

刚开始的时候把标记数组开小了，没注意到×2可能会出现超过100,000的情况，提交时RE了一次，把数组改打就AC了
![](http://pic002.cnblogs.com/images/2011/315754/2011072317145432.png)

[code lang="cpp"]
#include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 #include&lt;queue&gt;
 using namespace std;
 bool hash[400001];    //标记改点是否走过，如果为true则走过
 int main()
 {
     int m , n ;
     while(cin&gt;&gt; n &gt;&gt; m )
     {
         memset(hash,false,sizeof(hash));//初始化
         pair&lt;int ,int&gt;p;                //第一个代表横坐标，第二个代表走的步子
         p.first=n;
         p.second=0;                        //初始化p
         hash[n]=true;
         queue&lt;pair&lt;int ,int&gt;&gt;bfs;
         bfs.push(p);
         while(!bfs.empty())
         {
             p=bfs.front();        //取队首元素

             if(p.first==m)
             {//此时说明找到了，则输出，并结束搜索
                 cout&lt;&lt;p.second&lt;&lt;endl;
                 break;
             }

             p.second++;                    //移动次数+1
             pair&lt;int ,int&gt;q;            

             if(p.first&lt;m)
             {//如果改点在目标点的左边
                 q=p;
                 q.first*=2;                //×2操作
                 if(hash[q.first]==false&amp;&amp;q.first)
                 {//点没访问过，则从改点开始继续搜索
                     hash[q.first]=true;
                     bfs.push(q);
                 }

             //下面搜索同上，注释略
                 q=p;
                 q.first+=1;                
                 if(hash[q.first]==false)
                 {
                     hash[q.first]=true;
                     bfs.push(q);
                 }

             }

             if(p.first&gt;0)
             {
                 q=p;
                 q.first--;
                 if(hash[q.first]==false)
                 {
                     hash[q.first]=true;
                     bfs.push(q);
                 }
             }
             bfs.pop();    //队首元素出队列
         }
     }
     return 0;
 }
[/code]