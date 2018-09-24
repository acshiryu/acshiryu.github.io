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

const int maxn=100010;
int a[maxn];
int jia[maxn];
int jian[maxn];
int dp[2][maxn];
int jia_num;
int jian_num;
int erfenjia(int s,int t,int k)
{
	if(s==t)
		return s;
	int m=(s+t)/2;

	if(k>=jia[m])
		return erfenjia(m+1,t,k);
	else
		return erfenjia(s,m,k);
}

int erfenjian(int s,int t,int k)
{
	if(s==t)
		return s;
	int m=(s+t)/2;

	if(k<=jian[m])
		return erfenjian(m+1,t,k);
	else
		return erfenjian(s,m,k);
}
int erfen(int*a ,int s,int t,int k,bool x)
{
	if(s==t)
		return s;
	int m=(s+t)/2+1;
	if(x==0&&k<=a[m])
		return erfen(a,s,m-1,k,x);
	else if(x==1&&k>=a[m])
		return erfen(a,s,m-1,k,x);
	else
		return erfen(a,m,t,k,x);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int i,j;
		int ans=1;
		scanf("%d",&n);
		zero(jia);
		zero(jian);
		jia_num=jian_num=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			int tmp=a[n-i-1];
			if(i!=0)
			{
				int s,t;
				if(tmp>=jia[jia_num-1])
					s=jia_num++;
				else
					s=erfenjia(0,jia_num-1,tmp);

				if(tmp<=jian[jian_num-1])
					t=jian_num++;
				else
					t=erfenjian(0,jian_num-1,tmp);

				jia[s]=tmp;
				jian[t]=tmp;
				int sx=erfen(jia,0,jia_num-1,tmp,0);
				int sy=erfen(jian,0,jian_num-1,tmp,1);
				if(sx==0&&jia[sx]<=tmp)
					sx=-1;
				if(sy==0&&jian[sy]>=tmp)
					sy=-1;
				int com=s+1+t+1-min(s-sx,t-sy);
			//	cout<<min(s-sx,t-sy)<<endl;
			//	cout<<s<<' '<<t<<endl;
			//	cout<<sx<<' '<<sy<<endl;
				if(com>ans)
					ans=com;
			}
			else
			{
				jia[jia_num++]=tmp;
				jian[jian_num++]=tmp;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}