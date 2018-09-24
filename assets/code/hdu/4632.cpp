#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn=1000+10;
const int mod=10007;
int dp[maxn][maxn];
char s[maxn];
int len;
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		len=strlen(s);
		int i,j,k;
		for(i=len-1;i>=0;i--)
		{
			for(k=0;i+k<len;k++)
			{
				j=i+k;
				if(k==0)
				{
					dp[i][j]=1;
				}
				else if(k==1)
				{
					dp[i][j]=2+(s[i]==s[j]);
				}
				else
				{
					dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+mod)%mod;		
					if(s[i]==s[j])
						dp[i][j]+=dp[i+1][j-1]+1;
				}
			}
		}
		printf("Case %d: %d\n",cas++,dp[0][len-1]%mod);
	}
    return 0;
}