title: hdu2971Tower 矩阵快速幂
toc: true
tags:
  - 快速幂
  - 矩阵
  - 递推
categories:
  - 算法竞赛
id: 1601
date: 2012-09-21 17:20:37
---

从题意中可得出两个递推关系：
![](/wp-content/uploads/2012/09/2971_13.png "2971_1")

要求Sn，显然这题是矩阵快速幂的问题，所以我们首先要将两个递推公式合并成一个只含有Sn递推的公式

显然，第二个式子含有平方项，所以，首先我们要将第一式平方并带入Sn中
![](/wp-content/uploads/2012/09/2971_2.png "2971_2")

这样就可以运用矩阵快速幂求Sn了
[code lang="cpp"]
/**
	两个细节问题
	1.1.因为式子中含有负数，故取模时要
	while(k&amp;lt;0)  
		k+=mod;

	2.矩阵乘法的优化，矩阵乘法时由于多次用到取模，而取模的速度很慢，
	所以要充分利用64位整数的优点，等到算完后再进行取模运算
	c[i][j]=0;
    for(k=0;k&amp;lt;mat_n;k++)
    {
        c[i][j]+=a[i][k]*b[k][j];
    }
	c[i][j]%=mod;
**/
#include&amp;lt;iostream&amp;gt;
#include&amp;lt;cstdio&amp;gt;
#include&amp;lt;cmath&amp;gt;
using namespace std;
const int mat_n=4;//矩阵的维度
void matrix_mul(__int64 a[][mat_n],__int64 b[][mat_n],__int64 mod)
{//a=a*b
    __int64 c[mat_n][mat_n];
    int i,j,k;
    for(i=0;i&amp;lt;mat_n;i++)
    {
        for(j=0;j&amp;lt;mat_n;j++)
        {
            c[i][j]=0;
            for(k=0;k&amp;lt;mat_n;k++)
            {
                 c[i][j]+=a[i][k]*b[k][j];
            }
			c[i][j]%=mod;
        }
    }

    for(i=0;i&amp;lt;mat_n;i++)
        for(j=0;j&amp;lt;mat_n;j++)
            a[i][j]=c[i][j];
}
void matrix_power(__int64 s[][mat_n],__int64 k,__int64 mod)
{// return s[n][n]^k%mod
    __int64 ans[mat_n][mat_n];
    memset(ans,0,sizeof(ans));
    int i,j;
    for(i=0;i&amp;lt;mat_n;i++)
        ans[i][i]=1;

    while(k&amp;gt;0)
    {
        if(k%2==1)
        {
            matrix_mul(ans,s,mod);
        }
        k=k/2;
        matrix_mul(s,s,mod);
    }

    for(i=0;i&amp;lt;mat_n;i++)
        for(j=0;j&amp;lt;mat_n;j++)
            s[i][j]=ans[i][j];
}
__int64 a[5];
__int64 s[5];
__int64 abs(__int64 k)
{
	if(k&amp;gt;=0)
		return k;
	return -k;
}
__int64 modfun(__int64 k,__int64 mod)
{
	if(k&amp;lt;0)
	{
		k+=abs(k/mod)*mod;
	}
	while(k&amp;lt;0)
		k+=mod;
	return k%mod;
}
int main()
{
	int T;
	scanf(&amp;quot;%d&amp;quot;,&amp;amp;T);
	while(T--)
	{
		__int64 t,n,mod;
		scanf(&amp;quot;%I64d%I64d%I64d&amp;quot;,&amp;amp;t,&amp;amp;n,&amp;amp;mod);
		a[1]=s[1]=1;
		a[2]=t%mod;
		s[2]=(t*t+1)%mod;
		int i,j;
		for(i=3;i&amp;lt;=4;i++)
		{
			a[i]=modfun(2*t*a[i-1]-a[i-2],mod);
			s[i]=(s[i-1]+(a[i]*a[i]))%mod;
		}

		//for(i=1;i&amp;lt;=4;i++)
		//	cout&amp;lt;&amp;lt;a[i]&amp;lt;&amp;lt;' '&amp;lt;&amp;lt;s[i]&amp;lt;&amp;lt;endl;
		if(n&amp;lt;=4)
		{
			printf(&amp;quot;%I64d\n&amp;quot;,s[n]);
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
		for(i=0;i&amp;lt;4;i++)
		{
			ans=(ans+(mat[0][i]*s[4-i]));
		}
		printf(&amp;quot;%I64u\n&amp;quot;,ans%mod);
	}
	return 0;
}
[/code]