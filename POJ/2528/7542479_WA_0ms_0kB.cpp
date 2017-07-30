#include "cstdio"
#include "map"
#include "algorithm"
using namespace std;
map<int ,int> Map;
int sum[20010];
int lisan[20010];
int ll[20010];
int rr[20010];
int add[20010];
//void Down(int rt,int l,int r){
//    if(add[rt]){
//        add[rt<<1]=add[rt];
//        add[rt<<1|1]=add[rt];
//        sum[rt<<1]=add[rt];
//        sum[rt<<1|1]=add[rt];
//        add[rt]=0;
//    }
//}
void build(int l,int r,int rt){
    sum[rt]=0;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}
int judge(int l,int r,int rt,int L,int R){
    if(sum[rt]) return 0;
    if(L<=l&&r<=R){
        sum[rt]=1;
        add[rt]=1;
        return 1;
    }
//    Down(rt,l,r);
    int mid = (l+r)>>1;
    int K=0;
    if(mid>=L) K+=judge(l, mid, rt<<1, L, R);
    if(R>mid) K+=judge(mid+1, r, rt<<1|1, L, R);
    if(sum[rt<<1]&&sum[rt<<1|1])
        sum[rt]=1;
    return K;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        int k=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&ll[i],&rr[i]);
            lisan[++k]=ll[i];
            lisan[++k]=rr[i];
        }
        sort(lisan+1,lisan+1+k);
        k = (int)(unique(lisan+1, lisan+1+k)-lisan-1);
        for(int i=1;i<=k;i++){
            Map[lisan[i]]=i;
//            printf("%d\n",lisan[i]);
        }
        build(1, k, 1);
        int ans=0;
        for(int i=n;i>=1;i--){
            if(judge(1, k, 1, Map[ll[i]],Map[rr[i]])){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
