#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char str[2000][8];
int dis[2000][2000];
int lowdis[2000];
int main()
{
    int n ;
    while ( cin >> n , n )
    {
        int i , j , k ;
        for ( i = 0 ; i < n ; i ++ )
            cin >> str [i];
        memset(dis,0,sizeof(dis));
        //求任意两车之间的距离
        for ( i = 0 ; i < n - 1 ; i ++ )
        {
            for ( j = i+1 ; j < n ; j ++ )
            {
                for ( k = 0 ; k < 7 ; k ++ )
                {
                    if(str[i][k]!=str[j][k])
                        dis[i][j]++;
                }
                dis[j][i]=dis[i][j];
            }
        }
        //初始化集合和颠倒集合的距离
        for ( i = 0 ; i < n ; i ++ )
            lowdis[i]=dis[0][i];
        int ans = 0 ;    //    所求的解
        for ( i = 0 ; i < n - 1 ; i ++ )
        {
            int mindis = ( 1 << 20 ) ;
            for ( j = 0 ; j < n ; j ++ )
            {
                if( lowdis[j] && mindis > lowdis[j] )
                {//寻找到集合距离最小的点
                    mindis = lowdis[j] ;
                    k = j;
                }
            }
            ans += mindis ;
            lowdis[k] = 0 ;
            for ( j = 0 ; j < n ; j ++ )
            {//更新各点到集合的距离
                if(lowdis[j]>dis[k][j])
                    lowdis[j]=dis[k][j];
            }
        }
        //输出答案，注意后面还有个‘.’
        cout<<"The highest possible quality is 1/"<<ans<<"."<<endl;
    }
    return 0;
}