#include<cstdio>
#include<iostream>
using namespace std;
int a[100005];
const int inf=200000;
int main()
{
	int n,s;
	while(~scanf("%d%d",&n,&s))
	{
		int i,j;
		int sum=0;
		int len=inf;
		int k=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			while(sum>=s)
			{
				len=min(len,i-k);
				sum-=a[++k];
			}
			if(sum<0)
			{
				len=1;
				k=i;
				sum=0;
			}
		}
		if(len==inf)
			printf("0\n");
		else
			printf("%d\n",len);
	}
}