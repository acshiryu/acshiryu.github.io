#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(c<a)
            c=a;
        cout<<((c-a-1)/(a-b)+2)<<endl;
    }
    return 0;
}

