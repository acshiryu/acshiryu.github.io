title: USACO 2.2.4 Party Lamps 解题报告
toc: true
tags:
  - 找规律
  - 搜索
  - 枚举
categories:
  - 算法竞赛
id: 903
date: 2012-03-07 23:04:37
---

题目大意就是给出灯的个数，和对灯的操作规则，和经过C步操作后亮着的部分灯和熄灭的部分灯，求灯最后的可能情况，如果没有输出`IMPOSSIBLE'

*   按钮1：当按下此按钮，将改变所有的灯：本来亮着的灯就熄灭，本来是关着的灯被点亮。
*   按钮2：当按下此按钮，将改变所有奇数号的灯。
*   按钮3：当按下此按钮，将改变所有偶数号的灯。
*   按钮4：当按下此按钮，将改变所有序号是3*K+1(K&gt;=0)的灯。例如：1,4,7...
注意到当每对一个操作实施两次和没实施效果一样，故可将大于4的C减小到3或4；

然后从开始进行搜索没一盏灯进行一步操作后的可能情况，知道进行了C步操作，如果满足题目条件则保存数据再搜索下一组情况
[code lang="cpp"]
#include&lt;iostream&gt; 
#include&lt;cstdlib&gt; 
#include&lt;cstdio&gt; 
#include&lt;cstring&gt; 
#include&lt;algorithm&gt; 
#include&lt;cmath&gt; 
using namespace std; 
int op[105]; 
int cl[105]; 
int n; 
int c; 
int clk=0; 
int opk=0; 
bool found=false; 
struct prog{ 
    int a1; 
    int a2; 
    int a3; 
    int a4; 
    bool str[105]; 
}; 
prog ans[10000]; 
int p=0; 
bool istrue(bool* lap) 
{ 
    int i; 
    for(i=0;i&lt;opk;i++) 
    { 
        if(lap[op[i]-1]!=true) 
            return false; 
    } 
    for(i=0;i&lt;clk;i++) 
    { 
        if(lap[cl[i]-1]!=false) 
            return false; 
    } 
    return true; 
} 
void change(bool* lap,int k) 
{ 
    int st=0; 
    int ad=k; 
    if(k==4) 
    { 
        st=1; 
        ad=2; 
    } 
    int i; 
    for(i=st;i&lt;n;i+=ad) 
        lap[i]=!lap[i]; 
} 
void DFS(bool *lap,int k) 
{ 
    int i,j; 
    if(k/2==c/2) 
    { 
        if(istrue(lap)) 
        { 

            for(j=0;j&lt;n;j++) 
                ans[p].str[j]=lap[j]; 
            for(j=0;j&lt;25;j++) 
            { 
                ans[p].a1=ans[p].a1*2+ans[p].str[j];

            }

            for(j=25;j&lt;50;j++) 
            {

                ans[p].a2=ans[p].a2*2+ans[p].str[j]; 

            }

            for(j=50;j&lt;75;j++) 
            { 
                ans[p].a3=ans[p].a3*2+ans[p].str[j]; 

            }

            for(j=75;j&lt;100;j++) 
            { 
                ans[p].a4=ans[p].a4*2+ans[p].str[j]; 
            } 
            p++; 
            found=true; 
        } 
        return ; 
    } 
    for(i=1;i&lt;=4;i++) 
    { 

        bool tmp[105];

        for(j=0;j&lt;n;j++) 
        { 
            tmp[j]=lap[j]; 
        } 
        change(tmp,i); 
        DFS(tmp,k+1); 
    } 
} 
int cmp(const void *a,const void *b) 
{ 
    if((*(prog *)a).a1!=(*(prog *)b).a1) 
        return (*(prog *)a).a1-(*(prog *)b).a1; 
    if((*(prog *)a).a2!=(*(prog *)b).a2) 
        return (*(prog *)a).a2-(*(prog *)b).a2; 
    if((*(prog *)a).a3!=(*(prog *)b).a3) 
        return (*(prog *)a).a3-(*(prog *)b).a3; 
    return (*(prog *)a).a4-(*(prog *)b).a4;

} 
int main() 
{

    memset(ans,0,sizeof(ans)); 
    bool lap[105]; 
    freopen(&quot;lamps.in&quot;,&quot;r&quot;,stdin); 
    freopen(&quot;lamps.out&quot;,&quot;w&quot;,stdout); 
    memset(lap,true,sizeof(lap)); 
    cin&gt;&gt;n; 
    cin&gt;&gt;c; 
    while(1) 
    { 
        cin&gt;&gt;op[opk]; 

        if(op[opk]==-1) 
            break; 
        opk++; 
    } 
    while(1) 
    { 
        cin&gt;&gt;cl[clk]; 

        if(cl[clk]==-1) 
            break; 
        clk++; 
    } 
    if(c&gt;4) 
    { 
        if(c%2) 
            c=3; 
        else 
            c=4; 
    } 
    DFS(lap,0); 
    int i,j; 
    if(!found) 
        cout&lt;&lt;&quot;IMPOSSIBLE&quot;&lt;&lt;endl; 
    else 
    { 
        qsort(ans,p,sizeof(ans[0]),cmp); 
        for(i=0;i&lt;p;i++) 
        { 
            if(i&amp;&amp;ans[i].a1==ans[i-1].a1&amp;&amp;ans[i].a2==ans[i-1].a2&amp;&amp;ans[i].a3==ans[i-1].a3&amp;&amp;ans[i].a4==ans[i-1].a4) 
                continue; 
            for(j=0;j&lt;n;j++) 
            { 

                cout&lt;&lt;ans[i].str[j]; 
            } 
            cout&lt;&lt;endl; 
        } 
    } 
    return 0; 
}
[/code]