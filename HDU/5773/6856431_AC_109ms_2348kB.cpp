#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXX=100000+10;
const int INF=0x3f3f3f3f;
int num[MAXX];
int dp[MAXX];
int c[MAXX];
int n;
int main(){
	int T,t=1;
	scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]),c[i]=INF;
        }
        int x=0; int ans=0;
        for(int i=1;i<=n;i++){
            if(num[i]==0)
            {
                x++;
                continue;
            }
            num[i]-=x;
            int k=lower_bound(c+1,c+1+n,num[i])-c;
            c[k]=min(c[k],num[i]);
            ans=max(ans,k);
        }
        printf("Case #%d: %d\n",t++,ans+x);
	}
	return 0;
}
