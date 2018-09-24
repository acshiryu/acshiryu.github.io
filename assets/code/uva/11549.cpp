#include<cstdio>
#include<set>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long __int64;
__int64 mypow10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,100000000000};
inline int count(__int64 k)
{
	if(k==0)
		return 1;
	int cnt=0;
	while(k)
	{
		k=k/10;
		cnt++;
	}
	return cnt;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		__int64 n,k;
		//scanf("%I64d%I64d",&n,&k);
		cin>>n>>k;
		set<int>s;
		int maxn=0;
		while(s.count(k)==0)
		{
			maxn=max(maxn,(int)k);
			s.insert(k);
			k=k*k;
			int l=count(k);
			if(l>n)
				k=k/mypow10[l-n];
		}
		printf("%d\n",maxn);
	}
}