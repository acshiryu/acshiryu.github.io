#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
void gcd ( __int64 a , __int64 b , __int64 &d , __int64 &x ,__int64 &y )
{
    if ( ! b ) 
        d = a , x = 1 , y = 0 ;
    else
        gcd ( b , a % b , d , y , x ) , y -= x * ( a / b ) ;
}
int main()
{
    __int64 a, b , c, k ;
    while ( cin >> a >> b >> c >> k , a || b || c || k )
    {
        __int64 d , x , y ;
        gcd ( c ,  ( ( __int64 ) 1 )<< k , d , x , y ) ;
        if ( ( b - a ) % d != 0 )
            cout << "FOREVER" <<endl;
        else
        {
            __int64 ans = ( b - a ) / d * x ;
            ans = ans % ( (  ( ( __int64 ) 1 )<< k ) / d ) ;
            if ( ans < 0 )
                ans += (  ( ( __int64 ) 1 )<< k ) / d ;
            cout << ans << endl ;
        }
    }
    return 0;
}