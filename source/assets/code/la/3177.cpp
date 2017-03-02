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

int n;
const int maxn=100000+10;
int r[maxn];
int erfen(int a,int c)
{
	int b=(a+c)/2;
	if(a==c)
		return a;
	int i,j;
	int left,right;
	left=right=0;
	left=r[0];
	for(i=1;i<n-1;i++)
	{
		if(i%2==0)
		{
			right=b-r[0]-right;
			if(right>r[i])
			{
				right=r[i];
				left=0;
			}
			else
			{
				left=r[i]-right;
			}
		}
		else
		{
			left=r[0]-left;
			if(left>r[i])
			{
				left=r[i];
				right=0;
			}
			else
			{
				right=r[i]-left;
			}
		}
	}
//	cout<<left<<' '<<right<<' '<<b<<endl;
	int all=r[0]+right+r[n-1];
	if(all>b)
	{
		return erfen(b+1,c);
	}
	else
	{
		return erfen(a,b);
	}
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int i,j;
		int l,m;
		for(i=0;i<n;i++)
			scanf("%d",&r[i]);
		if(n==1)
		{
			printf("%d\n",r[0]);
			continue;
		}
		l=m=0;
		for(i=0;i<n;i++)
		{
			l=max(l,r[i]+r[(i+1)%n]);
			m=max(m,3*r[i]);
		}

		if(n%2==0)
		{
			printf("%d\n",l);
		}
		else
		{
			printf("%d\n",erfen(l,m));
		}

	}
    return 0;
}