#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
    scanf("%d",&t);
    int cas=1;
    while (t--)
    {
        int n , m ;
        scanf("%d%d",&n,&m);
        int i ;
        for (i=0;i<2005;i++)
        {//pre初始化
            pre[i]=i;
        }
        memset(com,-1,sizeof(com));

        bool found = false;        //判断是否找到搞基的虫子
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
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
        printf("Scenario #%d:\n",cas++);
        if (found)
        {
            printf("Suspicious bugs found!\n");
        } 
        else
        {
            printf("No suspicious bugs found!\n");
        }
        printf("\n");
    }
    return 0;
}