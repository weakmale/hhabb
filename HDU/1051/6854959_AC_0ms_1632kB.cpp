#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n;
struct node{
    int L; int W;
}a[5010];
int c[5010];
bool cmp(node a,node b){
    if(a.L==b.L)
        return a.W<b.W;
    return a.L<b.L;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].L,&a[i].W);c[i]=1000000;
        }
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=n;i>=1;i--){
            int k=lower_bound(c+1,c+1+n,a[i].W)-c;
            c[k]=min(a[i].W,c[k]);
            ans=max(k,ans);
        }
        printf("%d\n",ans);
	}
	return 0;
}
