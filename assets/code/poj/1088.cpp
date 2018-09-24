#include<iostream>
#include<cstdio>
using namespace std;
int map[105][105];
int f[][2]={
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
;
int vis[105][105] ;
int m , n ;
int DFS ( int x , int y )
{
    if ( vis[x][y] != -1 )
        return vis[x][y] ;
    int i ;
    int sum = 1 ;
    for ( i = 0 ; i < 4 ; i ++ )
    {
        int s = x + f[i][0] ;
        int t = y + f[i][1] ;
        if ( s < 0 || t < 0 || s >= m || t >= n )
            continue;
        if ( map[s][t] >= map[x][y] )
            continue;
        sum = max ( sum , DFS ( s , t ) + 1 ) ;
    }
    vis[x][y] = sum ;
    return sum ;
}
int main()
{
    while ( cin >> m >> n )
    {
        int sum = 0;
        int i , j ;
        for ( i = 0 ; i < m ; i ++ )
            for ( j = 0 ; j < n ; j  ++ )
                cin >> map [i][j] ;
        memset ( vis , -1 , sizeof ( vis ) ) ;
        for ( i = 0 ; i < m ; i ++ )
            for ( j = 0 ; j < n ; j  ++ )
                sum = max ( sum , DFS ( i , j ) ) ; 
        cout << sum << endl ;
    }
    return 0 ;
}