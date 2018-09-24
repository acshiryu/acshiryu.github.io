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
#define MAX 10000000
struct{
	int x,y;
}a[20][20];
int n;

int check(int k)
{
	int i;
	for(i=0;i<n;i++)
		a[0][i].y=0;
	i=0;
	while(k)
	{
		a[0][i].y=k%2;
		k=k/2;
		i++;
	}

	for(i=0;i<n;i++)
		if(a[0][i].x==1&&a[0][i].y==0)
			return -1;

	return 0;			
}
int fun()
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int sum=0;
			if(i>=2)
				sum+=a[i-2][j].y;
			if(j>0)
				sum+=a[i-1][j-1].y;
			if(j<n-1)
				sum+=a[i-1][j+1].y;
			if(sum%2==0)
				a[i][j].y=0;
			else
				a[i][j].y=1;
			if(a[i][j].y==0&&a[i][j].x==1)
				return MAX;
		}

	}

	int cnt=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j].x==0&&a[i][j].y==1)
				cnt++;

	return cnt;
}
int main()
{
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j].x);
			}
		}

		int ans=MAX;

		for(i=0;i<(1<<n);i++)
		{
			if(check(i)==-1)
				continue;
			ans=min(ans,fun());
		}
		if(ans!=MAX)
			printf("Case %d: %d\n",cas++,ans);
		else
			printf("Case %d: -1\n",cas++);
	}
     return 0;
}