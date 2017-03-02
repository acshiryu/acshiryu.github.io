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

string s[30];
int num[30][30];
int num2[30];
struct prog{
	int num;
	int len;
	int xh;
}qian[5000],hou[5000];
void mycount(int l,int r,bool zl)
{
	prog *tmp;
	if(zl==0)
	{
		tmp=qian;
	}
	else
	{
		tmp=hou;
	}
	zero(tmp);

	int i,j;
	int len2=1;
	int len=0;
	for(i=0;i<(1<<(r-l));i++)
	{

		int k=i;
		j=l;
		int ans=0;
		int len=0;
		while(k)
		{
			if(k%2==1)
			{
				ans=ans^num2[j];
				len++;
			}
			j++;
			k/=2;
		}
		tmp[i].num=ans;
		tmp[i].len=len;
		tmp[i].xh=i;
	}
}
int erfen(int l,int r,int k)
{
	if(l+1==r)
	{
		if(hou[l].num==k)
			return l;
		else
			return -1;
	}
	int m=(l+r)/2;
	if(hou[m].num<=k)
		return erfen(m,r,k);
	else
		return erfen(l,m,k);
}

bool cmp(prog a,prog b)
{
	if(a.num==b.num)
		return a.len<b.len;
	return a.num<b.num;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i,j;
		for(i=0;i<n;i++)
			cin>>s[i];
		zero(num);
		for(i=0;i<n;i++)
		{
			for(j=0;j<s[i].length();j++)
			{
				num[i][s[i][j]-'A']=(!num[i][s[i][j]-'A']);
			}
		}
		for(i=0;i<n;i++)
		{
			num2[i]=0;
			for(j=0;j<26;j++)
			{
				num2[i]=2*num2[i]+num[i][j];
			}
		}
		mycount(0,n/2,0);
		mycount(n/2,n,1);
		sort(hou,hou+(1<<(n-n/2)),cmp);
		int ans=0;
		int ansi,ansj;
		for(i=0;i<(1<<(n/2));i++)
		{
			j=erfen(0,(1<<(n-n/2)),qian[i].num);
			if(j==-1)
				continue;
			int qianhou=qian[i].len+hou[j].len;
			if(qianhou>ans)
			{
				ansi=qian[i].xh;
				ansj=hou[j].xh;
				ans=qianhou;
			}
		}
		cout<<ans<<endl;
		if(ans==0)
			continue;
		bool sp=0;
		int t=0;
		while(ansi)
		{
			if(ansi%2==1)
			{
				if(sp)
					cout<<' ';
				cout<<t+1;
				sp=1;
			}
			t++;
			ansi/=2;
		}

		t=n/2;
		while(ansj)
		{
			if(ansj%2==1)
			{
				if(sp)
					cout<<' ';
				cout<<t+1;
				sp=1;
			}
			t++;
			ansj/=2;
		}
		cout<<endl;
	}
    return 0;
}