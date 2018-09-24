/**
	两个细节问题
	1.1.因为式子中含有负数，故取模时要
	while(k<0)  
		k+=mod;

	2.矩阵乘法的优化，矩阵乘法时由于多次用到取模，而取模的速度很慢，
	所以要充分利用64位整数的优点，等到算完后再进行取模运算
	c[i][j]=0;
    for(k=0;k<mat_n;k++)
    {
        c[i][j]+=a[i][k]*b[k][j];
    }
	c[i][j]%=mod;
**/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int mat_n=4;//矩阵的维度
void matrix_mul(__int64 a[][mat_n],__int64 b[][mat_n],__int64 mod)
{//a=a*b
    __int64 c[mat_n][mat_n];
    int i,j,k;
    for(i=0;i<mat_n;i++)
    {
        for(j=0;j<mat_n;j++)
        {
            c[i][j]=0;
            for(k=0;k<mat_n;k++)
            {
                 c[i][j]+=a[i][k]*b[k][j];
            }
			c[i][j]%=mod;
        }
    }

    for(i=0;i<mat_n;i++)
        for(j=0;j<mat_n;j++)
            a[i][j]=c[i][j];
}
void matrix_power(__int64 s[][mat_n],__int64 k,__int64 mod)
{// return s[n][n]^k%mod
    __int64 ans[mat_n][mat_n];
    memset(ans,0,sizeof(ans));
    int i,j;
    for(i=0;i<mat_n;i++)
        ans[i][i]=1;

    while(k&gt;0)
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
__int64 a[5];
__int64 s[5];
__int64 abs(__int64 k)
{
	if(k&gt;=0)
		return k;
	return -k;
}
__int64 modfun(__int64 k,__int64 mod)
{
	if(k<0)
	{
		k+=abs(k/mod)*mod;
	}
	while(k<0)
		k+=mod;
	return k%mod;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		__int64 t,n,mod;
		scanf("%I64d%I64d%I64d",&t,&n,&mod);
		a[1]=s[1]=1;
		a[2]=t%mod;
		s[2]=(t*t+1)%mod;
		int i,j;
		for(i=3;i<=4;i++)
		{
			a[i]=modfun(2*t*a[i-1]-a[i-2],mod);
			s[i]=(s[i-1]+(a[i]*a[i]))%mod;
		}

		//for(i=1;i<=4;i++)
		//	cout<<a[i]<<' '<<s[i]<<endl;
		if(n<=4)
		{
			printf("%I64d\n",s[n]);
			continue;
		}

		__int64 mat[mat_n][mat_n];
		memset(mat,0,sizeof(mat));

		mat[0][0]=modfun(4*((t*t)),mod);
		mat[0][1]=modfun(2-8*((t*t)),mod);
		mat[0][2]=mat[0][0];
		mat[0][3]=mod-1;
		mat[1][0]=mat[2][1]=mat[3][2]=1;

		matrix_power(mat,n-4,mod);

		__int64 ans=0;
		for(i=0;i<4;i++)
		{
			ans=(ans+(mat[0][i]*s[4-i]));
		}
		printf("%I64u\n",ans%mod);
	}
	return 0;
}