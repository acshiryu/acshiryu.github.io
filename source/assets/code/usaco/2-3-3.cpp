/* 
ID:shiryuw1 
PROG:zerosum 
LANG:C++ 
*/ 
#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std; 
int n; 
struct prog{ 
    char c[10]; 
    int pre; 
    int next; 
    char op; 
    int k; 
}; 
int add (int a,int b,char c) 
{ 
    switch(c) 
    { 
    case 0:return a;break; 
    case '+':return a+b;break; 
    case '-':return a-b;break; 
    } 
} 
void DFS(prog ans) 
{ 
    int i; 
    if(ans.k==n) 
    { 
        if(add(ans.pre,ans.next,ans.op)==0) 
        { 
            for(i=1;i<=n;i++) 
            { 
                if(i!=1) 
                    cout<<ans.c[i]; 
                cout<<i; 
            } 
            cout<<endl; 
        } 
        return ; 
    } 
    ans.k++; 
    prog tmp; 
    if(ans.op==0) 
    { 
        tmp=ans; 
        tmp.c[tmp.k]=' '; 
        tmp.pre=tmp.pre*10+tmp.k; 
        DFS(tmp);

        tmp=ans; 
        tmp.c[tmp.k]='+'; 
        tmp.next=tmp.k; 
        tmp.op='+'; 
        DFS(tmp); 
        tmp=ans; 
        tmp.c[tmp.k]='-'; 
        tmp.next=tmp.k; 
        tmp.op='-'; 
        DFS(tmp); 
    } 
    else 
    { 
        tmp=ans; 
        tmp.c[tmp.k]=' '; 
        tmp.next=tmp.next*10+tmp.k; 
        DFS(tmp);

        tmp=ans; 
        tmp.c[tmp.k]='+'; 
        tmp.pre=add(tmp.pre,tmp.next,tmp.op); 
        tmp.next=tmp.k; 
        tmp.op='+'; 
        DFS(tmp);

        tmp=ans; 
        tmp.c[tmp.k]='-'; 
        tmp.pre=add(tmp.pre,tmp.next,tmp.op); 
        tmp.next=ans.k; 
        tmp.op='-'; 
        DFS(tmp); 
    } 
} 
int main() 
{ 
    freopen("zerosum.in","r",stdin); 
    freopen("zerosum.out","w",stdout); 
    cin>>n; 
    prog ans; 
    ans.k=1; 
    ans.pre=1; 
    ans.op=0; 
    ans.next=0; 
    ans.c[0]=0; 
    DFS(ans); 
    return 0; 
}