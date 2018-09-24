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

char s[30];
char q[30];
char inter[100010];
char cry[50010];
int p[100010];
int cnt[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j;
        scanf("%s%s",s,inter);
        for(i=0;s[i];i++)
        {
            q[s[i]-'a']=i+'a';
        }

        zero(cry);
        int len=strlen(inter);
        if(len==1)
        {
            printf("%c%c\n",inter[0],q[inter[0]-'a']);
            continue;
        }
        for(i=(len-1)/2+1;inter[i];i++)
            cry[i-1-(len-1)/2]=s[inter[i]-'a'];

        p[0]=-1;
        j=-1;
        for(i=1;inter[i];i++)
        {
            while(j>=0&&inter[j+1]!=inter[i])
                j=p[j];
            if(inter[j+1]==inter[i])
                j++;
            p[i]=j;
        }

        j=-1;
        int t;
        t=strlen(cry);
        //cout<<cry<<endl;
        for(i=0;cry[i];i++)
        {
            while(j>=0&&inter[j+1]!=cry[i])
                j=p[j];
            if(inter[j+1]==cry[i])
            {
                j++;
            }
            cnt[i]=j;
            if(j==t)
                j=p[j];
        }

        for(i=0;i<len-cnt[t-1]-1;i++)
            printf("%c",inter[i]);
        for(i=0;i<len-cnt[t-1]-1;i++)
            printf("%c",q[inter[i]-'a']);
        printf("\n");
    }
    return 0;
}