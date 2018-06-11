#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

struct prog{
	double p;
	int k;
}pos[1005];
bool cmp(prog a,prog b)
{
	return a.k<b.k;
}
double dis[1005][1005];
double sum[1005][1005];
double dp[1005][1005];
int main()
{
	int kx,m;
	while(scanf("%d%d",&kx,&m),kx||m)
	{
		int i,j,k;
		int pos_num=0;
		map<int,int>mp;

		for(i=0;i<kx;i++)
		{
			int n;
			scanf("%d",&n);
			//cout<<1<<endl;
			for(j=0;j<n;j++)
			{
				int t;
				double p;
				scanf("%d%lf",&t,&p);
				if(mp.count(t)==0)
				{
					mp[t]=pos_num;
					pos[pos_num].p=p;
					pos[pos_num++].k=t;
				}
				else
				{
					pos[mp[t]].p+=p;
				}
			}
		}

		sort(pos,pos+pos_num,cmp);

		zero(sum);
		for(i=0;i<pos_num;i++)
		{
			sum[i][i]=pos[i].p;
			for(j=i+1;j<pos_num;j++)
			{
				sum[i][j]=sum[i][j-1]+pos[j].p;
			}
		}

		zero(dis);
		for(i=0;i<pos_num;i++)
		{
			for(j=i+1;j<pos_num;j++)
			{
				dis[i][j]=0.0;
				for(k=i+1;k<=j;k++)
				{
					dis[i][j]+=(pos[k].k-pos[i].k)*pos[k].p;
				}

				double tmp=dis[i][j];
				for(k=i+1;k<=j;k++)
				{
					tmp=(pos[k].k-pos[k-1].k)*(sum[i][k-1]-sum[k][j])+dis[i][j];
					if(tmp<dis[i][j])
						dis[i][j]=tmp;
					else
						break;
				}
				//cout<<dis[i][j]<<endl;
			}
		}

		for(i=0;i<pos_num;i++)
		{
			//dp[i][0]=0;
			dp[i][1]=dis[0][i];
			for(j=2;j<=m;j++)
			{
				dp[i][j]=1000000000.0;
				for(k=0;k<=i;k++)
				{
					dp[i][j]=min(dp[i][j],dp[k][j-1]+dis[k+1][i]);
				}
			}
		}

		printf("%.2lf\n",dp[pos_num-1][m]);
	}
    return 0;
}