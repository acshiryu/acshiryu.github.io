#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n , m ;
struct matrix {//矩阵
    int a[30][30];
    void init(  )
    {//初始化
        int i ;
        memset ( a, 0 ,sizeof ( a ) ) ;
        for ( i = 0 ; i < 30 ; i ++ )
            a[i][i] = 1 ;
    }
};
void print ( matrix s )
{//打印一个矩阵
    int i , j ;
    for ( i = 0 ; i < n ; i ++ )
    {
        for ( j = 0 ; j < n ; j ++ )
        {
            if ( j )
                cout<<' ';
            cout<<s.a[i][j]%m;
        }
        cout<<endl;
    }
}
matrix matrixadd ( matrix a , matrix b )
{//矩阵加法，计算时记得要取模，避免超int
    int i , j ;
    matrix c ;
    for ( i = 0 ; i < n ; i ++ )
        for ( j = 0  ; j < n ; j ++ )
            c.a[i][j]=((a.a[i][j]+b.a[i][j])%m);
    return c ;
}
matrix matrixmul ( matrix a , matrix b )
{//矩阵乘法，计算时记得要取模，避免超int
    int i , j , k ;
    matrix c ;
    for ( i = 0 ; i < n ; i ++ )
    {
        for ( j = 0 ; j < n ; j ++ )
        {
            c.a[i][j]=0;
            for ( k = 0 ; k < n ; k ++ )
                c.a[i][j] +=((a.a[i][k]*b.a[k][j])%m) ;
            c.a[i][j] %= m ;
        }
    }
    return c ;
}
matrix mul ( matrix s , int k  )
{//矩阵的k次方，快速幂
    matrix ans ;
    ans .init () ;
    while ( k >= 1 )
    {
        if ( k & 1 )
            ans = matrixmul ( ans , s ) ;
        k = k >> 1 ;
        s = matrixmul ( s , s ) ;
    }
    return ans ;
}
matrix sum ( matrix s , int k )
{//举证前k项求和
    if ( k == 1 )
        return s ;
    matrix tmp ;//用来保存答案
    tmp.init();//初始化
    tmp = matrixadd ( tmp , mul ( s , k >> 1 ) );    //计算1+A^(k/2)
    tmp = matrixmul ( tmp , sum ( s , k >> 1 ) ) ;    //计算(1+A^(k/2))*(A + A^2 + A^3 + … + A^(k/2)  )
    if ( k&1 )//考虑是否要+A^k
        tmp = matrixadd ( tmp , mul ( s , k ) ) ;
    return tmp ;//返回前n项的值
}

int main()
{
    int k ;
    while ( cin >> n >> k >> m )
    {
        int i , j ;
        matrix s ;
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
                cin >> s.a[i][j] ;
        s = sum ( s , k ) ;
        print(s);    
    }
    return 0;
}