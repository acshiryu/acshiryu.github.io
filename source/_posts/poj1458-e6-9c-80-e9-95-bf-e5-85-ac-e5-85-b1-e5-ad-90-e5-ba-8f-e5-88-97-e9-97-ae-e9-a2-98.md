title: poj1458 最长公共子序列问题
toc: true
tags:
  - DP
  - 最长公共子序列
categories:
  - 算法竞赛
id: 1362
date: 2012-05-09 17:49:54
---

杭电挂了，状态dp完全没看懂，只有秒一道水题充数，dp还要加油啊
[code lang="java"]
import java.util.*;
public class Main {
	public static void main(String[] args) {
		int[][] dp=null;
		String s1=new String();
		String s2=new String();
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			s1=in.next();
			s2=in.next();
			dp=new int[s1.length()+1][s2.length()+1];
			for(int i=0;i&lt;s1.length();i++){
				for(int j=0;j&lt;s2.length();j++){
					if(s1.charAt(i)==s2.charAt(j))
						dp[i+1][j+1]=dp[i][j]+1;
					else
						dp[i+1][j+1]=Math.max(dp[i+1][j],dp[i][j+1]);
				}
			}
			System.out.println(dp[s1.length()][s2.length()]);
		}
	}

}
[/code]