#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[300005];
int MinimumRepresentation(char *s, int l)  
{  
    int i = 0, j = 1, k = 0, t;  
    while(i < l && j < l && k < l) {  
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];  
        if(!t) k++;  
        else{  
            if(t > 0) i = i + k + 1;  
            else j = j + k + 1;  
            if(i == j) ++ j;  
            k = 0;  
        }  
    }  
    return (i < j ? i : j);  
}  
int main()
{
	while(cin>>s)
	{
		char t=s[0];
		int i=strlen(s);
		s[i]=t;
		for(i=0;s[i+1];i++)
		{
			s[i]=s[i+1]-s[i]+'0';
			if(s[i]<'0')
				s[i]+=8;
		}
		s[i]=0;
		int n=strlen(s);
		int k=MinimumRepresentation(s,n);
		for(i=k;i<k+n;i++)
		{
			cout<<s[i%n];
		}
		cout<<endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}