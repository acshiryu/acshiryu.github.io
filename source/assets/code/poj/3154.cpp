#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

double old_place[1005];
double new_place[2010];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int mk=m+n;
		double old=10000.0/n;
		double now=10000.0/mk;
		int i;
		for(i=0;i<n;i++)
			old_place[i]=old*i;

		for(i=0;i<=mk;i++)
			new_place[i]=now*i;
		int j=0;
		double sum=0.0;
		for(i=0;i<n;i++)
		{
			while(fabs(old_place[i]-new_place[j])>fabs(old_place[i]-new_place[j+1]))
				j=j+1;
			sum+=fabs(old_place[i]-new_place[j]);
		}
		printf("%.4lf\n",sum);
	}
    return 0;
}