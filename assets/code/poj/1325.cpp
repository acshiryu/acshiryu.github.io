#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int m , n , k ;
bool map[100][100] , vis [100];
int link [100];
bool find ( int x ) 
{
    int i ;
    for ( i = 1 ; i < n ; i ++ )
    {
        if (map[x][i] && !vis[i] )
        {
            vis[i]=true;
            if( link [i] == 0 || find ( link [i] ) )
            {
                link [i] = x ;
                return true ;
            }
        }
    }
    return false ;
}
int main()
{
    while ( cin >> m , m )
    {
        cin >> n >> k ;
        int i , j ;
        memset ( map , 0 , sizeof ( map ) ) ;
        memset ( link , 0 , sizeof ( link ) );
        for ( i = 0 ; i < k ; i ++ )
        {
            int a , b , c ;
            cin >> a >> b >> c ;
            if ( b == 0 || c == 0 )
                continue ;
            map [b][c] = true ;
        }
        int ans = 0 ;
        for ( i = 1 ; i < m ; i ++ )
        {
            memset ( vis , 0 , sizeof ( vis ) ) ;
            if ( find ( i ) )
                ans ++ ;
        }
        cout << ans << endl ;
    }
    return 0;
}