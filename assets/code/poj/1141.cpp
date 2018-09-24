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

char s[200];
int dp[200][200];
int ac[200][200];//记录放的位置  表示是xxxy  xxx表示参照点 y表示方的括号种类和具体方位 
				//  当y为-1时表示两边去括号  当为8时分开  党为0-3表示括号的种类  详看printto函数
char to[255];	//括号对应转换成整数  方便存储
void printto(int k)
{
	switch(k)
	{
	case 0:printf(")");break;
	case 1:printf("(");break;
	case 2:printf("]");break;
	case 3:printf("[");break;
	}
}
void print(int i,int j)
{
	if(j<i)
		return ;
	if(ac[i][j]==-1)
	{//属于(S)或[S]类型    则先打印正括号 在打印S  最后打印反括号
		printf("%c",s[i]);
		print(i+1,j-1);
		printf("%c",s[j]);
		return ;
	}
	if(ac[i][j]%10==8)
	{//属于AB  分别打印AB
		print(i,ac[i][j]/10);
		print(ac[i][j]/10+1,j);
		return ;
	}

	//其他就属于(S ,[S ,S] ,S)类型  根据括号的位置打印
	if(ac[i][j]/10==i)
	{//属于(S ,[S 类型  先打印正反括号 再打印S
		if(to[s[i]]<2)
			printf("()");
		else
			printf("[]");
		print(i+1,j);

	}
	else
	{//属于S] ,S)类型 先打印S 再打印正反括号
		print(i,j-1);
		if(to[s[j]]<2)
			printf("()");
		else
			printf("[]");
	}
	return ;

}
int main()
{
	to['(']=0;to[')']=1;to['[']=2;to[']']=3;
	while(gets(s))
	{//因为测试数据中有空串  不能用scanf读取字符串，很多人就是wa在这里
		int i,j,k;
		int len=strlen(s);
		zero(dp);
		zero(ac);
		for(i=0;i<len;i++)
		{//初始化
			dp[i][i]=1;
			ac[i][i]=i*10+to[s[i]];
		}
		for(j=1;j<len;j++)
		{
			for(i=0;i+j<len;i++)
			{
				if((to[s[i]]^to[s[i+j]])==1&&((to[s[i]]%2)==0))
				{//如果能够表示成（S）和[S]情况的话
					if(j!=1)
						dp[i][i+j]=dp[i+1][i+j-1];
					else
						dp[i][i+j]=0;
					ac[i][i+j]=-1;
				}
				else
				{
					//表示成(S或者[S  则需要在i位置补全为()S或者[]S
					dp[i][i+j]=dp[i+1][i+j]+1;
					ac[i][i+j]=(i)*10+to[s[i]];
					if(dp[i][i+j]>dp[i][i+j-1]+1)
					{//表示成S)或者S]  则需要在i位置补全为S()或者S[]  ac记录最后一位的数字
						dp[i][i+j]=dp[i][i+j-1]+1;
						ac[i][i+j]=(i+j)*10+to[s[i+j]];
					}
				}
				//划分成A B 两部分向更小的部分递推  此时ac数组记录分开的位置
				for(k=i+1;k<i+j-1;k++)
				{
					if(dp[i][i+j]>dp[i][k]+dp[k+1][i+j])
					{
						dp[i][i+j]=dp[i][k]+dp[k+1][i+j];
						ac[i][i+j]=k*10+8;
					}
				}
			}
		}
		//打印结果
		print(0,len-1);
		printf("\n");
	}
    return 0;
}