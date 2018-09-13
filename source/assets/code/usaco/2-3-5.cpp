#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std; 
int map [ 105 ] [ 105 ] = { 0 } ;     //初始时i拥有j的股份的多少
int nmap [ 105 ] [ 105 ] = { 0 } ;    //通过传递时，i拥有j股份的多少
bool con [ 105 ] [ 105 ] = { false } ; //当为true时表示i能管理j
int main() 
{ 
    //因为USACO都是通过读取文件的形式来验证程序的
    freopen("concom.in","r",stdin);   
    freopen("concom.out","w",stdout); 
    int n ; 
    cin >> n ; 
    int i , j , k ; 
    for ( i = 0 ; i < n ; i ++ ) 
    { 
        int a , b , c ; 
        cin >> a >> b >> c ;   //a拥有b的c%的股份
        map [ a ] [ b ] = c ; 
        if ( c >= 50 )         //当股份超过50%时则说明a能管理b
            con [ a ] [ b ] = true ; 
    }

    for ( i = 1 ; i <= 100 ; i ++ ) 
    { 
        con [ i ] [ i ] = true ; 
        bool tag = true ;//判断是否又有新公司能被i管理，当为false时
                          //说明已无新公司可被i管理，则从下一个i开始
        while ( tag ) 
        { 
            tag = false ; //初始时标记为无公司加入
            for ( j = 1 ; j <= 100 ; j ++ ) 
            { 
                if ( ! con [ i ] [ j ]) 
                {      //如果i不能管理j,则看规则是否能符合第三条
                    int sum = 0 ; //定义i间接拥有j的股份
                    for ( k = 1 ; k <= 100 ; k ++ ) 
                    { 
                        if  ( con [ i ] [ k ] ) 
          {//i能管理k,，则i间接拥有j股份值要加上k拥//j有的股份值
                            sum += map [ k ] [ j ] ; 
                        }

                    } 
                    if ( sum > 50 ) 
                    { //如果间接拥有股份值超过50%，则i能管理j
                        tag = true ; //标记为true,有新公司被管理
                        con [ i ] [ j ] = true ; 
                    } 
                } 
            } 
        } 
    } 
    for ( i = 1 ; i <= 100 ; i ++ ) 
    { 
        for ( j = 1 ; j <= 100 ; j ++ ) 
        { //输出i能管理j的情况，要排除i=j
            if ( con [ i ] [ j ] && i != j ) 
                cout << i << ' ' << j << endl ; 
        } 
    }
    return 0; 
}