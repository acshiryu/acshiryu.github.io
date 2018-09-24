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
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

typedef long long ll;
int pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
struct prog{
    ll yz;
    ll num;
}ans;
ll n;
void DFS(prog tmp,int i,int k)
{
    if(ans.yz<tmp.yz)
        ans=tmp;
    if(ans.yz==tmp.yz&&ans.num>tmp.num)
        ans=tmp;
    if(k==0||i==12)
        return ;
    ll j;
    int t=0;
    for(j=1;j*tmp.num<=n&&t<=k;t++,j*=pri[i+1])
    {
        prog tx;
        tx.num=j*tmp.num;
        tx.yz=tmp.yz*(1+t);
        DFS(tx,i+1,t);
    }
}
int main()
{
    while(cin>>n)
    {
        ans.num=1;
        ans.yz=1;
        int k=0;
        for(ll i=1;i<=n;i*=2,k++)
        {
            //cout<<i<<endl;
            //system("pause");
            prog tmp;
            tmp.num=i;
            tmp.yz=k+1;
            DFS(tmp,0,k);
        }
        cout<<ans.num<<endl;
    }
    return 0;
}