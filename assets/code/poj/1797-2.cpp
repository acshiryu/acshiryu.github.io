#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = (1<<20);
int *p,*r;        //p是用于并查集的，r是用来存储边序号的
int *u,*v,*w;    //分别代表边的起点，终点，和权值，明显不是我的风格，先熟悉下模板，不得不这样写
bool cmp(const int a,const int b)
{//间接排序函数，
    return w[a]>w[b];
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
        int i ;
        u=new int[m];
        v=new int[m];
        w=new int[m];
        r=new int[m];//动态分配
        for ( i = 0 ; i < m ; i ++ )
        {
            int a , b , c ;
            cin>>a>>b>>c;
            u[i]=a;
            v[i]=b;
            w[i]=c;//加入边
        }
        p=new int[n+1];
        for ( i =1 ; i <= n; i ++ )
            p[i]=i;//初始化并查集
        for ( i = 0 ;i < m ; i ++ )
            r[i]=i;//初始化边序号
        sort(r,r+m,cmp);//根据边的权值的大小将边的序号进行排序，r[i]表示第i+1大的边存储在u，v，w数组中的序号
        int ans=inf;    //将答案初始化为最大值
        for ( i = 0 ; i < m ; i ++ )
        {
            int e=r[i];//找到第i+1大的边
            int x=find(u[e]);
            int y=find(v[e]);
            if(x!=y)
            {//如果该边所在的两边不在同一个连通分量里，则连接该边
                if(ans>w[e])//如果该边的权值比ans小（实际上一定不会比ans大），则更新ans
                    ans=w[e];
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