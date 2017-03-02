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

int s[100];
int t[100];
long long f(int *p,int k,int zd)
{
	if(k<0)
		return 0;
	if(p[k]==zd)
		return f(p,k-1,zd);
	return f(p,k-1,6-p[k]-zd)+((1LL)<<(k));
}
int main()
{
	int n;
	int cas=1;
	while(scanf("%d",&n),n)
	{
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);

		for(i=n-1;i>=0;i--)
			if(s[i]!=t[i])
				break;

		if(i==-1)
		{
			printf("Case %d: 0\n",cas++);
			continue;
		}

		long long ans=0;
		int k=6-s[i]-t[i];
		ans=f(s,i-1,k)+f(t,i-1,k)+1;
		printf("Case %d: %lld\n",cas++,ans);
	}
    return 0;
}