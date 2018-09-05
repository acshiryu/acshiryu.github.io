#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100000] , mod[100000] ;
int main()
{
    int c , n ;
    while ( scanf("%d%d",&c,&n) , c || n )
    {
        int i , j ;
        for ( i = 0 ; i < n ; i ++ )
            scanf("%d",&a[i]) , mod[i] = -2 ;//将mod初始化为-2
        mod[0]=-1 ;//mod[0]为-1，就是假设存在a[-1]，且a[-1]是n的倍数，这样就可以把两种情况写在一起
        __int64 sum = 0 ;//直接用sum，省去了另开数组的空间
        for ( i = 0 ; i < n ; i ++ )
        {
            sum += a[i] ;
            if ( mod [ sum % c ] != -2 )
            {//如果在i之前有与sum对n同余的数，则可以输出答案，
                for ( j = mod [ sum % c ] + 1 ; j <= i ; j ++ )
                {
                    cout<<j+1;
                    if ( i != j )
                        cout<<' ';
                }
                cout<<endl;
                break;
            }
            mod [sum%c] = i ;//记录余数对应的是i
        }
    }
    return 0;
}