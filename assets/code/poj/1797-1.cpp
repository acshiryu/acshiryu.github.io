//第一次提交的代码基本是套模板的，和自己写的出入较大，不习惯，将代码修改下感觉也许更好！，第一次提交的代码见最下面
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = (1<<20);
int p[1005];        //p是用于并查集的，r是用来存储边序号的
struct prog {
    int w,v,u;        //记录起点，终点，权值
};
bool cmp(prog a,prog b)
{//间接排序函数，
    return a.w>b.w;
}
int find(int x)
{//并查集里的find函数，你懂的
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
    int t;
    cin >> t;
    int k = 1;
    while(t--)
    {
        int n ,m;
        cin >> n >> m;
        prog *r;
        r=new prog[m];
        int i ;
        for ( i = 0 ; i < m ; i ++ )
            cin>>r[i].u>>r[i].v>>r[i].w;    //输入边的信息

        for ( i =1 ; i <= n; i ++ )
            p[i]=i;//初始化并查集

        sort(r,r+m,cmp);//根据边的权值的大小将边的序号进行排序，r[i]表示第i+1大的边存储在u，v，w数组中的序号
        int ans=inf;    //将答案初始化为最大值
        for ( i = 0 ; i < m ; i ++ )
        {
            int x=find(r[i].u);
            int y=find(r[i].v);
            if(x!=y)
            {//如果该边所在的两边不在同一个连通分量里，则连接该边
                if(ans>r[i].w)//如果该边的权值比ans小（实际上一定不会比ans大），则更新ans
                    ans=r[i].w;
                p[x]=y;//连接该边
                if(find(1)==find(n))//当1和n连通时，则说明找到了一条从1到n的路，并且可知该路的所有边的权值都是最大的，故边的最小权值就是答案
                    break;
            }
        }
        //输出答案，格式如题所述
        cout<<"Scenario #"<<k<<":"<<endl;
        cout<<ans<<endl<<endl;
        k++;
    }
    return 0;
}