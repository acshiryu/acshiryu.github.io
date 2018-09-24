#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int map[][5]={    {5,-1,-2,-1,-3},
                {-1,5,-3,-2,-4},
                {-2,-3,5,-2,-2},
                {-1,-2,-2,5,-1},
                {-3,-4,-2,-1,0} };
char str1[105];
char str2[105];
int f[256];
bool vis[105][105];
int ans[105][105];
int DFS ( int x , int y )
{

    int i ;
    int xy=0;
    if ( x == -1 )
    {
        for ( i = 0 ; i <= y ; i ++ )
            xy += map[str2[i]][4] ;
        return xy ;
    }
    if ( y == -1 )
    {
        for ( i = 0 ; i <= x ; i ++ )
            xy += map[str1[i]][4] ;
        return xy ;
    }
    if ( vis[x][y] ) 
        return ans[x][y] ;
    vis[x][y]=true;
    ans[x][y] = max ( DFS ( x - 1 , y - 1 ) + map[str1[x]][str2[y]] , max ( DFS(x,y-1)+map[4][str2[y]] , DFS(x-1,y)+map[str1[x]][4] )) ;
    return ans[x][y] ;
}
int main()
{
    f['A']=0;
    f['C']=1;
    f['-']=4;
    f['G']=2;
    f['T']=3;
    int t ;
    cin >> t ;
    while ( t -- )
    {
        int i , j ;
        int len1 , len2 ;
        cin >> len1 >> str1 ;
        for ( i = 0 ; i < len1 ; i ++ )
            str1[i]=f[str1[i]];

        cin >> len2 >> str2 ;
        for ( i = 0 ; i < len2 ; i ++ )
            str2[i]=f[str2[i]];
        memset ( vis , 0 , sizeof ( vis ) ) ;
        cout << DFS(len1-1,len2-1) << endl ;
    }
    return 0;
}