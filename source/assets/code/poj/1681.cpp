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

char a[20][20];
int ans[20];
int mat[20];
int n;

int OneCount(unsigned int x)
{//计算二进制中的1的个数  参考Matrix67
    x=(x&0x55555555)+((x>>1)&0x55555555); 
    x=(x&0x33333333)+((x>>2)&0x33333333);
    x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f); 
    x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff); 
    x=(x&0x0000ffff)+((x>>16)&0x0000ffff);
    return x;
}
int test(int k,int t)
{
    k=k^t;
    k=k^(t<<1);
    k=k^(t>>1);
    k=k&((1<<n)-1);
    return k;
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            k=0;
            scanf("%s",a[i]);
            for(j=0;j<n;j++)
            {
                a[i][j]=(a[i][j]=='y'?0:1);
                k=k*2+a[i][j];
            }
            mat[i]=k;
        }

        int bin=(1<<n)-1;

        int up;
        for(i=0;i<=bin;i++)
        {
            ans[0]=i;
            k=mat[0];
            for(j=1;j<=n;j++)
            {
                up=test(k,ans[j-1]);
                k=mat[j]^ans[j-1];
                ans[j]=up;
            }
            if(up==0)
                break;
        }

        if(i==bin+1)
        {
            printf("inf\n");
            continue;
        }
        int cnt=0;
        for(i=0;i<n;i++)
        {
            cnt+=OneCount(ans[i]);
        }
        printf("%d\n",cnt);
    }

    return 0;
}