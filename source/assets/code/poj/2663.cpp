#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int a[35];
int f[35];
int g[35];
int main()
{
	int n;
	a[0]=1;
	int i;
	for(i=1;i<31;i++)
	{
		f[i]=2*a[i-1]+g[i-1];
		g[i]=f[i-1];
		a[i]=f[i-1]+a[i-2];
	}
	while(scanf("%d",&n),n+1)
		printf("%d\n",a[n]);
}