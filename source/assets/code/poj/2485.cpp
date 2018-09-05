#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int map[500][500];
int lowcost[500];
const int inf = (1<<20) ;
int main()
{
    int n;
    int t;
    cin >> t;
    while ( t -- )
    {
        cin >> n ;
        int i , j ;
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
                cin >> map[i][j];
        for ( i = 0 ; i < n ; i ++ )
            lowcost[i]=map[0][i];    //初始化各点到集合的距离
        int ans=0;//记录生成树的最大权值
        for ( i = 0 ; i < n-1 ; i ++ )
        {
            int mindis=inf;
            int minone;
            for ( j = 0 ; j < n ; j ++ )
            {//寻找到集合距离最近的点
                if(lowcost[j]&&mindis>lowcost[j])
                {
                    mindis=lowcost[j];
                    minone=j;
                }
            }
            if(ans <mindis )
                ans =mindis;
            lowcost[minone]=0;
            for ( j = 0 ; j < n ; j ++ )
            {//更新各点到集合的距离
                if(lowcost[j]>map[minone][j])
                    lowcost[j]=map[minone][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}