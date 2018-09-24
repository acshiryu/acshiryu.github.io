#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int cost[100],lowcost[100],level[100];    //各点的的花费，从0到各点最小费用，各点的等级
int change[100][100];                    //拿i换j时还额外要的金币
bool vis[100];                            //确定i是否还要访问
int main()
{
    int m , n ;
    while ( cin >> m >> n ) 
    {
        int i , j , k ;
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
                change [i][j] = ( i == j ? 0 : ( 1 << 20 ) );//初始化，如果不能交换就为最大
        for ( i = 0 ; i < n ; i ++ )
        {//输入数值
            int a , b , c ;
            cin >> a >> b >> c;
            cost[i]=a;
            level[i]=b;
            for ( j = 0 ; j < c ; j ++ )
            {
                int d , e ;
                cin >> d >> e;
                change[i][d-1]=e;
            }
        }
        int minans = (1<<20);//定义结果
        for ( k = level[0] - m ; k != level[0] + 1 ; k ++ )
        {//定义区间早[k，k+m]
            memset(vis,true,sizeof(vis));    //初始化标记数组
            vis[0]=false;                    //0不用访问了
            int sum = 0 ;
            for ( j = 0 ; j < n ; j ++ )
            {
                if ( level[j]<k || level[j]>k+m)
                {//如果不在该区间了。就不用访问了
                    sum ++ ;
                    vis[j]=false;
                }
            }
            for ( i = 0 ; i < n ; i ++ )
                    lowcost[i] = change[0][i] + cost [i] ;//初始化各点到0的最短路（所发金币）
            for ( j = 1 ; j < n - sum ; j ++ )
            {
                int one ;
                int ans = (1 << 30);
                for ( i = 0 ; i < n ; i ++ )
                {//寻找花费金币最少的一点
                    if( vis[i] && ans > lowcost[i] )
                    {
                        ans = lowcost [i] ;
                        one = i;
                    }
                }
                vis [one] =false;
                for ( i = 0 ; i < n ; i ++ )
                {//更新各点的最短路
                    if ( lowcost [i] >( lowcost [one]- cost [one ] +change [one][i] + cost [i]) )
                        lowcost [i] = lowcost [one]-cost [one ] +change [one][i] + cost [i] ;
                }
            }
            for ( j = 0 ; j < n ; j ++ )
            {//遍历从0到n的最短路，寻找所花金币最小的点
                if ( level[j]>=k && level[j]<=k+m&&minans > lowcost [j] )
                    minans = lowcost [j] ;
            }
        }
        cout<<minans<<endl;
    }
    return 0;
}