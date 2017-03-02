#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct prog{
	char type[25];
	char name[25];
	int price;
	int quality;
}com[1010];
bool compare_type(prog a,prog b)
{
	if(strcmp(a.type,b.type)==0)
	{
		if(a.quality==b.quality)
			return a.price<b.price;
		return a.quality<b.quality;
	}
	if(strcmp(a.type,b.type)>0)
		return 1;
	return 0;
}
int com_start[1010];
int com_type;
int n,b;
int erfen(int s,int t)
{
	if(s==t)
		return s;
	int m=(s+t)/2+1;
	int i,j;
	int sum=0;
	for(i=0;i<com_type;i++)
	{
		int less=1000000;
		for(j=com_start[i];j<com_start[i+1];j++)
		{
			if(com[j].quality>=m)
			{
				less=min(less,com[j].price);
			}
		}
		sum+=less;
	}
	if(sum<=b)
		return erfen(m,t);
	else
		return erfen(s,m-1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,k;
		scanf("%d%d",&n,&b);
		int max_quality,min_quality;
		max_quality=0;
		min_quality=1000000000;
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d%d",&com[i].type,&com[i].name,&com[i].price,&com[i].quality);
			max_quality=max(max_quality,com[i].quality);
			min_quality=min(min_quality,com[i].quality);
		}
		sort(com,com+n,compare_type);

		com_start[0]=0;
		for(j=1,i=1;i<n;i++)
		{
			if(strcmp(com[i].type,com[i-1].type))
				com_start[j++]=i;
		}
		com_type=j;
		com_start[j]=n;
		printf("%d\n",erfen(min_quality,max_quality));
	}
    return 0;
}