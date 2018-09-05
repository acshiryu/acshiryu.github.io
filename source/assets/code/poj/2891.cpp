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

void e_gcd ( __int64 a , __int64 b , __int64 &d , __int64 &x , __int64 &y )
{

	if ( ! b )
		d = a , x =1 , y =0 ;
	else
		e_gcd ( b , a%b , d , y , x ) , y -= x * ( a / b ) ;
}
__int64 gcd(__int64 a,__int64 b)
{
	return b==0?a:gcd(b,a%b);
}
__int64 lcm(__int64 a,__int64 b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int T;
	while(~scanf("%d",&T))
	{
		int i,j;
		T--;
		__int64 m,n,r1,r2;
		bool ans=true;
		scanf("%I64d%I64d",&m,&r1);
		for(i=0;i<T;i++)
		{
			scanf("%I64d%I64d",&n,&r2);
			if(ans)
			{
				__int64 x,y,d;
				e_gcd(m,n,d,x,y);
				if((r2-r1)%d!=0)
					ans=false;
				__int64 t=(r2-r1)/d;
				x=x*t;
				y=y*t;
				x%=(n/d);//求出最小正整数x
				while(x<0)
					x+=(n/d);
				r1=m*x+r1;//合并
				m=lcm(m,n);
				if((r1-r2)%n!=0)
					ans=false;
			}
		}
		if(ans)
			printf("%I64d\n",r1);
		else
			printf("-1\n");

	}
    return 0;
}