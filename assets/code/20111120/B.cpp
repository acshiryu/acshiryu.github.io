#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int m , n , k;
        cin >> m>>n>>k;
        cout<<min((m+n-k)/3,min(m/2,n))<<endl;
    }
    return 0;
}
