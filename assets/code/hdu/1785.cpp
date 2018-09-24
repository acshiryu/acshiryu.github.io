#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct prog{
    double x ;
    double y ;
    double asin0 ;
}po[105];
bool cmp ( prog a , prog b )
{
    return a.asin0<b.asin0;
}
int main()
{
    int n ;
    while ( cin >> n , n >= 0 )
    {
        int i , j ;
        for ( i = 0 ; i < n ; i ++ )
        {
            cin >> po[i].x >> po[i].y ;
            double z = sqrt ( pow ( po[i].x , 2) + pow ( po[i].y , 2 ) ) ;
            po[i].asin0 = acos ( po[i].x / z ) ;
        }
        sort ( po , po + n , cmp ) ;
        for ( i = 0 ; i < n ; i ++ )
        {
            if(i)
                printf(" ");
            printf("%.1lf %.1lf",po[i].x,po[i].y);
        }
        printf("\n");
    }
    return 0;
}