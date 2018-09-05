#include <iostream>  
using namespace std;  

int Extended_Euclid(int a,int b,int &x,int &y)    //扩展欧几里得算法  
{  
    int d;  
    if(b==0)  
    {  
        x=1;y=0;  
        return a;  
    }  
    d=Extended_Euclid(b,a%b,y,x);  
    y-=a/b*x;  
    return d;  
}  

int Chinese_Remainder(int a[],int w[],int len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数  
{  
    int i,d,x,y,m,n,ret;  
    ret=0;  
    n=1;  
    for (i=0;i<len;i++)  
        n*=w[i];  
    for (i=0;i<len;i++)  
    {  
        m=n/w[i];  
        d=Extended_Euclid(w[i],m,x,y);  
        ret=(ret+y*m*a[i])%n;  
    }  
    return (n+ret%n)%n;  
}  

int main()  
{  
    int n;  
    int w[3],a[]={23,28,33};
    int k = 1;
    while (~scanf("%d%d%d%d",&w[0],&w[1],&w[2],&n))     
    {  
        if ( w[0]==-1&&w[1]==-1&&w[2]==-1&&n==-1)
            break;
        int t = Chinese_Remainder(w,a,3) - n ;    //引用中国剩余定理
        t=t % ( 23 * 28 * 33 ) ;
        if ( t <= 0 )
            t += 23 * 28 * 33 ;
        printf("Case %d: the next triple peak occurs in ",k) ;
        printf("%d days.\n",t);  
        k++;
    }  
    return 0;  
}