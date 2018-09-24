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

int main()
{
	int n,a,b,c;
	while(cin>>n>>a>>b>>c)
	{
		int s=a+b+c;
		double ans=(1.0*n/s);
		if(a==0&&b==0&&c==0)
			printf("%.1lf %.1lf %.1lf\n",0.0,0.0,0.0);
		else
		    printf("%.16f %.16f %.16f\n",ans*a,ans*b,ans*c);

	}
    return 0;
}