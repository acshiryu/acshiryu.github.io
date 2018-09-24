#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

__int64 ans[10];
struct rect{
    int llx,lly,urx,ury,c;
}cfx[10005];
const int sx[]={1,2,4,3,5,6,7};
int color[5];
int color_rank[3];
void DFS(int lx,int ly,int rx,int ry,int t,int c)
{
	if(lx==rx||ly==ry)
		return ;
        if(t==-1)
	{
		if(c!=0)
			ans[c]+=((__int64)(rx-lx))*(ry-ly);
                return ;
	}
	if(t>=0&&t<color_rank[0]&&((c|1)==c))
	{
		DFS(lx,ly,rx,ry,-1,c);
		return ;
	}
	else if(t>=color_rank[0]&&t<color_rank[1]&&((c|2)==c))
	{
		DFS(lx,ly,rx,ry,color_rank[0]-1,c);
		return ;
	}
	else if(t>=color_rank[1]&&t<color_rank[2]&&((c|4)==c))
	{

		DFS(lx,ly,rx,ry,color_rank[1]-1,c);
		return ;
	}

    if(cfx[t].llx>=rx||cfx[t].lly>=ry||cfx[t].urx<=lx||cfx[t].ury<=ly)
    {
        DFS(lx,ly,rx,ry,t-1,c);
    }
    else
    {
        int k1,k2,k3,k4;
        k1=max(lx,cfx[t].llx);
        k2=min(rx,cfx[t].urx);
        if(lx<k1)
            DFS(lx,ly,k1,ry,t-1,c);
        if(rx>k2)
            DFS(k2,ly,rx,ry,t-1,c);

        k3=max(ly,cfx[t].lly);
        k4=min(ry,cfx[t].ury);
        if(ly<k3)
            DFS(k1,ly,k2,k3,t-1,c);
        if(ry>k4)
            DFS(k1,k4,k2,ry,t-1,c);
		if(k1!=k2&&k3!=k4)
			DFS(min(k1,k2),min(k3,k4),max(k1,k2),max(k3,k4),t-1,cfx[t].c|c);
    }
}
bool cmp(rect a,rect b)
{
	return a.c<b.c;
}

int main()
{
	int T,cnt=1;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,n,i;
		scanf("%d",&n);
		x=y=0;
		zero(ans);
		zero(color);
		for(i=0;i<n;i++)
		{
			char str[3];
			scanf("%s",str);
			if(str[0]=='R')
				cfx[i].c=1;
			else if(str[0]=='G')
				cfx[i].c=2;
			else if(str[0]=='B')
				cfx[i].c=4;

			scanf("%d%d%d%d",&cfx[i].llx,&cfx[i].lly,&cfx[i].urx,&cfx[i].ury);
			x=max(x,cfx[i].urx);
			y=max(y,cfx[i].ury);
			color[cfx[i].c]++;
		}
		sort(cfx,cfx+n,cmp);
		color_rank[0]=color[1];
		color_rank[1]=color_rank[0]+color[2];
		color_rank[2]=color_rank[1]+color[4];

		DFS(0,0,x,y,n-1,0);

		printf("Case %d:\n",cnt++);
		for(i=0;i<7;i++)
			printf("%I64d\n",ans[sx[i]]);
	}
    return 0;
}