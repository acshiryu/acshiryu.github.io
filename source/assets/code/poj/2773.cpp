#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
usingnamespace std;
int pri[1000000];
int gcd ( int a , int b ) 
{
    return b ==0? a : gcd ( b , a % b ) ;
}
int main()
{
    int m , k ;
    while ( cin >> m >> k ) 
    {
        int i , j ;
        for ( i =1 , j =0 ; i <= m ; i ++ )
            if ( gcd ( m , i ) ==1 )
                pri [ j ++ ] = i ;

        if ( k%j !=0)
            cout <<k/j * m +pri[k%j-1] << endl;
        else//要特别考虑k%j=0的情况，因为数组是从0开始的，第i个对应的是pri[i-1]
            cout << (k/j-1)*m+pri[j-1] << endl ;
    }
    return0;
}