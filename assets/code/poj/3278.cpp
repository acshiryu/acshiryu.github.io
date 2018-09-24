#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
bool hash[400001];    //标记改点是否走过，如果为true则走过
int main()
{
    int m , n ;
    while(cin>> n >> m )
    {
        memset(hash,false,sizeof(hash));//初始化
        pair<int ,int>p;                //第一个代表横坐标，第二个代表走的步子
        p.first=n;
        p.second=0;                        //初始化p
        hash[n]=true;
        queue<pair<int ,int>>bfs;
        bfs.push(p);
        while(!bfs.empty())
        {
            p=bfs.front();        //取队首元素

            if(p.first==m)
            {//此时说明找到了，则输出，并结束搜索
                cout<<p.second<<endl;
                break;
            }

            p.second++;                    //移动次数+1
            pair<int ,int>q;            

            if(p.first<m)
            {//如果改点在目标点的左边
                q=p;
                q.first*=2;                //×2操作
                if(hash[q.first]==false&&q.first)
                {//点没访问过，则从改点开始继续搜索
                    hash[q.first]=true;
                    bfs.push(q);
                }

            //下面搜索同上，注释略
                q=p;
                q.first+=1;                
                if(hash[q.first]==false)
                {
                    hash[q.first]=true;
                    bfs.push(q);
                }

            }

            if(p.first>0)
            {
                q=p;
                q.first--;
                if(hash[q.first]==false)
                {
                    hash[q.first]=true;
                    bfs.push(q);
                }
            }
            bfs.pop();    //队首元素出队列
        }
    }
    return 0;
}