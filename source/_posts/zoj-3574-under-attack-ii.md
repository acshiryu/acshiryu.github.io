title: ZOJ3574 Under Attack II解题报告
toc: false
date: 2014-12-16 22:41:16
tags:
 - 矩形
 - 归并排序
 - 逆序对
categories:
 - 算法竞赛
---
原题地址：[ZOJ3574 Under Attack II](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=4596)
题目大意就是给出一个y无限的矩形区域，他的左边界在x=a,又边界x=b，求，现在给出n条直线，把这个矩形区域分成多少份？
很容易想到，每增加一条直线，若该直线与之前的直线在矩形内(不包括边界)有k个交点，则矩形增加的区域就是k+1，不知道为什么？我会在后续文章中介绍关于直线分割平面的相关推导。
但就算知道这，也还不行，如果直接两重循环，铁定TLE，我刚开始就是这样，然后彻彻底底被喵呜神给鄙视了！
![](/images/ZOJ4596-150x150.png)
其实，解决这题还有一个O(nlogn)的算法，我们可以这样看，假设，每一条边都已经固定在矩形上，然后，我们从矩形的左边开始看起，从下到上，映射到右边，如果在右边观看时，碰到有k个点(这些点对应的边一定要看过，也就是说对应左边的点要低)在上面，则说明该线段与前面的线段有k个交点。你也许不是很明白，看图，对应左边序号的123456，右边是246135，也就是说对于4号线，有1，3号线的左边低于4，右边高于4，则第4号线与前三条有两个交点，这不正是刚才要求的。现在转换成这样，是不是很熟悉，没错，求逆序对。逆序对的求法有多种，主要有归并排序，树状数组，如果不知道怎么做，可关注后续文章，会有关于求逆序对的总结。
我采用的是用用归并来求逆序对，详细也可参考刘汝佳的《算法入门竞赛经典》P144，那里介绍很详细，我也是直接拿着那的模板，详细看代码
<!--more-->
```c++
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct prog{
    int x,y;
}a[30005];
int t[30005];
bool cmp(prog a,prog b)
{
    return a.x<b.x;
}
int cnt;
void merge(int x,int y)
{
    if(y-x>1)
    {
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        merge(x,m);
        merge(m,y);
        while(p<m||q<y)
        {
            if(q>=y||(p<m&&a[p].y<=a[q].y))
            {
                t[i++]=a[p++].y;
            }
            else
            {
                t[i++]=a[q++].y;
                cnt+=m-p;
            }
        }
        for(i=x;i<y;i++)
            a[i].y=t[i];
    }
}
int main()
{
    int x,y;
    while(~scanf("%d%d",&x,&y))
    {
        int n;
        scanf("%d",&n);
        int i,j,k,b;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&k,&b);
            a[i].x=k*x+b;
            a[i].y=k*y+b;
        }
        sort(a,a+n,cmp);
        cnt=0;
        merge(0,n);
        cout<<n+cnt+1<<endl;
    }
    return 0;
```
		