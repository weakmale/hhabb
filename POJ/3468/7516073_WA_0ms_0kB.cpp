#include "cstdio"
using namespace std;
typedef long long LL;
LL sum[100010<<2];
LL lazy[100010<<2];
void Add(LL rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void Down(LL rt,LL l,LL r){
    LL mid=(l+r)>>1;
    if(lazy[rt]){
        lazy[rt<<1]=lazy[rt];
        lazy[rt<<1|1]=lazy[rt];
        sum[rt<<1]+=lazy[rt]*(mid-l+1);
        sum[rt<<1|1]+=lazy[rt]*(r-mid);
        lazy[rt]=0;
    }
}
void build(LL l,LL r,LL rt){
    if(l==r){
        scanf("%lld",&sum[rt]);
        return ;
    }
    LL mid = ( l +r ) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    Add(rt);
}
void change(LL l,LL r,LL rt,LL L,LL R,LL C){
    if(l>=L&&r<=R){
        sum[rt]+=(r-l+1)*C;
        lazy[rt]+=C;
        return ;
    }
    LL mid = (l+r)>>1;
    Down(rt, l, r);
    if(mid>=L) change(l, mid, rt<<1, L, R, C);
    if(mid<R) change(mid+1, r, rt<<1|1, L, R, C);
    Add(rt);
}
LL queue(LL l,LL r,LL rt,LL L,LL R){
    if(l>=L&&R>=r)
        return sum[rt];
    LL mid = (l+r)>>1;
    LL ans=0;
    Down(rt, l, r);
    if(L<=mid) ans+=queue(l, mid, rt<<1, L, R);
    if(R>mid) ans+=queue(mid+1, r, rt<<1|1,L , R);
    return ans;
}
int main(){
    int n,q; scanf("%d %d",&n,&q);
    build(1, n, 1);
    while (q--) {
        char s[2]; LL a,b,c;
        scanf("%s",s);
        if(s[0]=='Q'){
            scanf("%lld %lld",&a,&b);
            printf("%lld\n",queue(1, n, 1, a, b));
        }
        else{
            scanf("%lld %lld %lld",&a,&b,&c);
            change(1, n, 1, a, b, c);
        }
    }
    
}