#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
bool num[25];
int a[25];
bool ispri[50];
void DFS(int k,int n)
{
	int i,j;
	if(k==n)
	{
		if(ispri[a[k-1]+1])
		{
			for(i=0;i<n;i++)
			{
				if(i)
					printf(" ");
				printf("%d",a[i]);
			}
			printf("\n");
		}
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(num[i])
			continue;
		if(ispri[a[k-1]+i])
		{
			a[k]=i;
			num[i]=1;
			DFS(k+1,n);
			num[i]=0;
		}
	}
}
int main()
{
	int n;
	int cnt=1;
	memset(ispri,1,sizeof(ispri));
	ispri[0]=ispri[1]=0;
	int i,j;
	for(i=2;i<=8;i++)
	{
		if(ispri[i])
		{
			for(j=i*i;j<50;j+=i)
				ispri[j]=0;
		}
	}
	while(~scanf("%d",&n))
	{
		memset(num,0,sizeof(num));
		printf("Case %d:\n",cnt++);
		a[0]=1;
		num[1]=1;
		DFS(1,n);
		printf("\n");
	}
}