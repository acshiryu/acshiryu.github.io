#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct prog {
	char a ;
	int b ;
}tra;
struct proglu{
	char str[900];
}map;
bool hash[900];
bool found=false;
int p , q ;
int number=0;
void DFS(prog tmp , int n ,proglu map ,int k)
{
	if(found)
		return ;
	if(n==1)
	{
		int i;
		cout<<"Scenario #"<<number<<":"<<endl;
		for(i=0;i<k;i++)
		{

			cout<<map.str[i];
		}
		cout<<endl;
		found=true;
	}
	int t=(tmp.a-'A')*30+tmp.b;
	hash[t]=true;
	prog tmp2;
	tmp2=tmp;
	tmp2.a-=2;
	tmp2.b--;
	if(tmp2.a>='A'&&tmp2.b>=1&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a-=2;
	tmp2.b++;
	if(tmp2.a>='A'&&tmp2.b<=q&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a-=1;
	tmp2.b-=2;
	if(tmp2.a>='A'&&tmp2.b>=1&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a-=1;
	tmp2.b+=2;
	if(tmp2.a>='A'&&tmp2.b<=q&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=1;
	tmp2.b-=2;
	if(tmp2.a<='A'+p-1&&tmp2.b>=1&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=1;
	tmp2.b+=2;
	if(tmp2.a<='A'+p-1&&tmp2.b<=q&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=2;
	tmp2.b-=1;
	if(tmp2.a<='A'+p-1&&tmp2.b>=1&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}

	tmp2=tmp;
	tmp2.a+=2;
	tmp2.b+=1;
	if(tmp2.a<='A'+p-1&&tmp2.b<=q&&hash[(tmp2.a-'A')*30+tmp2.b]==false)
	{
		map.str[k]=tmp2.a;
		map.str[k+1]=tmp2.b+'0';
		DFS(tmp2,n-1,map,k+2);
		hash[(tmp2.a-'A')*30+tmp2.b]=false;
	}
}

int main()
{
	int k = 1 ;

	int t;
	cin>>t;
	while(t--)
	{
		number++;
		cin >> q >> p ;
		if(number!=1)
			cout<<endl;
		memset(hash,false,sizeof(hash)) ;
		tra.a='A';
		tra.b=1;
		memset(map.str,0,sizeof(map.str));
		map.str[0]='A';
		map.str[1]='1';
		found=false;
		DFS(tra,p*q,map,2); 
		if(!found)
		{
			cout<<"Scenario #"<<number<<":"<<endl;

			cout<<"impossible"<<endl;
		}
	}
	return 0;
}