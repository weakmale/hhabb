#include "cstdio"
#include "algorithm"
using namespace std;
const int MAXX=1e5+10;
const int INF=0x3f3f3f3f;
int arr[MAXX];
int n;
int c[MAXX];
int main(){
    int T; scanf("%d",&T); int t=1;
    while(T--){
        scanf("%d",&n);int a;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);c[i]=INF;
            arr[i]=a-i;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int  k=upper_bound(c+1,c+1+n,arr[i])-c;
            c[k]=min(c[k],arr[i]);
            ans=max(k,ans);
        }
        printf("Case #%d:\n",t++);
        printf("%d\n",n-ans);
    }
    return 0;
}