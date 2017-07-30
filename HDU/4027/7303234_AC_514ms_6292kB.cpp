#include "cstdio"
#include "algorithm"
#include "cmath"
#include "cstring"
#include "iostream"
using namespace std;
typedef long long  LL;
const int MAXX= 100010;
LL sum[MAXX<<2];
int cnt[MAXX<<2];
LL a[MAXX];
void PushUp(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    cnt[rt]=cnt[rt<<1]&&cnt[rt<<1|1];
}
void Build(int l,int r,int rt){
    if(r==l){
        scanf("%lld",&sum[rt]); return ;
    }
    int mid=(l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}
void Update(int L,int R,int l,int r,int rt){
    if(l==r){
        sum[rt]=sqrt(sum[rt]);
        if(sum[rt]==1)
            cnt[rt]=1;
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid&&!cnt[rt<<1]) Update(L,R,l,mid,rt<<1);
    if(R>mid&&!cnt[rt<<1|1]) Update(L,R, mid+1, r, rt<<1|1);
    PushUp(rt);
}
LL Query(int L,int R,int l,int r,int rt){
    if(r<=R&&l>=L)
        return sum[rt];
    int mid=(l+r)>>1;
    LL ans=0;
    if(L<=mid) ans+=Query(L, R, l, mid, rt<<1);
    if(mid<R) ans+=Query(L, R, mid+1, r, rt<<1|1);
    return ans;
}
int main(){
    int n; int kcase=1;
    while(~scanf("%d",&n)){
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        Build(1,n,1);
        printf("Case #%d:\n",kcase++);
        int m; scanf("%d",&m);
        while(m--){
            int a,r,l;
            scanf("%d %d %d",&a,&l,&r);
            if(l>r) swap(l, r);
            if(a==0) Update(l,r,1,n,1);
            else
                printf("%lld\n",Query(l,r,1,n,1));
        }
        printf("\n");
    }
    return 0;
}
