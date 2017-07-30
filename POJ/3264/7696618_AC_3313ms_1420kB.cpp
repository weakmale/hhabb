#include "cstdio"
#include "algorithm"
using namespace std;
int minn[50010<<2];
int maxx[50010<<2];
int Minn;
int Maxx;
void build(int l,int r,int rt){
    if(l==r){ scanf("%d",&minn[rt]),maxx[rt]=minn[rt];return ;}
    int mid = (l+r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    minn[rt] = min(minn[rt<<1],minn[rt<<1|1]);
    maxx[rt] = max(maxx[rt<<1],maxx[rt<<1|1]);
}
void queue(int l,int r,int rt, int L,int R){
    if(l>=L&&r<=R){
        Minn = min(Minn,minn[rt]);
        Maxx = max(Maxx,maxx[rt]);
        return ;
    }
    int mid = (l+r)>>1;
    if(L<=mid) queue(l, mid, rt<<1, L, R);
    if(R>mid)  queue(mid+1, r, rt<<1|1, L, R);
}
int main(){
    int n,q; scanf("%d %d",&n,&q);
    build(1, n, 1);
    while(q--){
        int l,r; scanf("%d %d",&l,&r);
        Minn = 1e8; Maxx = -1;
        queue(1, n, 1, l, r);
        printf("%d\n",Maxx-Minn);
    }
    return 0;
}