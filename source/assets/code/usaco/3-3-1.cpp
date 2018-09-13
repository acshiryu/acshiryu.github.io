/*
ID:shiryuw1
PROG:fence
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

int cnt[505];
int adj[505][505];
int path[2500];
int e;
int k;
void DFS(int s)
{
	int i,j;
	for(i=1;i<=k;i++)
	{
		if(adj[s][i])
		{
			adj[s][i]--;
			adj[i][s]--;
			DFS(i);
			path[e++]=i;
		}
	}
}
int main()
{
	  freopen("fence.in","r",stdin);
	  freopen("fence.out","w",stdout);
	int n;
	while(~scanf("%d",&n))
	{
		int i,j;
		zero(cnt);
		zero(adj);
		k=1;
		e=0;
		for(i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			adj[a][b]++;
			adj[b][a]++;
			cnt[a]++;
			cnt[b]++;
			k=max(k,max(a,b));
		}
		int s=0;
		for(i=1;i<=k;i++)
		{
			if(s==0)
				s=i;
			if(cnt[i]%2)
			{
				s=i;
				break;
			}
		}
		DFS(s);
		path[e++]=s;
		for(i=e-1;i>=0;i--)
			printf("%d\n",path[i]);
	}
	return 0;
}