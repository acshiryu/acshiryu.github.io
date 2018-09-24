#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

struct prog{
	int x;int y;
}h[1010],s[1010];
bool map[1010][1010];
int link[1010];
bool vis[1010];
int n,m;
bool check(int i,int j)
{
	if(h[i].x==s[j].x&&h[i].y==s[j].y)
		return 1;
	if(h[i].x+1==s[j].x&&h[i].y==s[j].y)
		return 1;
	if(h[i].x==s[j].x&&h[i].y==s[j].y+1)
		return 1;
	if(h[i].x+1==s[j].x&&h[i].y==s[j].y+1)
		return 1;
	return 0;
}

bool find ( int k ) 
{//对k寻找匹配，如果找到就记录匹配，并返回true,否则返回false
    int i , j ;
    for ( i = 1 ; i <= m ; i ++ )
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

	while(~scanf("%d%d",&n,&m),n||m)
	{
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%d%d",&h[i].x,&h[i].y);
		for(i=1;i<=m;i++)
			scanf("%d%d",&s[i].x,&s[i].y);

		zero(map);
		zero(link);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				map[i][j]=check(i,j);
			//	if(map[i][j]==1)
				//	cout<<i<<' '<<j<<endl;
			}
		}

		int ans = 0 ;    //最大匹配数
        for ( i = 1 ; i <= n ; i ++ )
        {
            memset ( vis , false , sizeof ( vis ) ) ;//对所有数据都初始为0，表明数据还没有试探
            if ( find ( i ) ) //如果对i找到一个匹配
                ans ++ ;
        }
	//	cout<<ans<<endl;
		printf("%d\n",m+n-ans);
	}
    return 0;
}