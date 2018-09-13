#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std; 
int op[105]; 
int cl[105]; 
int n; 
int c; 
int clk=0; 
int opk=0; 
bool found=false; 
struct prog{ 
    int a1; 
    int a2; 
    int a3; 
    int a4; 
    bool str[105]; 
}; 
prog ans[10000]; 
int p=0; 
bool istrue(bool* lap) 
{ 
    int i; 
    for(i=0;i<opk;i++) 
    { 
        if(lap[op[i]-1]!=true) 
            return false; 
    } 
    for(i=0;i<clk;i++) 
    { 
        if(lap[cl[i]-1]!=false) 
            return false; 
    } 
    return true; 
} 
void change(bool* lap,int k) 
{ 
    int st=0; 
    int ad=k; 
    if(k==4) 
    { 
        st=1; 
        ad=2; 
    } 
    int i; 
    for(i=st;i<n;i+=ad) 
        lap[i]=!lap[i]; 
} 
void DFS(bool *lap,int k) 
{ 
    int i,j; 
    if(k/2==c/2) 
    { 
        if(istrue(lap)) 
        { 

            for(j=0;j<n;j++) 
                ans[p].str[j]=lap[j]; 
            for(j=0;j<25;j++) 
            { 
                ans[p].a1=ans[p].a1*2+ans[p].str[j];

            }

            for(j=25;j<50;j++) 
            {

                ans[p].a2=ans[p].a2*2+ans[p].str[j]; 

            }

            for(j=50;j<75;j++) 
            { 
                ans[p].a3=ans[p].a3*2+ans[p].str[j]; 

            }

            for(j=75;j<100;j++) 
            { 
                ans[p].a4=ans[p].a4*2+ans[p].str[j]; 
            } 
            p++; 
            found=true; 
        } 
        return ; 
    } 
    for(i=1;i<=4;i++) 
    { 

        bool tmp[105];

        for(j=0;j<n;j++) 
        { 
            tmp[j]=lap[j]; 
        } 
        change(tmp,i); 
        DFS(tmp,k+1); 
    } 
} 
int cmp(const void *a,const void *b) 
{ 
    if((*(prog *)a).a1!=(*(prog *)b).a1) 
        return (*(prog *)a).a1-(*(prog *)b).a1; 
    if((*(prog *)a).a2!=(*(prog *)b).a2) 
        return (*(prog *)a).a2-(*(prog *)b).a2; 
    if((*(prog *)a).a3!=(*(prog *)b).a3) 
        return (*(prog *)a).a3-(*(prog *)b).a3; 
    return (*(prog *)a).a4-(*(prog *)b).a4;

} 
int main() 
{

    memset(ans,0,sizeof(ans)); 
    bool lap[105]; 
    freopen("lamps.in","r",stdin); 
    freopen("lamps.out","w",stdout); 
    memset(lap,true,sizeof(lap)); 
    cin>>n; 
    cin>>c; 
    while(1) 
    { 
        cin>>op[opk]; 

        if(op[opk]==-1) 
            break; 
        opk++; 
    } 
    while(1) 
    { 
        cin>>cl[clk]; 

        if(cl[clk]==-1) 
            break; 
        clk++; 
    } 
    if(c>4) 
    { 
        if(c%2) 
            c=3; 
        else 
            c=4; 
    } 
    DFS(lap,0); 
    int i,j; 
    if(!found) 
        cout<<"IMPOSSIBLE"<<endl; 
    else 
    { 
        qsort(ans,p,sizeof(ans[0]),cmp); 
        for(i=0;i<p;i++) 
        { 
            if(i&&ans[i].a1==ans[i-1].a1&&ans[i].a2==ans[i-1].a2&&ans[i].a3==ans[i-1].a3&&ans[i].a4==ans[i-1].a4) 
                continue; 
            for(j=0;j<n;j++) 
            { 

                cout<<ans[i].str[j]; 
            } 
            cout<<endl; 
        } 
    } 
    return 0; 
}