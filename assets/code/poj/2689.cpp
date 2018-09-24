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

bool ispri[46348];
bool ans[1000005];
int main()
{
	unsigned int i,j,k=0;
	one(ispri);
	ispri[0]=ispri[1]=1;
	for(i=2;i<46348;i++)
	{
		if(ispri[i])
		{
			for(j=i*i;j<46348;j+=i)
				ispri[j]=0;
		}
	}
	unsigned int l,r;
	while(~scanf("%u%u",&l,&r))
	{
		unsigned int a,b,c,d;
		a=b=c=d=-1;
		one(ans);
		if(l<2)l=2;
		for(i=2;i<46348;i++)
		{
			if(ispri[i])
			{
				unsigned int t=l/i;
				for(j=i*t;j<=r;j+=i)
				{
					if(j>=l)
					{
						if(j!=i)
							ans[j-l]=0;
						else
							ans[j-l]=1;
					}
				}
			}
		}
		for(i=0;i<=r-l;i++)
		{
			if(ans[i])
			{
				if(a==-1)
					a=c=i;
				else if(b==-1)
					b=d=i;
				else
				{
					if(b-a>i-k)
						b=i,a=k;
					if(d-c<i-k)
						d=i,c=k;
				}
				k=i;
			}
		}
		if(b==-1)
			printf("There are no adjacent primes.\n");
		else
			printf("%u,%u are closest, %u,%u are most distant.\n",a+l,b+l,c+l,d+l);
	}
    return 0;
}