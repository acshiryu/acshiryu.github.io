/*
ID:shiryuw1
PROG:fact4
LANG:C++
*/
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

int main()
{
	freopen("fact4.in","r",stdin);
	 freopen("fact4.out","w",stdout);
	int n;
	while(cin>>n)
	{
		int ans=1;
		int a,b;
		a=b=0;
		for(int i=1;i<=n;i++)
		{
			int k=i;
			while(k%2==0)
			{
				a++;
				k/=2;
			}
			while(k%5==0)
			{
				b++;
				k/=5;
			}
			ans=ans*k%10;
		}
		a-=b;
		a%=4;
		if(a==0)
		{
			if(b)
				a=4;
		}
		ans=(ans*(1<<a))%10;
		cout<<ans<<endl;
	}
    return 0;
}