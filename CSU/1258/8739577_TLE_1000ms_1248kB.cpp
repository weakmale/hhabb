#include "cstdio"
using namespace std;
int tree[10010*4];
int lowbet(int x){ return x&-x; }
void build(int l,int r,int rt){
    if(l==r){ scanf("%d",&tree[rt]);return;}
    int mid = (l+r)>>1;
    build(l, mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    tree[rt]=tree[rt<<1]^tree[rt<<1|1];
}
void change(int L,int R,int l,int r,int rt){
    if(l==r){
        if(tree[rt]>=0) tree[rt] = tree[rt]-lowbet(tree[rt]);
        else{
            int x=-tree[rt]; x=x-lowbet(x);
            tree[rt]=-x;
        }
        return ;
    }
    int mid = (l+r)>>1;
    if(L<=mid) change(L, R, l, mid, rt<<1);
    if(R>mid) change(L, R, mid+1, r, rt<<1|1);
    tree[rt]=tree[rt<<1]^tree[rt<<1|1];
}
int queue(int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R)
        return tree[rt];
    int ans=0;
    int mid = (l+r)>>1;
    if(L<=mid) ans^=queue(L, R, l, mid, rt<<1);
    if(R>mid) ans^=queue(L, R, mid+1, r, rt<<1|1);
    return ans;
}
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        build(1, n, 1);
        while(m--){
            int a,b,c; scanf("%d %d %d",&a,&b,&c);
            if(a==1)
                change(b, c, 1, n, 1);
            else
                printf("%d\n",queue(b, c, 1, n, 1));
        }
    }
    return 0;
}