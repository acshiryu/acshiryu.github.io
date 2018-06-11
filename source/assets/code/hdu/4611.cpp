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

__int64 gcd(__int64 a,__int64 b)
{
	return b==0?a:gcd(b,a%b);
}
__int64 lcm(__int64 a,__int64 b)
{
	return a/gcd(a,b)*b;
}

__int64 abs(__int64 k)
{
	return k<0?-k:k;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		__int64 n,a,b;
		scanf("%I64d%I64d%I64d",&n,&a,&b);

		if(a>b)
		{
			__int64 t;
			t=b;
			b=a;
			a=t;
		}

		__int64 k=gcd(a,b);
		__int64 ga=a/k;
		__int64 gb=b/k;
		__int64 i,j;
		__int64 sum=0;
		__int64 sumi;
		__int64 sumn=0;
		__int64 x=0;
		__int64 nm=(n%lcm(a,b))/b;
		__int64 tx=0;
		for(i=0;i<ga;i++)
		{
			sumi=0;
			__int64 anum=x/a;
			__int64 x1=(anum+1)*a-x;
			sumi+=x1*abs(x%a-x%b);
			x+=x1;
			__int64 sy=b-x1;
			while(sy>=a)
			{
				sy-=a;
				sumi+=a*abs(x%a-x%b);
				x+=a;
			}
			sumi+=sy*abs(x%a-x%b);

			x+=sy;

			sum+=sumi;
		}
		x=0;
		for(i=0;i<nm;i++)
		{
			sumi=0;
			__int64 anum=x/a;
			__int64 x1=(anum+1)*a-x;
			sumi+=x1*abs(x%a-x%b);
			x+=x1;
			__int64 sy=b-x1;
			while(sy>=a)
			{
				sy-=a;
				sumi+=a*abs(x%a-x%b);
				x+=a;
			}
			sumi+=sy*abs(x%a-x%b);

			x+=sy;

			sumn+=sumi;
		}

		__int64 ans=sum*(n/lcm(a,b))+sumn;

		__int64 nab=n%lcm(a,b);
		for(i=nm*b;i<nab;i++)
			ans+=abs(i%a-i%b);

		printf("%I64d\n",ans);

	}
    return 0;
}