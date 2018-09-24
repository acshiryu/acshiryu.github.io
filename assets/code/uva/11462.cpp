#include<cstdio>
#include<cstring>
int a[105];
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int k;
		memset(a,0,sizeof(a));
		while(n--)
		{
			scanf("%d",&k);
			a[k]++;
		}
		bool sc=0;
		for(int i=1;i<=100;i++)
		{

			while(a[i]--)
			{
				if(sc)
					printf(" ");
				sc=1;
				printf("%d",i);
			}
		}
		printf("\n");
	}
}