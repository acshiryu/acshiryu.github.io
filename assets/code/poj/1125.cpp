#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = (1 << 20);    //最大值
int d[105][105];
struct prog
{
    int x,y,d;    //定义起点，终点，所用时间
};
int main()
{
    int n;
    while(cin>>n,n)
    {
        int i,j;

        //先将路径初始化，让d[i][i]=0,d[i][j]=inf;i =/= j;
        for(i=0;i<105;i++)
        {
            for(j=0;j<105;j++)
            {
                if(i==j)
                    d[i][j]=0;
                else
                    d[i][j]=inf;
            }
        }

        //根据输入的数据构造路径，注意题目的起点和终点范围是1……N，而数组是从0开始的，故要把所给的节点-1
        for(i =0;i<n;i++)
        {
            int m;    //从i出发亲密人的个数
            cin>>m;
            for ( j = 0 ; j < m ; j ++)
            {
                int a, b ;        //与i亲密的人及传递谣言的时间
                cin>>a>>b;
                d[i][a-1]=b;
            }
        }

        //Floyd算法，你懂的
        for ( int k = 0 ; k < n ; k ++ )
        {
            for(i = 0 ; i < n ; i ++)
            {
                for ( j = 0 ; j < n ; j ++ )
                {
                    if(d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
            }
        }

        prog dij ,pij;//保存谣言散布的地点，终点，及时间，其中dij表示的是题目要求的，而pij表示的从固定点出发散布到某点的最长时间
        dij.d=inf;//初始时将时间初始化为最大（因为要求的是从任意点出发让所有人知道谣言的最短时间）
        for ( i = 0 ; i < n ; i ++ )
        {
            pij.d=0;//将从i散布谣言所用的时间初始化为0（因为此处要求的是从i出发散布谣言的最大时间）
            for ( j = 0 ; j < n ; j ++ )
            {
                if(pij.d<d[i][j])
                {//如果找到从i到j所用的时间要长与目前找到的从i出发用时的时间，则更新pij
                    pij.d=d[i][j];
                    pij.x=i;
                    pij.y=j;
                }

            }
            //如果从i出发用的时间比目前找到的用的最长时间还要短，则更新dij
            if(dij.d>pij.d)
                dij=pij;
        }
        if(dij.d>=inf)//如果dij还一直是最大值，说明并不能让全部人得知谣言，则输出disjoint。但数据比较水，这个判断可省略 Orz
            cout<<"disjoint"<<endl;
        else//输出起点和时间，注意要将起点标号+1
            cout<<dij.x+1<<' '<<dij.d<<endl;
    }
    return 0;
}