hexo for my blog
====
## 1.工具下载
nodejs：https://nodejs.org/en/

git: http://git-scm.com/download/win

tortoisegit: https://tortoisegit.org/download/

## 2. 准备工作
### 2-1 git config
```
git config --global user.name "username"
git config --global user.email "username@github.com"
```

### 2-2 ssh key
```
ssh-keygen -t rsa -C "username@github.com"
```
得到文件 id_rsa和id_rsa.pub
github添加id_rsa.pub公钥
测试 ssh git@github.com


## 3.从无到有
### 3-1 github创建空仓库username.github.io，创建分支hexo 然后项目主页 setting - Branches  切换hexo为默认分支
### 3-2 本地创建username.github.io  依次执行 
```
npm install hexo
hexo init
npm install
```
### 3-3 本地文件夹 git init  并添加远程仓库
```
git init
git checkout -b hexo
git remote add origin git@github.com:username/username.github.io.git
```
### 3-4 修改文件
修改_config.yml中的deploy参数，分支应为master
```
deploy:
type: git
repo: git@github.com:username/username.github.io.git
branch: master
```
			
### 3-5 插件安装
```
npm install hexo-deployer-git --save
npm install hexo-generator-feed --save
npm install hexo-generator-sitemap --save
npm install js-yaml
npm install hexo-admin --save
```
### 3-6 提交文件至hexo
```
git add .
git commit -m "...."
git push origin hexo
```
### 3-7 提交文件至master
```
hexo clean
hexo generate (hexo g)
```
本地测试修改 hexo server (hexo s)

提交到远端 hexo deploy (hexo d)
		
## 4 换电脑
```
git clone git@github.com:username/username.github.io.git
npm install hexo
npm install
npm install hexo-deployer-git
```
注意  此时不需要hexo init命令了
		
## 5 其他
### 5-1 Hexo下mathjax的转义问题
https://segmentfault.com/a/1190000007261752

## 6 写作帮助
### 6-1 插入本文链接
```
{% post_link poj-1426-find-the-multiple %}
```
### 6-2 插入代码文件
代码文件需存放于source/assets/code文件夹
```
{% include_code main Prime Ring lang:cpp main.cpp %}
### 6-3 插如图片
```
![](/assets/image/img.jpg)
```
```