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

int a[10][10];
int ans[10];
int mat[10];
int test(int k,int t)
{
    k=k^t;
    k=k^(t<<1);
    k=k^(t>>1);
    k=k&((1<<6)-1);
    return k;
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k;
        for(i=0;i<5;i++)
        {
            k=0;
            for(j=0;j<6;j++)
            {
                scanf("%d",&a[i][j]);
                k=k*2+a[i][j];
            }
            mat[i]=k;
        }

        int bin=(1<<6)-1;

        int up;
        for(i=0;i<=bin;i++)
        {
            ans[0]=i;
            k=mat[0];
            for(j=1;j<=5;j++)
            {
                up=test(k,ans[j-1]);
                k=mat[j]^ans[j-1];
                ans[j]=up;
            }
            if(up==0)
                break;
        }

        printf("PUZZLE #%d\n",cas++);
        for(i=0;i<5;i++)
        {
            for(j=5;j>=0;j--)
            {
                printf("%d",bool(ans[i]&(1<<j)));
                if(j!=0)
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}