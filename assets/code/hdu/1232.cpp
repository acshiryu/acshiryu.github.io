#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pre[1005 ];
bool tmp[1005];
int find(int k)
{
	return pre[k]==k?k:pre[k]=find(pre[k]);
}
void join(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb)
		pre[fa]=fb;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n)
	{
		int i,j;
		for(i=0;i<1005;i++)
			pre[i]=i;
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			join(a,b);
		}
		memset(tmp,0,sizeof(tmp));
		int cnt=0;
		for(i=1;i<=n;i++)
		{
			if(tmp[find(i)]==0)
			{
				cnt++;
				tmp[find(i)]=1;
			}
		}
		printf("%d\n",cnt-1);
	}
}