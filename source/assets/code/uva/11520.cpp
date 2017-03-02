#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char mat[15][15];
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,j;
		scanf("%d",&n);
		memset(mat,'.',sizeof(mat));
		for(i=1;i<=n;i++)
			scanf("%s",mat[i]+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mat[i][j]=='.')
				{
					for(char c='A';c<='Z';c++)
					{
						if(c!=mat[i][j-1]&&c!=mat[i][j+1]&&c!=mat[i-1][j]&&c!=mat[i+1][j])
						{
							mat[i][j]=c;
							break;
						}
					}
				}
			}
		}
		printf("Case %d:\n",cas++);
		for(i=1;i<=n;i++)
			printf("%s\n",mat[i]+1);
	}
    return 0;
}