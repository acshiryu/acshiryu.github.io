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
			for(int i=0;i<s1.length();i++){
				for(int j=0;j<s2.length();j++){
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