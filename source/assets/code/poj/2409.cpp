#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd (int a, int b) 
{ 
	return b ? gcd(b,a%b) : a; 
}
ll polya(int c,int s)
{
	int k;
	ll p[64]; 

	// power of c
	p[0] = 1; 
	for (k=0 ; k<s ; k++) 
		p[k+1] = p[k] * c;

	// reflection part
	ll count = s&1 ? s * p[s/2 + 1] :
	(s/2) * (p[s/2] + p[s/2 + 1]);

	// rotation part
	for (k=1 ; k<=s ; k++) 
		count += p[gcd(k, s)];
	count /= 2 * s;
	return count;
}

int main (void)
{
	int c, s;
	while (scanf("%d%d", &c, &s),c||s) 
	{
		cout<<polya(c,s)<<endl;
	}
	return 0;
}