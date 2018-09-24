#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
string s[50005];
int main()
{
	map<string,bool>ans;
	int n=0;
	while(cin>>s[n])
		ans[s[n++]]=true;
	for(int i=0;i<n;i++)
	{
		bool found=false;
		for(int j=1;j<s[i].size();j++)
		{
			string s1(s[i],0,j);
			string s2(s[i],j);
			if(ans.count(s1)&&ans.count(s2))
			{
				found=true;
				break;
			}
		}
		if(found)
			cout<<s[i]<<endl;
	}
	return 0;
}