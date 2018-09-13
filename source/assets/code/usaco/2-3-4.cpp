/* 
ID:shiryuw1 
PROG:money 
LANG:C++ 
*/ 
#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std; 
int sys [ 30 ] ; 
long long money [ 10005 ] [ 30 ] = { 0 } ; 
int main() 
{ 
    freopen("money.in","r",stdin); 
    freopen("money.out","w",stdout); 
    int v , n ; 
    cin >> v >> n ; 
    int i , j , k ; 
    for ( i = 0 ; i < v ; i ++ ) 
    { 
        cin >> sys [ i ] ; 
    } 
    sort ( sys , sys + v );

    for ( i = 0 ; i <= n ; i ++ ) 
    { 
        if ( i % sys [ 0 ] == 0 ) 
            money [ i ] [ 1 ] = 1; 
        else 
            money [ i ] [ 1 ] = 0 ; 
    } 
    for ( i = 2 ; i <= v ; i ++ ) 
    { 
        for ( j = 0 ; j <= n ; j ++ ) 
        { 
            for ( k = 0 ; j >= k * sys [ i - 1 ] ; k ++ ) 
            { 
                money [ j ] [ i ] += money [ j - k * sys [ i - 1 ] ] [ i - 1 ] ; 
            } 
        } 
    }

    printf ( "%lld\n" , money [ n ] [ v ] ); 
    return 0; 
}