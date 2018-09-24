#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int d[20005],x[20005];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n||m)
	{
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<m;i++)
			scanf("%d",&x[i]);

		sort(d,d+n);
		sort(x,x+m);

		j=0;
		int sum=0;
		for(i=0;i<n;i++)
		{
			while(j<m&&x[j]<d[i])
				j++;
			if(j==m)
				break;
			if(j!=m)
				sum+=x[j++];
		}

		if(i!=n)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",sum);
	}
	return 0;
}