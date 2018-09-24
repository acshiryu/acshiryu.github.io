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

int a[25],b[25];
int main()
{
    while(~scanf("%d",&a[0]))
    {
        b[0]=a[0];
        int i;
        for(i=1;i<20;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        int ans=1<<20;
        for(i=0;i<2;i++)
        {
            int cnt=0;
            memcpy(b,a,sizeof(b));
            if(i==1)
            {
                b[0]=!b[0];
                b[1]=!b[1];
                cnt++;
            }
            for(int j=1;j<19;j++)
            {
                if(b[j-1]==1)
                {
                    cnt++;
                    b[j-1]=!b[j-1];
                    b[j]=!b[j];
                    b[j+1]=!b[j+1];
                }
            }
            if(b[19]^b[18]==0)
            {
                if(b[19]==1)
                    cnt++;
                if(ans>cnt)
                    ans=cnt;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}