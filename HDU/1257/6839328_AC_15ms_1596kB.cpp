#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int const MAXX=30000+10;
const int INF=0x3f3f3f3f;
int a[MAXX];
int dp[MAXX];
int c[MAXX];
int n;
int ans;
void LIS(){
    for(int i=1;i<=n;i++){
        int k=upper_bound(c+1,c+1+n,a[i])-c;
        dp[i]=k;
        c[k]=min(c[k],a[i]);
        ans=max(dp[i],ans);
    }
}
int main(){
	while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]); c[i]=INF;
        }
        ans=0;
        LIS();
        printf("%d\n",ans);
	}
	return 0;
}
