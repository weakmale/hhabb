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
int a[MAXX];
int b[MAXX];
int dp1[MAXX];
int dp2[MAXX];
int c1[MAXX];
int c2[MAXX];
int ans1; int ans2;
void LIS1(){
    for(int i=1;i<=n;i++){
        int k=lower_bound(c1+1,c1+1+n,a[i])-c1;
        dp2[i]=k;
        c1[i]=min(c1[k],a[i]);
        ans1=max(dp2[i],ans1);

    }
}
/*void LIS2(){
    for(int i=1;i<=n;i++){
        int k=lower_bound(c2+1,c2+1+n,b[i])-c2;
        dp2[i]=k;
        c2[i]=min(c2[k],b[i]);
        ans2=max(dp2[i],ans2);printf("%d~~~~~%d---%d\n",ans2,k,b[i]);
    }
}*/
int main(){
    int t=1;
	while(~scanf("%d",&n)){
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            a[i]=y-x; b[i]=x-y;  c1[i]=c2[i]=INF;
        }
        ans1=0; ans2=0;
        LIS1();
        int ans=max(ans1,ans2);
        printf("Case %d:\n",t++);
        printf("My king, at most %d road can be built.\n",ans);
	}
	return 0;
}
