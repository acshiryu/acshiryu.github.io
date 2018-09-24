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

char s1[100005];
char s2[100005];
int main()
{
	while(~scanf("%s%s",s1,s2))
	{
		int wrong=0;
		found=false;
		if(strlen(s1)!=strlen(s2))
		{
			cout<<"NO"<<endl;
			continue;
		}
		zero(hash);
		char c1,c2;
		for(int i=0;s1[i];i++)
		{
			if(s1[i]!=s2[i])
			{
				wrong++;
				if(wrong==1)
				{
					c1=s1[i];
					c2=s2[i];
				}
				if(wrong==2)
				{
					if(s1[i]!=c2||s2[i]!=c1)
						wrong++;
				}
				if(wrong>2)
					break;
			}
		}
		if(wrong==2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    return 0;
}