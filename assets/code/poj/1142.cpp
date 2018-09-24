#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool isprime (int k)
{//判断是否是素数
    int t = sqrt ( k + 0.5 );
    for ( int i = 2 ; i <= t ; i ++ )
        if ( k % i == 0 )
            return false;
    return true;
}
int sum(int k)
{//求出该数各位上的和
    int i , s;
    s = 0 ;
    while ( k != 0 )
    {
        i = k % 10 ;
        s += i ;
        k = k / 10 ;
    }
    return s;
}
int cut (int k )
{//分治法思想，如果是素数，就返回sum，否则，就将该数分成两部分，再来求各部分的质因子的sum
    if ( isprime(k) )
        return sum (k);
    for ( int i = (int) sqrt (k + 0.5) ; i >1 ; i -- )
        if ( k % i == 0 ) 
            return cut (i) + cut (k / i) ;
}
int main()
{
    int n;
    while ( cin >> n , n )
    {
        while ( n ++ )
        {
            if (!isprime(n)&&sum(n)==cut(n))
                break;
        }
        cout<<n<<endl;
    }
}