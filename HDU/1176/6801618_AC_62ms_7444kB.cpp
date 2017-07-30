#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXX=100000+10;
int dp[MAXX][15];
int n;
int main(){
	while(scanf("%d",&n),n){
		memset(dp,0,sizeof(dp));
		int x,t; int T=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&t);
			dp[t][x]++;
			if(T<t)
				T=t;
		}
		for ( int i = T-1; i >= 0 ; --i ){
			for( int j=0; j<=10 ; j++ ){
				if(j==0)
					dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
				else if(j==10)
					dp[i][j]=max(dp[i+1][j-1],dp[i+1][j])+dp[i][j];
				else{
					int maxx=max(dp[i+1][j-1],dp[i+1][j]);
					dp[i][j]=max(maxx,dp[i+1][j+1])+dp[i][j];
				}
			}
		}
		printf("%d\n",dp[0][5]);
	}
	return 0;
}