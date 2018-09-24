/*
ID:shiryuw1
PROG:rect1
LANG:C++
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int ans[2505]={0};
struct prog{
	int llx,lly,urx,ury,color;
}rect[1005];
int area;
void DFS(int lx,int ly,int rx,int ry,int t)
{
	if(t==0)
		return ;
	if(rect[t].llx>=rx||rect[t].lly>=ry||rect[t].urx<=lx||rect[t].ury<=ly)
	{
		DFS(lx,ly,rx,ry,t-1);
	}
	else
	{
		int k1,k2,k3,k4;
		k1=max(lx,rect[t].llx);
		k2=min(rx,rect[t].urx);
		if(lx<k1)
			DFS(lx,ly,k1,ry,t-1);
		if(rx>k2)
			DFS(k2,ly,rx,ry,t-1);

		k3=max(ly,rect[t].lly);
		k4=min(ry,rect[t].ury);
		if(ly<k3)
			DFS(k1,ly,k2,k3,t-1);
		if(ry>k4)
			DFS(k1,k4,k2,ry,t-1);
		//cout<<k1<<' '<<k2<<' '<<k3<<' '<<k4<<endl;
		ans[rect[t].color]+=abs(k2-k1)*abs(k4-k3);
		area-=abs(k2-k1)*abs(k4-k3);
	}

}
int main()
{
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int i,j;
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&rect[i].llx,&rect[i].lly,&rect[i].urx,&rect[i].ury,&rect[i].color);
	area=a*b;
	DFS(0,0,a,b,n);
	ans[1]+=area;
	for(i=1;i<2505;i++)
		if(ans[i])
			printf("%d %d\n",i,ans[i]);
	return 0;
}