#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const double pi=3.14159265359;
const double inf=0.00001;
double area[10005];
int n,f;

double erfen(double s,double t)
{
	double m=(s+t)/2+inf;
	if(fabs(s-t)<inf)
		return s;
	int i,j;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=(int)(area[i]/m);
	}
	if(sum>=f)
		return erfen(m,t);
	else
		return erfen(s,m-inf);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&f);
		f++;
		int i,j;
		double sum=0.0;
		for(i=0;i<n;i++)
		{
			int r;
			scanf("%d",&r);
			area[i]=pi*r*r;
			sum+=area[i];
		}
		printf("%.4lf\n",erfen(0,sum/f));
	}
    return 0;
}