#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int INF=0x3f3f3f3f;
int n;
int s;
int a[100000+10];
int c1[100000+10];
int dp[100000+10];
int main(){
	while(~scanf("%d %d",&n,&s)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            c1[i]=INF;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=lower_bound(c1+1,c1+1+n,a[i])-c1;
            ans=max(ans,dp[i]);
            if(i-s>0)
                c1[dp[i-s]]=min(c1[dp[i-s]],a[dp[i-s]]);
        }
        printf("%d\n",ans);
	}
	return 0;
}
