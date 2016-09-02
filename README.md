hexo for my blog
====
1.工具下载
nodejs：https://nodejs.org/en/
git: http://git-scm.com/download/win
tortoisegit: https://tortoisegit.org/download/

2. 准备工作
2-1 git config
git config --global user.name "username"
git config --global user.email "username@github.com"
2-2 ssh key
ssh-keygen -t rsa -C "username@github.com"
得到文件 id_rsa和id_rsa.pub
github添加id_rsa.pub公钥
测试 ssh git@github.com


3.从无到有
3-1 github创建空仓库username.github.io，创建分支hexo
3-2 https://github.com/username/username.github.io项目主页 setting - Branches  切换hexo为默认分支
3-3 本地创建username.github.io  依次执行 
		npm install hexo
		hexo init
		npm install
3-4 本地文件夹 git init  并添加远程仓库
		git init
		git checkout -b hexo
		git remote add origin git@github.com:username/username.github.io.git
3-5 修改文件
		修改_config.yml中的deploy参数，分支应为master
			deploy:
			type: git
			repo: git@github.com:username/username.github.io.git
			branch: master
			
3-6 插件安装
		npm install hexo-deployer-git --save
		npm install hexo-generator-feed --save
		npm install hexo-generator-sitemap --save
3-7 提交文件至hexo
		git add .
		git commit -m "...."
		git push origin hexo
3-8 提交文件至master
		hexo clean
		hexo generate (hexo g)
		本地测试修改 hexo server (hexo s)
		提交到远端 hexo deploy (hexo d)
		
4 换电脑
git clone git@github.com:username/username.github.io.git
npm install hexo
npm install
npm install hexo-deployer-git
注意  此时不需要hexo init命令了
		
	