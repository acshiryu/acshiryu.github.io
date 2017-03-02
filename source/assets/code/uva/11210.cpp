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

char mj[50][10];
int mj_num;
int a[50];
int own[15];
int own_num;
inline void init()
{
	mj_num=0;
	zero(mj);
	int i;
	for(i=1;i<10;i++,mj_num++)
	{
		mj[mj_num][0]=i+'0';
		mj[mj_num][1]='T';
	}
	for(i=1;i<10;i++,mj_num++)
	{
		mj[mj_num][0]=i+'0';
		mj[mj_num][1]='S';
	}
	for(i=1;i<10;i++,mj_num++)
	{
		mj[mj_num][0]=i+'0';
		mj[mj_num][1]='W';
	}
	strcpy(mj[mj_num++],"DONG");
	strcpy(mj[mj_num++],"NAN");
	strcpy(mj[mj_num++],"XI");
	strcpy(mj[mj_num++],"BEI");
	strcpy(mj[mj_num++],"ZHONG");
	strcpy(mj[mj_num++],"FA");
	strcpy(mj[mj_num++],"BAI");
}
int mj_num_cnt(char *s)
{
	if(s[1]=='T')
		return s[0]-'0'-1;
	if(s[1]=='S')
		return s[0]-'0'+8;
	if(s[1]=='W')
		return s[0]-'0'+17;
	int i;
	for(i=27;i<34;i++)
		if(strcmp(s,mj[i])==0)
			return i;
}
int ans[50];
int ans_num;
void DFS(int mj_i,int sd)
{
	int i,j,k;
	if(ans_num>0&&ans[ans_num-1]==mj_i)
		return ;
	if(sd==5)
	{
		ans[ans_num++]=mj_i;
		return ;
	}
	bool dt=true;
	for(i=0;i<own_num;i++)
	{
		j=own[i];
		if(a[j]==0)
			continue;
		if(a[j]==3)
		{
			a[j]-=3;
			DFS(mj_i,sd+1);
			a[j]+=3;
		}
		if( (j<9&&j>1) ||(j<18&&j>10) ||(j<27&&j>19))
		{
			if(a[j-1]>0&&a[j-2]>0&&a[j]>0)
			{
				a[j-1]--;
				a[j-2]--;
				a[j]--;
				DFS(mj_i,sd+1);
				a[j-1]++;
				a[j-2]++;
				a[j]++;
				dt=false;
			}
		}

		if( (j<8&&j>0) ||(j<17&&j>9) ||(j<26&&j>18))
		{
			if(a[j-1]>0&&a[j+1]>0&&a[j]>0)
			{
				a[j-1]--;
				a[j+1]--;
				a[j]--;
				DFS(mj_i,sd+1);
				a[j-1]++;
				a[j+1]++;
				a[j]++;
				dt=false;
			}
		}

		if( (j<7&&j>=0) ||(j<16&&j>=9) ||(j<25&&j>=18))
		{
			if(a[j+2]>0&&a[j+1]>0&&a[j]>0)
			{
				a[j+2]--;
				a[j+1]--;
				a[j]--;
				DFS(mj_i,sd+1);
				a[j+2]++;
				a[j+1]++;
				a[j]++;
				dt=false;
			}
		}
		if(dt==false)
			break;
	}

}
int main()
{
	int i,j;
	int cas=1;
	init();
	char s[10];
//	cout<<mj_num_cnt("FA")<<' '<<mj[32]<<endl;
	while(zero(a),~scanf("%s",s))
	{
		if(s[0]=='0')
			break;
		zero(own);
		j=mj_num_cnt(s);
		own[0]=j;
		own_num=1;
		a[j]++;
		for(i=1;i<13;i++)
		{
			scanf("%s",s);
			j=mj_num_cnt(s);
			if(a[j]==0)
			{
				own[own_num++]=j;
			}
			a[j]++;
		}

		ans_num=0;
		for(i=0;i<34;i++)
		{
			if(a[i]==4)
				continue;
			if(a[i]==0)
			{
				own[own_num++]=i;
			}
			a[i]++;

			for(j=0;j<own_num;j++)
			{
				if(a[own[j]]>=2)
				{
					a[own[j]]-=2;
					DFS(i,1);
					a[own[j]]+=2;
				}
			}
			if(a[i]==1)
				own_num--;
			a[i]--;
		}
		printf("Case %d: ",cas++);
		if(ans_num==0)
		{
			printf("Not ready\n");
			continue;
		}
		for(i=0;i<ans_num;i++)
		{
			if(i)
			{
				printf(" ");
			}
			printf("%s",mj[ans[i]]);
		}
		printf("\n");
	}
    return 0;
}