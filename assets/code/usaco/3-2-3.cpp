/*
ID:shiryuw1
PROG:spin
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

struct prog{
	int v;
	int s[5];
	int l[5];
	int k;
}spin[5];
bool inn(int k,int m,int n)
{
	int t=k+360;
	if((k>=m&&k<=n)||(t>=m&&t<=n))
		return true;
	return false;
}
bool inspink(int m,int n)
{
	for(int i=0;i<spin[n].k;i++)
	{
		if(inn(m,spin[n].s[i],spin[n].s[i]+spin[n].l[i]))
			return true;
	}
	return false;
}
bool inspin(int k)
{
	int i;
	for(i=0;i<5;i++)
		if(!inspink(k,i))
			return false;
	return true;
}
bool pass()
{
	int i;
	for(i=0;i<360;i++)
	{
		if(inspin(i))
			return true;
	}
	return false;
}
void rotation()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<spin[i].k;j++)
		{
			spin[i].s[j]=(spin[i].s[j]+spin[i].v)%360;
		}
	}
}
int main()
{
  freopen("spin.in","r",stdin);
 freopen("spin.out","w",stdout);
	int i,j;
	for(i=0;i<5;i++)
	{
		int k;
		cin>>spin[i].v>>k;
		spin[i].k=k;
		while(k--)
		{
			cin>>spin[i].s[k]>>spin[i].l[k];
		}
	}
	for(i=0;i<360;i++)
	{
		if(pass())
			break;
		rotation();
	}
	if(i>=360)
		cout<<"none"<<endl;
	else
		cout<<i<<endl;
    return 0;
}