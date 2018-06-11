#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct ac {
    int x ;
    int y ;
}po[555555];
int cross(ac a , ac b ,ac c)
{
    return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
}
bool convex(int n)
{
    for(int i = 0 ; i < n ; i ++)
        if(cross(po[i],po[(i+1)%n],po[(i+2)%n])<0)
            return false;
    return true;
}
int main()
{
    int n ;
    while (cin >> n , n)
    {
        for (int i=0;i < n ; i ++ )
            cin >> po[i].x >> po[i].y;
        if (convex(n))
            cout<<"convex"<<endl;
        else
            cout<<"concave"<<endl;
    }
    return 0;
}