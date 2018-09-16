title: Linux命令之Crontab学习笔记
toc: true
tags:
 - Linux
 - crontab
categories:
 - 学习笔记
date: 2018-09-16 10:25:00
---
## crontab介绍

crontab是unix下设置周期性执行任务的工具，类似于windows的计划任务。当系统启动时会自动启动cron进程并后台运行，系统每分钟就启动一次cron服务并检查是否有可执行的任务，若有则会自动执行该任务。

## 安装crond服务

Linux系统一般都默认安装有crond服务，可跳过该步

安装crond服务
``` bash
yum install vixie-cron  #vixie-cron是cron主程序
yum install crontabs    #crontabs软件包是用来安装、卸装、或列举用来驱动 cron 守护进程的表格的程序
```
启动crond服务
``` bash
service crond start
```
查看crond服务是否启动
``` bash
service crond status
```
设置开机启动
``` bash
chkconfig crond on
```
<!--more-->
## crontab格式
crontab格式为5个\*加上一个任务命令
``` bash
* * * * * COMMAND  
```
第一个\*表示分钟，范围0~59     
第二个\*表示小时，范围0~23  
第三个\*表示日期，范围1~31  
第四个\*表示月份，范围1~12
第五个\*表示星期，范围0~7，其中0和7都表示星期天   
代表在特定的时间执行COMMAND，若要每隔一定的时间执行COMMAND，则在\*后紧跟/

- \*表示任何时候都匹配  
- 可以用“A,B,C”表示A或者B或者C时执行一次命令
- 可以用“A-B”表示A到B之间时执行一次命令
- 可以用“X/A”表示每A分钟(小时等)执行一次命令，会先满足X约束，再满足A条件

## crontab应用举例
每晚22:30重启mysql服务
``` bash
30 22 * * * service mysqld restart
```
每月5,15,25日的21:45重启mysql服务
``` bash
45 21 5,15,25 * * service mysqld restart
```
每月1到15日的22:45重启mysql服务
``` bash
45 22 1-15 * * service mysqld restart
```
每隔5分钟重启mysql服务
``` bash
*/5 * * * * service mysqld restart
```
晚上22点至6点间每隔1小时重启mysql服务
``` bash
0 22-6/1 * * * service mysqld restart
```
晚上22点至6点间每隔30分钟重启mysql服务
``` bash
0,30 22-6 * * * service mysqld restart
```
或者
``` bash
0-59/30 22-6 * * * service mysqld restart
```

## crontab基本命令
crontab命令大全
``` bash 
crontab [-u user] file  
crontab [-u user ] [ -i ] { -e | -l | -r }
	(default operation is replace, per 1003.2)
-e	(edit user's crontab)
-l	(list user's crontab)
-r	(delete user's crontab)
-i	(prompt before deleting user's crontab)
```
若没有指定-u则默认当前用户

## crontab配置文件
全局配置目录
``` bash
/etc/crontab
```
用户配置目录
``` bash
/var/spool/cron
```
crontab日志文件
``` bash
/var/log/cron
```

## Crontab常见错误
1. 环境变量不存在
2. 命令行双引号使用%时没加\\
3. 第3个\*和第5个\*之间执行的是"或"操作
4. 分钟设置误用

例如：四月的第一个星期日早晨1时59分运行a.sh
``` bash
59 1 1-7 4 0 /root/a.sh		#错误的写法，实际上会在4月的1-7号或者星期日的1时59分执行a.sh
59 1 1-7 4 * test `date +\%w` -eq 0 && /root/a.sh	#正确，虽会在4月1-7号都执行，但会先执行test判断是否星期日，只有是星期日才会继续执行a.sh
```

例如：每6小时执行一次a.sh
``` bash
* 0,6,12,18 * * * /root/a.sh	#错误，0,6,12,18点的时候会每一分钟都执行
0 */6 * * *	/root/a.sh	#正确			
```
	
## crontab综合案例
crontab中最小执行任务的时间单元是分钟，但如果想每30秒执行一次要怎么做？    
可以通过sleep命令配合crontabs完成该功能
``` bash
COMMAND; sleep 30s; COMMAND
```
但若要每秒都执行，则可以先写好shell脚本，然后让每一分钟去执行该脚本
	
## 参考资料
[Linux中的计划任务—Crontab](http://www.imooc.com/learn/216)
[每天一个linux命令（50）：crontab命令](http://www.cnblogs.com/peida/archive/2013/01/08/2850483.html)  
[CentOS安装crontab及使用方法](http://blog.163.com/victory_wxl/blog/static/14130530220115296180333/)
