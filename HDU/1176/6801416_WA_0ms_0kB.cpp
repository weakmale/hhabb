#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXX=100000+10;
int dp[MAXX][15];
int n;
int maxx(int a,int b,int c){
	int d[3];
	d[0]=a;
	d[1]=b;
	d[2]=c;
	sort(d,d+3);
	return d[2];
}
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
		for ( int i = T; i >= 0 ; --i ){
			int m=11; int j=1;
			if(i<5){
				m=6+i; j=6-i;
			}
			for( ; j<=m ; j++ ){
				dp[i][j]=maxx(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])+dp[i][j];
			}
		}
		printf("%d\n",dp[0][6]);
	}
	return 0;
}