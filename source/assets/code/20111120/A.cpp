#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool hash[10];
long long ans[1000005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        memset(hash,0,sizeof(hash));
        while(m--)
        {
            int a;
            cin>>a;
            hash[a]=1;
        }
        m=0;
        int i;
        for(i=0;i<10;i++)
            if(hash[i]==0)
                m++;
        ans[0]=1;
        for(i=1;i<=n;i++)
            ans[i]=ans[i-1]*m%1000000007;
        if(hash[0])
        {
            long long sum=0;
            for(i=1;i<=n;i++)
                sum=(sum+ans[i])%1000000007;
            cout<<sum<<endl;
        }
        else
        {
            cout<<ans[n]<<endl;
        }
    }
    return 0;
}
