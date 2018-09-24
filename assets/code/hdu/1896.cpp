#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct Stone{
    int x;    //石头的初始地
    int y;    //石头能扔的最远距离
};
bool operator<( Stone a, Stone b )
{ //重载小于，按照结构体中x小的在队顶，如果x一样，则按照y的最小的在//队顶
    if( a.x== b.x ) return a.y > b.y;  
    return a.x > b.x;   
}  
int main()
{
    int t;
    scanf("%d",&t);//测试数据个数
    while(t--)
    {
        int n;
        int i ;
        priority_queue<Stone>que;     //定义一个Stone成员的优先//队列
        scanf("%d",&n);
        Stone tmp;
        for(i =0;i< n ; i++ )
        {
            scanf("%d%d",&tmp.x,&tmp.y);
            que.push(tmp);//入队
        }
        int sum =1;//判断碰到的是第几个石头的标记
        while(!que.empty())//当队列为空就跳出循环，也就是说再//向前就没有石头可以遇到
        {
        tmp = que.top();//去队顶元素，也就是在后面的所有//石头中第一个碰到的石头
            que.pop();//出对
            if(sum%2)
            {//如果是奇数号石头，则处理，否则不做处理
                tmp . x+=tmp.y;//则向前扔y单位长度
                que.push(tmp);//扔出去的石头入队
            }
            sum++;//石头计数+1
        }
        printf("%d\n",tmp.x);//打印最后一块石头的坐标就是所求//的最远距离
    }
    return 0;
}