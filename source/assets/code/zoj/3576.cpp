#include "iostream"
#include "cmath"
#include "cstdio"
using namespace std;
unsigned int gcd(unsigned int a,unsigned int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
	unsigned int k;
	unsigned long long a,b;
	while(cin>>a>>b)
	{
	        k=gcd(a,b);
	        a=a/k;
	        b=b/k;//注意一定要约去a,b的公因子
		printf("%.3lfn",(ceil((a*b)/2.0)/(a*b*1.0))*1.0*sqrt(1.0*(a*a+b*b))*k);
                //向上取整可用ceil()，向下取整可用floor()
	}
	return 0;
}