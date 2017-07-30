#include "cstdio"
using namespace std;
int sum[100010<<2];
int lazy[100010<<2];
void Add(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void Down(int rt,int l,int r){
    int mid=(l+r)>>1;
    if(lazy[rt]){
        lazy[rt<<1]=lazy[rt];
        lazy[rt<<1|1]=lazy[rt];
        sum[rt<<1]+=lazy[rt]*(mid-l+1);
        sum[rt<<1|1]+=lazy[rt]*(r-mid);
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&sum[rt]);
        return ;
    }
    int mid = ( l +r ) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    Add(rt);
}
void change(int l,int r,int rt,int L,int R,int C){
    if(l>=L&&r<=R){
        sum[rt]+=(r-l+1)*C;
        lazy[rt]+=C;
        return ;
    }
    int mid = (l+r)>>1;
    Down(rt, l, r);
    if(mid>=L) change(l, mid, rt<<1, L, R, C);
    if(mid<R) change(mid+1, r, rt<<1|1, L, R, C);
    Add(rt);
}
int queue(int l,int r,int rt,int L,int R){
    if(l>=L&&R>=r)
        return sum[rt];
    int mid = (l+r)>>1;
    int ans=0;
    Down(rt, l, r);
    if(L<=mid) ans+=queue(l, mid, rt<<1, L, R);
    if(R>mid) ans+=queue(mid+1, r, rt<<1|1,L , R);
    return ans;
}
int main(){
    int n,q; scanf("%d %d",&n,&q);
    build(1, n, 1);
    while (q--) {
        char s[2]; int a,b,c;
        scanf("%s",s);
        if(s[0]=='Q'){
            scanf("%d %d",&a,&b);
            printf("%d\n",queue(1, n, 1, a, b));
        }
        else{
            scanf("%d %d %d",&a,&b,&c);
            change(1, n, 1, a, b, c);
        }
    }
    
}