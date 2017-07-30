#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXX=100000+10;
const int INF=0x3f3f3f3f;
int dp[MAXX];
int c[MAXX];
int n;
int num[MAXX];
int main(){
	int T; scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]),c[i]=INF;
        for(int i=1;i<=n;i++){
            dp[i]=lower_bound(c+1,c+1+n,num[i])-c;
            c[dp[i]]=min(c[dp[i]],num[i]);
        }
        for(int i=1;i<n;i++)
            printf("%d ",dp[i]);
        printf("%d\n",dp[n]);
	}
	return 0;
}
