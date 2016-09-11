#include<iostream>
#include<cstdlib>
using namespace std;
char s1[65],s2[65];
void change(char *a,int k)
{
    while(*a)
    {
        if((*a)=='5'||(*a)=='6')
            (*a)=k+'0';
        a++;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s1>>s2;
        change(s1,5);
        change(s2,5);
        cout<<atoi(s1)+atoi(s2)<<' ';
        change(s1,6);
        change(s2,6);
        cout<<atoi(s1)+atoi(s2)<<endl;
    }
}
