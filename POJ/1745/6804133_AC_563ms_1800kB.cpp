#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXX=10000+10;
int n,k;
int a[MAXX];
bool dp[MAXX][110];
int main(){
	while(~scanf("%d %d",&n,&k)){
		memset(dp,false ,sizeof(dp));
		for( int i = 1 ;i <= n ; ++i ){
			scanf("%d",&a[i]);
		}
		dp[1][( ( a[1] % k ) + k ) % k ]=true;
		for(int i=2;i<=n;i++){
			for(int j=0;j<k;j++){
				if(dp[i-1][j]){
					dp[i][ ( ( j - a[i] ) % k + k ) % k ]=true;//同余定理 
					dp[i][ ( ( j + a[i] ) % k + k ) % k ]=true;
				}
			}
		}
		if(!dp[n][0])
			printf("Not divisible\n");
		else
			printf("Divisible\n");
	}
	return 0;
}