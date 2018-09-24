/*
ID:shiryuw1
PROG:kimbits
LANG:C++
*/
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

long long c[50][50];
int main()
{
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	long long n,l,k,i,j;
	zero(c);
	for(i=0;i<50;i++)
	{
		c[i][i]=c[0][i]=1;
	}
	for(i=1;i<50;i++)
	{
		for(j=i+1;j<50;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i][j-1];
		}
	}
	cin>>n>>l>>k;
	while(n--)
	{
		long long sum=0;
		for(i=0;i<=l;i++)
			sum+=c[i][n];
		if(k>sum)
		{
			printf("1");
			k-=sum;
			l--;
		}
		else
			printf("0");
	}
	printf("\n");
	return 0;
}