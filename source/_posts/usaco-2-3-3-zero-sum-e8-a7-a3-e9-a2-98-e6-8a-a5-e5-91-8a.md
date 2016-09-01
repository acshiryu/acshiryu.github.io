title: USACO 2.3.3 Zero Sum 解题报告
toc: true
tags:
  - DFS
  - 搜索
  - 枚举
categories:
  - 算法竞赛
id: 910
date: 2012-03-08 23:25:53
---

题目意思很简单个，就是在序列1…N中每两个连续的数字间指定一个操作符（+、-或空格），使得最后的结果为0 输出这样的结果（有多个就按ASCII 码的顺序输出）

这题可以用DFS直接求解，通过在每两个连续的数间指定可能的运算符（按空格，+，-的顺序指定）。当运算到最后一个数时如果结果为0，则输出

[code lang="cpp"]
/* 
ID:shiryuw1 
PROG:zerosum 
LANG:C++ 
*/ 
#include&lt;iostream&gt; 
#include&lt;cstdlib&gt; 
#include&lt;cstdio&gt; 
#include&lt;cstring&gt; 
#include&lt;algorithm&gt; 
#include&lt;cmath&gt; 
using namespace std; 
int n; 
struct prog{ 
    char c[10]; 
    int pre; 
    int next; 
    char op; 
    int k; 
}; 
int add (int a,int b,char c) 
{ 
    switch(c) 
    { 
    case 0:return a;break; 
    case '+':return a+b;break; 
    case '-':return a-b;break; 
    } 
} 
void DFS(prog ans) 
{ 
    int i; 
    if(ans.k==n) 
    { 
        if(add(ans.pre,ans.next,ans.op)==0) 
        { 
            for(i=1;i&lt;=n;i++) 
            { 
                if(i!=1) 
                    cout&lt;&lt;ans.c[i]; 
                cout&lt;&lt;i; 
            } 
            cout&lt;&lt;endl; 
        } 
        return ; 
    } 
    ans.k++; 
    prog tmp; 
    if(ans.op==0) 
    { 
        tmp=ans; 
        tmp.c[tmp.k]=' '; 
        tmp.pre=tmp.pre*10+tmp.k; 
        DFS(tmp);

        tmp=ans; 
        tmp.c[tmp.k]='+'; 
        tmp.next=tmp.k; 
        tmp.op='+'; 
        DFS(tmp); 
        tmp=ans; 
        tmp.c[tmp.k]='-'; 
        tmp.next=tmp.k; 
        tmp.op='-'; 
        DFS(tmp); 
    } 
    else 
    { 
        tmp=ans; 
        tmp.c[tmp.k]=' '; 
        tmp.next=tmp.next*10+tmp.k; 
        DFS(tmp);

        tmp=ans; 
        tmp.c[tmp.k]='+'; 
        tmp.pre=add(tmp.pre,tmp.next,tmp.op); 
        tmp.next=tmp.k; 
        tmp.op='+'; 
        DFS(tmp);

        tmp=ans; 
        tmp.c[tmp.k]='-'; 
        tmp.pre=add(tmp.pre,tmp.next,tmp.op); 
        tmp.next=ans.k; 
        tmp.op='-'; 
        DFS(tmp); 
    } 
} 
int main() 
{ 
    freopen(&quot;zerosum.in&quot;,&quot;r&quot;,stdin); 
    freopen(&quot;zerosum.out&quot;,&quot;w&quot;,stdout); 
    cin&gt;&gt;n; 
    prog ans; 
    ans.k=1; 
    ans.pre=1; 
    ans.op=0; 
    ans.next=0; 
    ans.c[0]=0; 
    DFS(ans); 
    return 0; 
}
[/code]