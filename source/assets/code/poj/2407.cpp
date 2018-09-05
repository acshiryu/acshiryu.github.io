#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n ;
    while ( scanf ( "%d", & n ) , n )
    {
        if ( n == 1 )
            printf ("0\n") ; 
        else
        {
            int i , j , m;
            m = sqrt ( n + 0.5 ) ;
            int ans = n ;
            for ( i = 2; i <= m ; i ++ )
                if ( n % i == 0)
                {
                    ans = ans / i * ( i - 1 ) ;
                    while ( n % i == 0 ) 
                        n /= i ;
                }
            if ( n > 1 )
                ans = ans / n * ( n - 1 ) ;

            printf ("%d\n",ans);
        }
    }
    return 0;
}