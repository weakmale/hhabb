#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXX=500000+10;
const int INF=0x3f3f3f3f;
int n;
struct node{
    int x;
    int y;
};
node a[MAXX];
int dp[MAXX];
int c[MAXX];
int ans;
bool cmp(node a,node b){
    return a.x<b.x;
}
void LIS(){
    for(int i=1;i<=n;i++){
        int k=lower_bound(c+1,c+1+n,a[i].y)-c;
        dp[i]=k;
        c[k]=min(c[k],a[i].y);
        ans=max(ans,dp[i]);
    }
}
int main(){
    int t=1;
	while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
            c[i]=INF;
        }
        ans=0;
        sort(a+1,a+1+n,cmp);
        LIS();
        printf("Case %d:\n",t++);
        printf("My king, at most %d road can be built.\n\n",ans);
	}
	return 0;
}
