#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
double dp[1100000];
int main(){
	
	for(int i=1;i<=1000010;i++)
		dp[i]=dp[i-1]+log(i);
	int T; scanf("%d",&T); int t=1;
	while(T--){
		int n,base; 
		scanf("%d %d",&n,&base);
		double ans; ans=dp[n]/log(base);
		int k=ans; k++;
		printf("Case %d: %d\n",t++,k);
	}
	return 0;
}
