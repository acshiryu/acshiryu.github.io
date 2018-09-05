#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
pair<int ,int> a[200];            //保存n个石头的坐标
double lowcost[200],closet[200];//Prim算法必备，lowcost[i]表示i距离集合的最近距离，closet[i]表示i距离集合最近的点
double map[200][200];            //两点之间的距离
int main()
{
    int n;
    int k=1;
    while(cin>>n,n)
    {
        int i,j;
        for (i = 0 ;i < n ; i++ )
            cin>>a[i].first>>a[i].second;    //输入n个点的坐标，从0开始，也就是说题目编程求0-1的最小Frog Distance
        memset(lowcost,0,sizeof(lowcost));    //清零
        for ( i = 0 ; i < n ; i ++ )
        {
            for ( j = 0 ; j < n ; j ++ )
            {//求任意两点的距离，保存到map中
                map[i][j]=1.0*sqrt(pow(1.0*abs(a[i].first-a[j].first),2)+pow(1.0*abs(a[i].second-a[j].second),2));
            }
        }
        double ans=0.0;//所要求的答案，初始化为0
        for ( i = 0 ; i< n ; i++ )
        {//把0放入集合，则点到集合的距离此时是点到0的距离
            lowcost[i]=map[0][i];
            closet[i]=0;
        }

        for ( i = 0 ; i < n - 1 ; i ++ )
        {
            double mindis=1.0*(1<<20);        //点到集合最小距离，初始化为最大
            int minone;                        //到集合最小距离对应的点
            for ( j = 0 ; j < n ; j ++ )
            {
                if(lowcost[j]&&mindis>lowcost[j])
                {//j点不在集合中，并且j到集合的距离比最小距离还小，则更新最小距离
                    mindis=lowcost[j];
                    minone=j;
                }
            }
            if(ans<mindis)        //如果答案并不比更新的最小距离大
                ans=mindis;        //更新答案
            lowcost[minone]=0.0;//将该点入集合
            if(minone==1)        //如果改点是1，则水明义江找到了答案
                break;
            for ( j = 0 ; j < n ; j ++ )
            {//更新各点到集合的最小距离
                if(map[j][minone]<lowcost[j])
                {//如果minone到某点j的距离比原来的j到集合的距离要小，则更新该点到集合的距离为改点到minone的距离
                    lowcost[j]=map[j][minone];
                    closet[j]=minone;
                }
            }
        }
        cout<<"Scenario #"<<k<<endl;
        printf("Frog Distance = %.3f\n\n",ans);
        k++;
    }
    return 0;
}