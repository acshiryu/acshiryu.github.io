#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int phi[1005];
int main()
{
    int i , j ;
    memset ( phi , 0 ,sizeof ( phi ) ) ;
    phi[1]=1;
    for ( i = 2 ; i <1005 ; i ++ )
    {//筛选求phi
        if ( ! phi [i] )
        {
            for ( j = i ; j <1005 ; j += i )
            {
                if ( ! phi [j] )
                    phi [j ] = j ;
                phi [j] = phi [j] / i * ( i - 1 ) ;
            }
        }
    }
    int t ;
    int k = 1 ;
    cin >> t ;
    while ( t-- )
    {
        int n ;
        cin >> n ;
        cout << k << ' ' << n << ' ';
        int sum = 3 ;//特别考虑的三个点，（1，0）（0，1）（1，1）
        for ( i = 2 ; i <= n ; i ++ )
            sum += 2 *(phi [i] );
        cout<<sum<<endl;
        k++;
    }
    return 0;
}