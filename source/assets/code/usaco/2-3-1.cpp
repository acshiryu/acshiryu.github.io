/*
ID:shiryuw1
PROG:prefix
LANG:C++
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=5020;
char str[200005]={0};
struct progtrie{
	int a[26];
	bool hash;
}trie[MAX];
int tree=1;
int maxpre=-1;
int vis[200005]={0};

bool isin(char *ch)
{
	int i;
	int k=0;
	for(i=0;ch[i]!=0;i++)
	{
		k=trie[k].a[ch[i]-'A'];
		if(k==0)
		{
			return false;
		}
	}
	if(k==0||trie[k].hash==false)
		return false;
	return true;
}

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	int i,ii;
	for(i=0;i<MAX;i++)
	{
		for(ii=0;ii<26;ii++)
		{
			trie[i].a[ii]=0;
		}
		trie[i].hash=false;
	}
	while(1)
	{
		char ch[20];
		cin>>ch;
		if(ch[0]=='.')
			break;
		int k=0;
		for(i=0;ch[i]!=0;i++)
		{
			if(trie[k].a[ch[i]-'A']==0)
			{
				trie[k].a[ch[i]-'A']=tree;
				tree++;
			}
			k=trie[k].a[ch[i]-'A'];
		}
		trie[k].hash=true;
	}
	getchar();
	char ch[100]={0};
	while(cin>>ch)
	{
		strcat(str,ch);
	}
	bool ans=true;
	int len=strlen(str);
	int maxlength=0;
	for(i=1;i<=len;i++)
	{
		int length=0;
		int j;
		for(j=1;j<=10;j++)
		{
			int x;
			if(i>=j)
			{
				if(vis[i-j]!=(i-j))
					continue;
				ans=false;
				int y=0;
				for(x=i-j;x<i;x++)
				{
					ch[y]=str[x];
					y++;
				}
				ch[y]=0;

				if(isin(ch))
				{
					if(vis[i-j]+y>length)
					{
						length=vis[i-j]+y;
					}
				}
			}

		}
		vis[i]=length;
		if(length>maxlength)
			maxlength=length;
		if(ans)
			break;
	}
	cout<<maxlength<<endl;
	return 0;
}