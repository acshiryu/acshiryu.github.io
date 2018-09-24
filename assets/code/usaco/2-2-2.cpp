/* 
ID:shiryuw1 
PROG:subset 
LANG:G++ //64位整数要用long long
*/ 
#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std; 
int sum=0; 
int n; 
long long fid[40][2000]; //是否寻找过dp(k,a+1000),当为-1时为否
long long dp(int k,int a) 
{ 
    if(k==0) 
    { //当为0时不合要求，故返回0
        return 0; 
    } 
    if(k==1) 
    { //当为1是可知只有可能两边的集合相差只能为1或-1
        if(abs(a)==1) 
            return 1; 当相差为1或-1时，则有一种情况符合
        return 0; 
    } 
    if(k==2) 
    { //理由同k=1时
        if(abs(a)==1||abs(a)==3) 
            return 1; 
        return 0; 
    } 
    if(fid[k][a+1000]==-1) //如果k,a没有访问过，则访问，并将访问结果存在该数组中，很明显该数组的结果不会再是-1否则直接返回fid[k][a+1000]，避免重复搜索。
        fid[k][a+1000]=dp(k-1,a+k)+dp(k-1,a-k); 
    return fid[k][a+1000]; 
}

int main() 
{ 
    freopen("subset.in","r",stdin); 
    freopen("subset.out","w",stdout); 
    cin>>n; 
    memset(fid,-1,sizeof(fid)); //初始化fid数组为-1
    printf("%lld\n",dp(n,0)/2); //寻找把1……N分成两组后使两组相差0的情况数
    return 0; 
}