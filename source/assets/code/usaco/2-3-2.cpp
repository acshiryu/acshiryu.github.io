/* 
ID:shiryuw1 
PROG:nocows 
LANG:C++ 
*/ 
#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
usingnamespace std; 
int a[222][111]={0};//表示i个节点构造题目要求的深度为j的二叉树的个数
int main() 
{ 
    freopen("nocows.in","r",stdin); 
    freopen("nocows.out","w",stdout); 
int n,m; 
int i,j,h1,h2; 
    cin>>n>>m; 
    a[1][1]=1; //1个节点构造深度为一的二叉树只有1中情况
for(i=1;i<=n;i+=2) 
{ //i代表左子树的节点数，故要小于n
for(j=1;j<=i&&i+j<n;j+=2) 
        { // j代表右子树的节点数，故要i+j<n
//又由分析，左右可以交换，故规定j<=i
for(h1=1;h1<m;h1++) 
            { //h1表示左子树的深度，可知;h1<m
for(h2=1;h2<=h1;h2++) 
                {  //h2表示右子树的深度，又左右可以交换，故规定;h2<=h1
int ii=i+j+1; //左右子树的节点加上根节点
int h=h1+1;//由规定知h1>=h2，故h=max{h1,h2}+1=h1+1
if(i==j&&h1==h2) 
//如果有i=j和h1=h2，则不能交换左右子树
                        a[ii][h]=((a[ii][h]+a[i][h1]*a[j][h2]))%9901; 
elseif(h1==h2||i==j) 
//当只有h1=h2或i=j时可以交换左右子树的节点数
                        a[ii][h]=(a[ii][h]+2*a[i][h1]*a[j][h2])%9901; 
else 
//否则既要交换i和j也要交换左右深度a[ii][h]=(a[ii][h]+2*a[i][h1]*a[j][h2]+2*a[i][h2]*a[j][h1])%9901; 
                } 
            } 
        } 
    } 
    cout<<a[n][m]<<endl; //输出n个节点构造shendu为m的满足条件的二叉树个数
return0; 
}