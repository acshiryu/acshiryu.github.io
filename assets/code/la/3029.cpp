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

char mp[1005][1005];
int sd[1005][1005];
int dp[1005];
int main()
{
	int T;
	int m,n;
	scanf("%d",&T);
	while(T--)
	{
		zero(dp);
		zero(mp);
		zero(sd);
		scanf("%d%d",&n,&m);
		int i,j,k;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				char s[5];
				scanf("%s",s);
				mp[i][j]=s[0];
			}
		}

		for(i=0;i<m;i++)
		{
			k=-1;
			for(j=0;j<n;j++)
			{
				if(mp[j][i]=='R')
				{
					sd[j][i]=j;
					k=j;
				}
				else if(mp[j][i]=='F')
				{
					sd[j][i]=k;
				}
			}
		}
		int mj=0;
		for(i=0;i<n;i++)
		{
			k=-1;
			dp[0]=-1;
			for(j=1;j<m;j++)
			{
				k=j-1;
				while(k!=-1&&sd[i][k]<=sd[i][j])
					k=dp[k];
				dp[j]=k;
			}
			for(j=0;j<m;j++)
				mj=max(mj,(j-dp[j])*(i-sd[i][j]));

			k=m;
			dp[m-1]=m;
			for(j=m-2;j>=0;j--)
			{
				k=j+1;
				while(k!=m&&sd[i][k]<=sd[i][j])
					k=dp[k];
				dp[j]=k;
			}
			for(j=0;j<m;j++)
				mj=max(mj,(dp[j]-j)*(i-sd[i][j]));
		}
		printf("%d\n",3*mj);
	}

    return 0;
}