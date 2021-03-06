 #include<iostream>
 #include<cstdlib>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 using namespace std;
 struct prog {
     __int64 a[2][2] ;
     void init(){
         a[0][0]=a[1][1]=3;
         a[1][0]=a[0][1]=1;
     }
 };

 prog matrixmul ( prog a ,prog b )
 {
     int i , j , k ;
     prog c ;
     for ( i = 0 ; i < 2; i ++ )
     {
         for ( j = 0 ; j < 2 ; j ++ )
         {
             c.a[i][j]=0;
             for ( k =0 ; k < 2; k ++ )
                 c.a[i][j]+=__int64(a.a[i][k]*b.a[k][j]) ;
             c.a[i][j] %= 1000000007  ;
         }
     }
     return c ;
 }
 prog mul (prog s , __int64 k )
 {
     prog ans ;
     ans.init();
     while ( k >= 1 )
     {
         if ( k & 1 )
             ans = matrixmul ( ans , s ) ;
         k = k >> 1 ;
         s = matrixmul ( s , s ) ;
     }
     return ans ;
 }
 int main()
 {
     __int64 n ;
     while ( cin >> n  )
     {
		 if(n==0)
		 {
			 cout<<1<<endl;
			 continue;
		 }
         prog s ;
         s.init ( ) ;
         s = mul ( s , n - 1 ) ;
		 cout<<s.a[0][0]%1000000007<<endl;
     }

     return 0;
 }