#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct prog{
    int x,y;
}a[30005];
int t[30005];
bool cmp(prog a,prog b)
{
    return a.x<b.x;
}
int cnt;
void merge(int x,int y)
{
    if(y-x>1)
    {
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        merge(x,m);
        merge(m,y);
        while(p<m||q<y)
        {
            if(q>=y||(p<m&&a[p].y<=a[q].y))
            {
                t[i++]=a[p++].y;
            }
            else
            {
                t[i++]=a[q++].y;
                cnt+=m-p;
            }
        }
        for(i=x;i<y;i++)
            a[i].y=t[i];
    }
}
int main()
{
    int x,y;
    while(~scanf("%d%d",&x,&y))
    {
        int n;
        scanf("%d",&n);
        int i,j,k,b;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&k,&b);
            a[i].x=k*x+b;
            a[i].y=k*y+b;
        }
        sort(a,a+n,cmp);
        cnt=0;
        merge(0,n);
        cout<<n+cnt+1<<endl;
    }
    return 0;
}