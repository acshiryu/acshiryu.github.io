title: USACO 2.2.3 Runaround Numbers解题报告
toc: true
tags:
  - 循环
  - 枚举
categories:
  - 算法竞赛
id: 901
date: 2012-03-07 23:02:17
---

题目大意就是给出一个M，求比M大得最小的一个“循环数”

*   如果你从最左边的数字开始 ( 在这个例子中是8) 数最左边这个数字个数字到右边(回到最左边如果数到了最右边),你会停止在另一个新的数字(如果没有停在一个不同的数字上，这个数就不是循环数). 就像: 8 1 3 6 2 从最左边接下去数8个数字: 1 3 6 2 8 1 3 6 所以下一个数字是6
*   重复这样做 (这次从“6”开始数6个数字) 并且你会停止在一个新的数字上: 2 8 1 3 6 2, 也就是2.
*   再这样做 (这次数两个): 8 1
*   再一次 (这次一个): 3
*   又一次: 6 2 8 这是你回到了起点, 在从每一个数字开始数1次之后. 如果你在从每一个数字开始数一次以后没有回到起点, 你的数字不是一个循环数。

这题可以从M开始，一个个枚举数据，知道遇到循环数，没什么技术含量
[code lang="cpp"]
/*
 ID:shiryuw1
 PROG:runround
 LANG:C++
 */
 #include&lt;iostream&gt;
 #include&lt;cstdlib&gt;
 #include&lt;cstdio&gt;
 #include&lt;cstring&gt;
 #include&lt;algorithm&gt;
 #include&lt;cmath&gt;
 using namespace std;
 bool isrod(unsigned m)
 {
     unsigned t=m;
     bool num[10]={false};
     char str[20]={0};
     sprintf(str,&quot;%u&quot;,m);
     char ch=str[0];
     char len=strlen(str);
     int k=0;
     num[str[0]-'0']=true;
     k=(k+(str[0]-'0'))%len;
     while(k)
     {
         if(num[str[k]-'0'])
         {
             return false;
         }
         num[str[k]-'0']=true;
         k=(k+(str[k]-'0'))%len;
     }
     int i,sum=0;
     for(i=0;i&lt;10;i++)
         sum+=num[i];
     if(sum&lt;((int)log10(1.0*m)+1))
         return false;
     return true;
 }
 int main()
 {
     freopen(&quot;runround.in&quot;,&quot;r&quot;,stdin);
     freopen(&quot;runround.out&quot;,&quot;w&quot;,stdout);
     unsigned m;
     scanf(&quot;%u&quot;,&amp;m);
     m++;
     while(m)
     {
         bool tag=false;
         unsigned t=m;
         unsigned num[10]={0};
         unsigned k=1
         while(t)
         {

             int s=t%10;
             if(s==0)
             {
                 m+=k;
                 tag=true;
                 break;
             }
             if(num[s]!=0)
             {
                 m+=num[s];
                 tag=true;;
                 break;
             }
             num[s]=k;
             k*=10;
             t/=10;
         }
         if(tag)
         {
             continue;
         }
         if(isrod(m)==true)
         {
             printf(&quot;%u\n&quot;,m);
             break;
         }
         else
             m++;
     }
     return 0;
 }[/code]