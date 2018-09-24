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

const int mod=1e9+7;
__int64 mul(__int64 n,__int64 k)
{
	__int64 ans=1;
	while(k>=1)
	{
		if(k&1)
			ans=ans*n%mod;
		k=k/2;
		n=n*n%mod;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		__int64 n,k;
		scanf("%I64d%I64d",&n,&k);
		__int64 m=n-k;

		if(m<0)
		{
			printf("0\n");
			continue;
		}
		if(m==0||m==1)
		{
			printf("%I64d\n",m+1);
			continue;
		}

		printf("%I64d\n",mul(2,m-2)*(m+3)%mod);
	}
    return 0;
}