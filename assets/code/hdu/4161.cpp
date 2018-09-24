#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int inf=1e3;
bool equal(int *a,int n)
{
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[0])
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	int a[25];
	int i,j;
	int cas=1;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<inf;i++)
		{
			if(!equal(a,n))
			{
				int tmp=a[0];
				for(j=0;j<n-1;j++)
				{
					a[j]=abs(a[j]-a[j+1]);
				}
				a[n-1]=abs(a[n-1]-tmp);
			}
			else
			{
				printf("Case %d: %d iterations\n",cas,i);
				break;
			}
		}
		if(i==inf)
			printf("Case %d: not attained\n",cas);
		cas++;
	}
	return 0;
}