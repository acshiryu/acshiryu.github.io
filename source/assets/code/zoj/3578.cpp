#include "iostream"
#include "cmath"
#include "cstdio"
using namespace std;
#define zero(x) 	(memset(x,0,sizeof(x)))
#define to(i,x,n)	for(i=x;ib?a:b;
}
bool iandjcross(int i,int j)
{//判断矩阵i和j是否相交
	if(matrix[i].xa>=matrix[j].xb||matrix[i].xb<=matrix[j].xa)
		return false;
	if(matrix[i].ya>=matrix[j].yb||matrix[i].yb<=matrix[j].ya)
		return false;
	return true;
}
int main()
{
	int n,m;
	int i,j,k;
	int x,y,z;
	int r,s,t; 
	int ans,maxx,minx;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		maxx=0;
		to(i,0,k)
		{
			scanf("%d%d%d%d%d",&r,&s,&t,&x,&y);
			ans=0;
			matrix[i].xa=x;
			matrix[i].ya=y;
			matrix[i].xb=x+r;
			matrix[i].yb=y+s;
			to(j,0,i)
			{
				if(iandjcross(i,j))
				{
					ans=max(ans,matrix[j].h);
				}
			}
			matrix[i].h=(ans+t);
			maxx=max(maxx,matrix[i].h);
		}
		printf("%dn",maxx);
	}
	return 0;
}