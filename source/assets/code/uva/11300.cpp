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

long long money[1000005];
long long tmp[1000005];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		long long sum=0;
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&money[i]);
			sum+=money[i];
		}
		int ave=sum/n;
		for(i=0;i<n;i++)
		{
			money[i]=money[i]-ave;
		//	printf("%d\n",money[i]);
		}
		tmp[0]=0;
		for(i=1;i<n;i++)
			tmp[i]=tmp[i-1]-money[i];
		sort(tmp,tmp+n);
		int mid=n/2;

		long long ans=0;
		for(i=0;i<n;i++)
		{
			ans+=abs(-tmp[i]+tmp[mid]);
		}
		printf("%lld\n",ans);
	}
    return 0;
}