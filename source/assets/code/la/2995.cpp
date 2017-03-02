#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define zero(a) memset(a,0,sizeof(a))
#define one(a) memset(a,1,sizeof(a))
#define fone(a) memset(a,-1,sizeof(a))
#define pow2(a) ((a)*(a))
#define pow3(a) ((pow2(a))*(a))

int n;
char tx[15][15][15];
char kan[10][15][15];
void xyz(int k,int i,int j,int len,int& x,int& y , int& z)
{
	switch(k)
	{
	case 0:
		x=len;
		y=j;
		z=i;
		break;
	case 1:
		x=n-1-j;
		y=len;
		z=i;
		break;
	case 2:
		x=n-1-len;
		y=n-1-j;
		z=i;
		break;
	case 3:
		x=j;
		y=n-1-len;
		z=i;
		break;
	case 4:
		x=n-1-i;
		y=j;
		z=len;
		break;
	case 5:
		x=i;
		y=j;
		z=n-1-len;
		break;
	default:break;
	}
}

int main()
{
	while(scanf("%d",&n),n)
	{
		int i,j,k,p,q;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					tx[i][j][k]='#';

		for(i=0;i<n;i++)
			for(j=0;j<6;j++)
				scanf("%s",kan[j][i]);
/*
		for(k=0;k<6;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					cout<<kan[k][i][j];
				cout<<endl;
			}
			cout<<endl;
		}
*/

		for(k=0;k<6;k++)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(kan[k][i][j]=='.')
					{
						for(p=0;p<n;p++)
						{
							int x,y,z;
							xyz(k,i,j,p,x,y,z);
							tx[x][y][z]='.';
					//		cout<<x<<' '<<y<<' '<<z<<endl;
						}
					//	cout<<endl;
					}

		}
		while(1)
		{
			bool ok=true;
			for(k=0;k<6;k++)
			{
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
						if(kan[k][i][j]!='.')
						{
							for(p=0;p<n;p++)
							{
								int x,y,z;
								xyz(k,i,j,p,x,y,z);
								//cout<<x<<y<<z<<endl;
								//cout<<tuxing<<endl;
								if(tx[x][y][z]=='.')
									continue;
								if(tx[x][y][z]=='#')
								{
									tx[x][y][z]=kan[k][i][j];
									break;
								}
								if(tx[x][y][z]==kan[k][i][j])
								{
									break;
								}
								tx[x][y][z]='.';
								ok=false;
							}
						}
			}
			if(ok==true)
				break;
		}
		int sum=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(tx[i][j][k]!='.')
						sum++;

		printf("Maximum weight: %d gram(s)\n",sum);

	}
    return 0;
}