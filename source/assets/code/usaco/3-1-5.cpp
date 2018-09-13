/*
ID:shiryuw1
PROG:contact
LANG:C++
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

typedef map<string , int> msi;
typedef pair<string ,int> psi;
char s[200005];
string strget(char *t,int k)
{
	string str;
	for(int i=0;i<k;i++)
		str+=t[i];
	return str;
}
psi cnt[5555];
int strsec(string s)
{
	unsigned int i,ans=0;
	for(i=0;i<s.length();i++)
		ans=ans*2+s[i]-'0';
	return ans;
}
bool cmp(psi a,psi b)
{
	if(a.second==b.second)
	{
		if((a.first.length())==(b.first.length()))
			return strsec(a.first)<strsec(b.first);
		return (a.first.length())<(b.first.length());
	}
	return a.second>b.second;
}
int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	int a,b,n,i,j;
	scanf("%d%d%d",&a,&b,&n);
	msi ans;
	string tmp;
	while(~scanf("%s",s+strlen(s)));
	int len=strlen(s);
	for(i=0;i<=len-a;i++)
	{
		tmp=strget(s+i,a);
		for(j=a;j<=b&&i+j<=len;j++)
		{
			if(j!=a)
				tmp+=s[i+j-1];
			if(!ans.count(tmp))
				ans[tmp]=0;
			//cout<<tmp<<endl;
			ans[tmp]++;
		}
	}
	msi::iterator iter;
	for(iter=ans.begin(),i=0;iter!=ans.end();iter++,i++)
	{
		cnt[i].first=(iter->first);
		cnt[i].second=(iter->second);
	}
	sort(cnt,cnt+(j=i),cmp);
	int num=0;
	int hang=0;
	for(i=0;i<j;i++)
	{
		if(i&&cnt[i].second==cnt[i-1].second)
		{
			if(hang==5)
			{
				cout<<endl;
				hang=-1;
			}
			else
			{
				cout<<' ';
			}
			cout<<cnt[i].first;
			hang++;
		}
		else
		{
			if(num>=n)
				break;
			if(i)
				puts("");
			cout<<cnt[i].second<<"\n"<<cnt[i].first;
			hang=0;
			num++;
		}
	}
	puts("");
    return 0;
}