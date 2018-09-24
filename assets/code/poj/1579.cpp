#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w[25][25][25];
int DFS(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
		return DFS(20,20,20);
	int& ans=w[a][b][c];
	if(ans!=-1)
		return ans;
	if(a<b&&b<c)
		ans=DFS(a, b, c-1) + DFS(a, b-1, c-1) - DFS(a, b-1, c);
	else
		ans=DFS(a-1, b, c) + DFS(a-1, b-1, c) + DFS(a-1, b, c-1) - DFS(a-1, b-1, c-1);
	return ans;
}
int main()
{
	int i,j,k;
	memset(w,-1,sizeof(w));
	while(cin>>i>>j>>k)
	{
		if(i==-1&&j==-1&&k==-1)
			break;
		printf("w(%d, %d, %d) = %d\n",i,j,k,DFS(i,j,k));
	}
}