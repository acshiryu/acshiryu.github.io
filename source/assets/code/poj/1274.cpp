#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool map[201][201], vis[201] ;    //map保存两点间是否有边，vis保存每次操作后该数是否操作过
int link[201] ;                    //link保存改点连接的另一点的序号
int m , n ;
bool find ( int k ) 
{//对k寻找匹配，如果找到就记录匹配，并返回true,否则返回false
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ )
    {//对所有节点遍历一遍，寻找没有访问过并且与i连同的点
        if ( map [k][i] ==true && ! vis[i] )
        {
            vis [i] = true ;    //记录改点以被访问
            if ( link [i] == 0 || find ( link [i] ) )
            {//如果该点还未与其他点匹配，或还能找到其他点能与该点匹配的点j进行匹配，即存在增广路
                link [ i ] = k ;    //将i与k进行匹配
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while ( cin >> m >> n ) 
    {//初始化，接受数据的输入
        memset ( map , false , sizeof ( map ) ) ;
        memset ( link , 0 , sizeof ( link ) ) ;
        int i , j ;
        for ( i = 1 ; i <= m ; i ++ )
        {
            int s ;
            cin >> s ;
            for ( j = 0 ; j < s ; j ++ )
            {
                int k ;
                cin >> k ;
                map [i][k] = true ;
            }
        }
 
        int ans = 0 ;    //最大匹配数
        for ( i = 1 ; i <= m ; i ++ )
        {
            memset ( vis , false , sizeof ( vis ) ) ;//对所有数据都初始为0，表明数据还没有试探
            if ( find ( i ) ) //如果对i找到一个匹配
                ans ++ ;
        }
        cout<<ans<<endl;
    }
    return 0;
}