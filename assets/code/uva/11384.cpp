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

int f(int n)
{
	if(n==1)
		return 1;
	return f(n/2)+1;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",f(n));
	}
    return 0;
}