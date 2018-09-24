/*	素数判断用miller法 分解用pollard法 关键有几点														*\
	1:用2分法作64位乘法必须用unsigned __Int64 否则位移的时候会带符号(符号位移不掉)
	2:pollard会陷入死循环 所以要加卡时 如果超过多少次还没出来就return 1,换个初始数继续
	3:所有<<号,>>号必须全部加括号 像b1=(x<<32)>>32这种等号后面没加括号的是错误的 应该是b1=((x<<32)>>32);
	4:发现pollard算法中用x*x-1产生随机数，如果那个-1改成其他数 效率会不一样 根据frkstyc大牛的代码 
\*	x*x+16381要将近快一倍（可是这位仁兄用的是10007。。。我自己换别的数字试了一下，确实没有更快的）			*/
#define gcc 10007
#define MAX ((INT)1<<63)-1
typedef unsigned long long INT;
INT p[10]={2,3,5,7,11,13,17,19,23,29};
inline INT gcd(INT a,INT b)
{
    INT m=1;
    if(!b)    return a;
    while(m)
    {
        m=a%b;
        a=b;
        b=m;
    }
    return a;
}

//计算a*b%n
inline INT multi_mod(INT a,INT b,INT mod)
{
    INT sum=0;
    while(b)
    {
        if(b&1)    sum=(sum+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return sum;
}

//计算a^b%n;
inline INT quickmod(INT a,INT b,INT mod)
{
    INT sum=1;
    while(b)
    {
        if(b&1)    sum=multi_mod(sum,a,mod);
        a=multi_mod(a,a,mod);
        b>>=1;
    }
    return sum;
}

bool miller_rabin(INT n)
{//素性测试 判断是否为素数
    int i,j,k=0;
    INT u,m,buf;
    //将n分解为m*2^k
    if(n==2)
        return true;
    if(n<2||!(n&1))
        return false;
    m=n-1;
    while(!(m&1))
        k++,m>>=1;
    for(i=0;i<9;i++)
    {
        if(p[i]>=n)
            return true;
        u=quickmod(p[i],m,n);
        if(u==1)
            continue;
        for(j=0;j<k;j++)
        {
            buf=multi_mod(u,u,n);
            if(buf==1&&u!=1&&u!=n-1)
                return false;
            u=buf;
        }
        //如果p[i]^(n-1)%n!=1那么n为合数
        if(u-1)
            return false;
    }
    return true;
}

//寻找n的一个因子，该因子并不一定是最小的，所以下面要二分查找最小的那个因子
INT pollard(INT n)
{
    INT i=1;
    INT x=rand()%(n-1)+1;
    INT y=x;
    INT k=2;
    INT d;
    do
    {
        i++;
        d=gcd(n+y-x,n);
        if(d>1&&d<n)
            return d;
        if(i==k)
            y=x,k*=2;
        x=(multi_mod(x,x,n)+n-gcc)%n;
    }while(y!=x);
    return n;
}

INT MIN;

INT pollard_min(INT n)
{//返回最小质因子
    INT p,a,b=MAX;
    if(n==1)    return MAX;
    if(miller_rabin(n))    return n;
    p=pollard(n);
    a=pollard_min(p);//二分查找
    INT y=n/p;
    b=pollard_min(y);
    return a<b?a:b;
}