/*
ID:shiryuw1
PROG:runround
LANG:C++
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool isrod(unsigned m)
{
    unsigned t=m;
    bool num[10]={false};
    char str[20]={0};
    sprintf(str,"%u",m);
    char ch=str[0];
    char len=strlen(str);
    int k=0;
    num[str[0]-'0']=true;
    k=(k+(str[0]-'0'))%len;
    while(k)
    {
        if(num[str[k]-'0'])
        {
            return false;
        }
        num[str[k]-'0']=true;
        k=(k+(str[k]-'0'))%len;
    }
    int i,sum=0;
    for(i=0;i<10;i++)
        sum+=num[i];
    if(sum<((int)log10(1.0*m)+1))
        return false;
    return true;
}
int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    unsigned m;
    scanf("%u",&m);
    m++;
    while(m)
    {
        bool tag=false;
        unsigned t=m;
        unsigned num[10]={0};
        unsigned k=1
        while(t)
        {

            int s=t%10;
            if(s==0)
            {
                m+=k;
                tag=true;
                break;
            }
            if(num[s]!=0)
            {
                m+=num[s];
                tag=true;;
                break;
            }
            num[s]=k;
            k*=10;
            t/=10;
        }
        if(tag)
        {
            continue;
        }
        if(isrod(m)==true)
        {
            printf("%u\n",m);
            break;
        }
        else
            m++;
    }
    return 0;
}