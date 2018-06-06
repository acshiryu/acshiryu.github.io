title: 欧拉函数模板
toc: true
tags:
  - 欧拉函数
  - 筛选
categories:
  - 模板编程
id: 1017
date: 2012-08-03 16:00:10
---

对正整数n，欧拉函数是少于或等于n的数中与n互质的数的数目。例如euler(8)=4，因为1,3,5,7均和8互质。

Euler函数表达通式：euler(x)=x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)…(1-1/pn),其中p1,p2……pn为x的所有素因数，x是不为0的整数。euler(1)=1（唯一和1互质的数就是1本身）。 

欧拉公式的延伸：一个数的所有质因子之和是euler(n)*n/2。

那么如何变成实现欧拉函数呢？下面通过两种不同的方法来实现。第一种方法是直接根据定义来实现，同时第一种方法也是第二种筛法的基础，当好好理解。

[code lang="cpp"]
//直接求解欧拉函数  
int euler(int n){ //返回euler(n)   
     int res=n,a=n;  
     for(int i=2;i*i&lt;=a;i++){  
         if(a%i==0){  
             res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出   
             while(a%i==0) a/=i;  
         }  
     }  
     if(a&gt;1) res=res/a*(a-1);  
     return res;  
}  

//筛选法打欧拉函数表   
#define Max 1000001  
int euler[Max];  
void Init(){   
     euler[1]=1;  
     for(int i=2;i&lt;Max;i++)  
       euler[i]=i;  
     for(int i=2;i&lt;Max;i++)  
        if(euler[i]==i)  
           for(int j=i;j&lt;Max;j+=i)  
              euler[j]=euler[j]/i*(i-1);//先进行除法是为了防止中间数据的溢出   
}  
[/code]

原文：http://blog.csdn.net/once_hnu/article/details/6302868