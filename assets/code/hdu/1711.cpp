#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[1000000+5];
int b[1000000+5];
int p[1000000+5];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(p,-1,sizeof(p));
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
			if(i)
			{
				j=p[i-1];
				if(b[j+1]==b[i])
					p[i]=j+1;
				else
					p[i]=-1;
			}
		}
		j=-1;
		for(i=0;i<n;i++)
		{
			while(j>=0&&b[j+1]!=a[i])
				j=p[j];
			if(b[j+1]==a[i])
				j++;
			if(j+1==m)
				break;
		}
		if(i==n)
			printf("-1\n");
		else
			printf("%d\n",i-j+1);
	}
	return 0;
}