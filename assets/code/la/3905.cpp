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

const int maxn=100000+10;
const double inf=1e-6;
struct prog{
	double x;
	bool fx;
	prog(double y,bool f)
	{
		x=y;
		fx=f;
	}
	prog(){}
}lr[2*maxn];
int num;
void update(int x,int a,int w,double &L,double &R)
{
	if(a==0)
	{
		if(x<=0||x>=w)
			R=L-1;
	}
	else if(a>0)
	{
		L=max(L,-1.0*x/a);
		R=min(R,1.0*(w-x)/a);
	}
	else
	{
		L=max(L,1.0*(w-x)/a);
		R=min(R,-1.0*x/a);
	}
}
bool operator<(prog a,prog b)
{
	if(a.x==b.x)
		return a.fx>b.fx;
	return a.x<b.x;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int w,h,n;
		scanf("%d%d%d",&w,&h,&n);
		int i,j;
		num=0;
		for(i=0;i<n;i++)
		{
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);

			 double L=0,R=1e9;
			 update(x,a,w,L,R);
			 update(y,b,h,L,R);

			 if(R>L)
			 {
				 lr[num++]=prog(L,0);
				 lr[num++]=prog(R,1);
			 }
		}

		sort(lr,lr+num);

		int cnt=0;
		int ans=0;
		for(i=0;i<num;i++)
		{
			if(lr[i].fx==0)
				ans=max(ans,++cnt);
			else
				cnt--;
		}
		printf("%d\n",ans);
	}
    return 0;
}