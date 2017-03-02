#include <algorithm>
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

struct prog
{
	int tx,ty;
	int x,y;
	int i;
}p[105];
bool cmpx(prog a,prog b)
{
	return a.tx<b.tx;
}
bool cmpy(prog a,prog b)
{
	return a.ty<b.ty;
}

int x_num;
int y_num;
int sumx[205][205];
int sumy[205][205];
bool mp[205][205];
int main()
{
	int n;
	int cas=1;
	while(scanf("%d",&n),n)
	{
		int i,j,k;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].tx,&p[i].ty);
			p[i].i=i;
		}

		//ÀëÉ¢»¯
		x_num=y_num=1;
		sort(p,p+n,cmpx);
		p[0].x=0;
		for(i=1;i<n;i++)
		{
			if(p[i].tx==p[i-1].tx)
				p[i].x=p[i-1].x;
			else
				p[i].x=p[i-1].x+1;
			x_num=p[i].x+1;
		}

		sort(p,p+n,cmpy);
		p[0].y=0;
		for(i=1;i<n;i++)
		{
			if(p[i].ty==p[i-1].ty)
				p[i].y=p[i-1].y;
			else
				p[i].y=p[i-1].y+1;
			y_num=p[i].y+1;
		}

		zero(mp);
		for(i=0;i<n;i++)
			mp[p[i].x][p[i].y]=1;

		for(i=0;i<x_num;i++)
		{
			sumy[i][0]=0;
			for(j=1;j<=y_num;j++)
			{
				sumy[i][j]=sumy[i][j-1]+mp[i][j-1];
			}
		}

		for(i=0;i<y_num;i++)
		{
			sumx[0][i]=0;
			for(j=1;j<=x_num;j++)
			{
				sumx[j][i]=sumx[j-1][i]+mp[j-1][i];
			}
		}	
		int num=0;
		for(i=0;i<x_num;i++)
			for(j=0;j<y_num;j++)
			{
				num=max(num,sumy[i][y_num]);
				num=max(num,sumx[x_num][i]);
			}
		for(i=0;i<x_num;i++)
		{
			for(j=i+1;j<x_num;j++)
			{
				for(int s=0;s<y_num;s++)
				{
					for(int t=s+1;t<y_num;t++)
					{
						int shang=sumx[j][s]-sumx[i+1][s];
						int xia=sumx[j][t]-sumx[i+1][t];
						int zuo=sumy[i][t]-sumy[i][s+1];
						int you=sumy[j][t]-sumy[j][s+1];
						num=max(num,shang+xia+zuo+you+mp[i][s]+mp[i][t]+mp[j][s]+mp[j][t]);
					}
				}
			}
		}
		printf("Case %d: %d\n",cas++,num);
	}
    return 0;
}