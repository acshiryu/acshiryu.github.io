#include<iostream>
#include<cstdio>
using namespace std;
const int mod[3]={1000000007,222222224,183120};
typedef unsigned __int64 uint64;
const int mat_n=2;//矩阵的维度
void matrix_mul(uint64 a[][mat_n],uint64 b[][mat_n],uint64 mod)
{//a=a*b
	uint64 c[mat_n][mat_n];
	int i,j,k;
	for(i=0;i<mat_n;i++)
	{
		for(j=0;j<mat_n;j++)
		{
			c[i][j]=0;
			for(k=0;k<mat_n;k++)
			{
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
			}
		}
	}

	for(i=0;i<mat_n;i++)
		for(j=0;j<mat_n;j++)
			a[i][j]=c[i][j];
}
void matrix_power(uint64 s[][mat_n],uint64 k,uint64 mod)
{// return s[n][n]^k%mod
	uint64 ans[mat_n][mat_n];
	memset(ans,0,sizeof(ans));
	int i,j;
	for(i=0;i<mat_n;i++)
		ans[i][i]=1;

	while(k>0)
	{
		if(k%2==1)
		{
			matrix_mul(ans,s,mod);
		}
		k=k/2;
		matrix_mul(s,s,mod);
	}

	for(i=0;i<mat_n;i++)
		for(j=0;j<mat_n;j++)
			s[i][j]=ans[i][j];
}