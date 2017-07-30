#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
LL dp[100000010];
int main(){
	int T,t=1;scanf("%d",&T);
	dp[1]=5;  dp[2]=10;int j=0; int l=0;
	for(int i=3;i<100000010;i++){
		if( (i-j) % 5 == 0 && (i-j)!=l){
		l=i-j;
			j++;
			dp[i]=0; 
		}
		else
			dp[i]=max(dp[i-1]+5,dp[i-2]+5);
	}
	while(T--){
		LL Q,q; scanf("%lld",&Q); LL i=5; 
		if(dp[Q]==0)
		printf("Case %d: impossible\n",t++);
		else
		printf("Case %d: %lld\n",t++,dp[Q]);
	}
	return 0;
}
