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
#define MAX 1000000

int xz[30][10];
int xz_cnt;
int n;
int ans;
struct prog{
	string color[6];
}a[10];
string cr[10];

void DFS(int k,int x[])
{
//	cout<<k<<endl;
	if(k==n)
	{
		int i,j,p;
		int sum=0;
		for(i=0;i<6;i++)
		{

			int sum_tmp;
			sum_tmp=0;
			for(j=0;j<n;j++)
			{
				int xt=1;

				cr[j]=a[j].color[xz[x[j]][i]];
				for(p=0;p<j;p++)
				{
					if(cr[j].compare(cr[p])==0)
						xt++;
				}
				sum_tmp=max(sum_tmp,xt);
			}

			sum+=(n-sum_tmp);
			if(sum>=ans)
				return ;
		}
		ans=sum;
	//	cout<<ans<<endl;
	}
	else
	{
		for(int i=0;i<xz_cnt;i++)
		{
			x[k]=i;
			DFS(k+1,x);
		}
	}
}
void xuanzhuan(int ding,int di,int a,int b,int c,int d)
{
	int abcd[4];
	abcd[0]=a;
	abcd[1]=b;
	abcd[2]=c;
	abcd[3]=d;
	int i,j;
	for(i=0;i<4;i++,xz_cnt++)
	{
		xz[xz_cnt][0]=ding;
		xz[xz_cnt][5]=di;
		for(j=1;j<=4;j++)
			xz[xz_cnt][j]=abcd[(i+j)%4];
	}
}
void init()
{
	zero(xz);
	xz_cnt=0;
	//1的对面是6,2的对面是5,3的对面是4
	xuanzhuan(2,3,0,1,5,4);
	xuanzhuan(3,2,0,4,5,1);
	xuanzhuan(4,1,0,2,5,3);
	xuanzhuan(1,4,0,3,5,2);
	xuanzhuan(0,5,2,4,3,1);
	xuanzhuan(5,0,2,1,3,4);
}
int main()
{

	init();
	while(scanf("%d",&n),n)
	{
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<6;j++)
				cin>>a[i].color[j];
	//	cout<<1<<endl;
		ans=MAX;
		int x[10];
		x[0]=0;
		DFS(1,x);
		printf("%d\n",ans);
	}

    return 0;
}