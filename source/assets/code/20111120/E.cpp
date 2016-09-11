#include<iostream>
#include<cstring>
using namespace std;
char s[20];
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(s,0,sizeof(s));
        cin>>s;
        long long m=0;
        long long t=1;
        int i=0;
        for(i=0;s[i]!='.'&&s[i];i++);
        for(i++;s[i];i++)
        {
            m=m*10+s[i]-'0';
            t*=10;
        }
        cout<<t/gcd(t,m)<<endl;
    }
}
