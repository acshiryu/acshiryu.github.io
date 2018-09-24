#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[10000] ;
int mod[10000] ;//mod存储判断sum%n是否出现过，如果没出现时-1，如果出现，则是此时sum对应的k值，即前k项和
int sum [10001];//sum存储的与描述略有不同，sum[k]=a[0]+a[1]+...+a[k-1]；
int main()
{
    int n ;
    int i ;
    while ( cin >> n )
    {
        memset ( mod , -1 , sizeof ( mod ) ) ;
        sum[0]=0;
        for ( i = 0 ; i < n ; i ++ )
        {
            cin >> a[i] ;
        }
        for ( i = 0 ; i < n ; i ++ )
        {
            sum[i+1]=sum[i]+a[i];

            if ( sum [i+1] % n == 0 )
            {//如果是N的倍数，则输出
                int j ;
                cout<<i+1<<endl;
                for ( j = 0 ; j <= i ; j ++ )
                    cout<<a[j]<<endl;
                break;
            }
            if ( mod[sum [i+1] % n]!=-1)
            {//如果找到两个数的余数相同，则依次输出
                int j ;
                cout<<i-mod[sum [i+1] % n]<<endl;
                for ( j = mod[sum [i+1] % n]+1 ; j <= i ; j ++ )
                    cout<<a[j]<<endl;
                break;
            }
            mod[sum [i+1] % n]=i;//将此时对应的余数存到mod中，值为此时的i
        }
    }
    return 0;
}