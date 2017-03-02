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
	int x,i;
	char f;
	int rank;
}x[10010],y[10010];
bool operator<(prog a,prog b)
{
	return a.x<b.x;
}
bool cmpi(prog a,prog b)
{
	return a.i<b.i;
}
int main()
{
	int TTT;
	scanf("%d",&TTT);
	int cas=1;
	while(TTT--)
	{
		int l,t,n;
		scanf("%d%d%d",&l,&t,&n);
		int i,j;
		for(i=0;i<n;i++)
		{
			int a;
			char b[5];
			scanf("%d%s",&a,b);
			x[i].x=a;
			x[i].i=i;
			if(b[0] == 'L')
			{
				x[i].f=b[0];
				y[i].x=a-t;
			}
			else
			{
				x[i].f=b[0];
				y[i].x=a+t;
			}
			y[i].f=x[i].f;
			y[i].i=x[i].i;
		}
		sort(x,x+n);
		sort(y,y+n);
		for(i=0;i<n;i++)
		{
			x[i].rank=i;
			y[i].rank=i;
		}

		sort(x,x+n,cmpi);
		printf("Case #%d:\n",cas++);
		for(i=0;i<n;i++)
		{
			int k=x[i].rank;
			if(y[k].x<0||y[k].x>l)
			{
				printf("Fell off\n");
			}
			else
			{
				if((k>0&&y[k].x==y[k-1].x)||(k<n-1&&y[k].x==y[k+1].x))
					printf("%d Turning\n",y[k].x);
				else
					printf("%d %c\n",y[k].x,y[k].f);
			}
		}
		puts("");
	}
    return 0;
}