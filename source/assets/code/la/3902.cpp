#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

const int maxn=1000+10;
vector<int>link[maxn],node[maxn];
bool vis[maxn];
int fa[maxn];
int n,s,k;
void init()
{
	for(int i=0;i<=n;i++)
	{
		link[i].clear();
		node[i].clear();
	}
}
void build(int root,int father,int dep)
{
	int i,j;
	fa[root]=father;
	if(link[root].size()==1&&dep>k)
		node[dep].push_back(root);
	for(i=0;i<link[root].size();i++)
	{
		int knode=link[root][i];
		if(knode!=father)
		{
			build(knode,root,dep+1);
		}
	}
}
void dfs(int root ,int fat,int dep)
{
//	cout<<root<<' '<<dep<<endl;
	vis[root]=true;
	if(dep==k)
		return ;
	for(int i=0;i<link[root].size();i++)
	{
		int knode=link[root][i];
		if(knode!=fat)
		{
			dfs(knode,root,dep+1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&s,&k);
		int i,j;
		init();
		for(i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			link[a].push_back(b);
			link[b].push_back(a);
		}
		build(s,-1,0);
		int ans=0;
		zero(vis);
		for(i=n-1;i>k;i--)
		{
			for(j=0;j<node[i].size();j++)
			{
				int knode=node[i][j];
				if(vis[knode])
					continue;

				for(int d=0;d<k;d++)
				{
					knode=fa[knode];
				}

				dfs(knode,-1,0);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}