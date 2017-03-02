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

long long mp[25][25][25];
long long sum[25][25][25];
long long dp[25];
const long long inf=(1LL)<<55;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int i,j,k;
		zero(mp);
		zero(sum);
		for(i=1;i<=a;i++)
		{
			for(j=1;j<=b;j++)
			{
				for(k=1;k<=c;k++)
				{
					scanf("%lld",&mp[i][j][k]);
				}
			}
		}

		int h,ia,ib,ja,jb;
		for(h=1;h<=c;h++)
		{
			for(i=1;i<=a;i++)
			{
				for(j=1;j<=b;j++)
				{
					sum[i][j][h]=mp[i][j][h]+sum[i-1][j][h]+sum[i][j-1][h]-sum[i-1][j-1][h];
				}
			}
		}

		long long ans=-inf;

		for(ia=0;ia<a;ia++)
		{
			for(ja=0;ja<b;ja++)
			{
				for(ib=ia+1;ib<=a;ib++)
				{
					for(jb=ja+1;jb<=b;jb++)
					{
						long long maxk=0;
						for(h=1;h<=c;h++)
						{
							long long tmp=sum[ib][jb][h]+sum[ia][ja][h]-sum[ib][ja][h]-sum[ia][jb][h];
							ans=max(ans,maxk+tmp);
							maxk=max(maxk+tmp,0LL);
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
		if(T)
			printf("\n");
	}
    return 0;
}