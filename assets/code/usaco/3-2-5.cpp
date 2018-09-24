/*
ID:shiryuw1
PROG:msquare
LANG:C++
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

int f[10];
int a[10];
struct prog{
	int huifu;
	int kt;
	string ans;
};
int kt(int a)
{
	bool hash[10];
	memset(hash,0,sizeof(hash));
	int ans=0,i;
	for(i=0;a;i++)
	{
		int k=a%10;
		a/=10;
		int t=0;
		hash[k]=1;
		while(k--)
		{
			if(hash[k])
				t++;
		}
		ans+=t*f[i];
	}
	return ans;
}
bool hash[100000];
int main()
{
	  freopen("msquare.in","r",stdin);
	  freopen("msquare.out","w",stdout);
	int i,j;
	f[0]=1;
	for (i=1;i<10;i++)
	{
		f[i]=i*f[i-1];
	}
	while(cin>>a[0])
	{
		int ans=a[0];
		for(i=1;i<8;i++)
		{
			cin>>a[i];
			if(i<4)
				ans=ans*10+a[i];
		}
		for(i=4;i<8;i++)
			ans=ans*10+a[11-i];
		prog k;
		k.huifu=12348765;
		k.kt=kt(k.huifu);
		queue<prog>q;
		q.push(k);
		hash[k.kt]=1;
		while(!q.empty())
		{
			k=q.front();
			if(k.huifu==ans)
			{
				cout<<k.ans.length()<<'\n'<<k.ans<<endl;
				break;
			}
			int k5;
			for(i=0;i<3;i++)
			{
				k=q.front();
				switch(i)
				{
				case 0:
					k.ans+='A';
					k.huifu=(k.huifu%10000)*10000+k.huifu/10000;
					k.kt=kt(k.huifu);
					if(hash[k.kt])
						continue;
					hash[k.kt]=1;
					if(k.huifu==ans)
					{
						cout<<k.ans.length()<<'\n'<<k.ans<<endl;
						goto over;
					}
					q.push(k);
					break;
				case 1:
					k.ans+='B';
					k5=(k.huifu/10000)%10;
					k.huifu=k5*10000000+(k.huifu/100000)*10000+(k.huifu%10)*1000+((k.huifu/10)%1000);
					k.kt=kt(k.huifu);
					if(hash[k.kt])
						continue;
					hash[k.kt]=1;
					if(k.huifu==ans)
					{
						cout<<k.ans.length()<<'\n'<<k.ans<<endl;
							goto over;
					}
					q.push(k);
					break;
				case 2:
					k.ans+='C';
					int kx[10];
					for(int x=0;x<8;x++)
					{
						kx[7-x]=k.huifu%10;
						k.huifu/=10;
					}
					k.huifu=0;
					k.huifu=kx[0]*10000000+kx[5]*1000000+kx[1]*100000
						+kx[3]*10000+kx[4]*1000+kx[6]*100+kx[2]*10+kx[7];
					k.kt=kt(k.huifu);
					if(hash[k.kt])
						continue;
					hash[k.kt]=1;
					if(k.huifu==ans)
					{
						cout<<k.ans.length()<<'\n'<<k.ans<<endl;
							goto over;
					}
					q.push(k);
					break;
				default:break;
				}
			}
			q.pop();
over:	;}
	}
	return 0;
}