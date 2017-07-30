#include "cstdio"
#include "algorithm"
using namespace std;
int morc[200000<<2];
void build(int l,int r,int rt){
    if(l==r) { scanf("%d",&morc[rt]); return ;}
    int mid=(l+r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    morc[rt]=max(morc[rt<<1],morc[rt<<1|1]);
}
void change(int l,int r,int rt,int L,int c){
    if(l==r){ morc[rt]=c;return;}
    int mid=(l+r)>>1;
    if(L<=mid) change(l, mid, rt<<1, L, c);
    else change(mid+1, r, rt<<1|1, L, c);
    morc[rt]=max(morc[rt<<1],morc[rt<<1|1]);
    //printf("%d  %d\n",morc[rt],rt);
}
int queue(int l,int r,int rt,int L,int R){
    if(l>=L&&r<=R)
        return morc[rt];
    int mid = (l+r)>>1;
    int ans = 0;
    if(mid>=L) ans = max(ans,queue(l, mid, rt<<1, L, R));
    if(mid<R) ans = max(queue(mid+1, r, rt<<1|1, L, R),ans);
    return ans;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        build(1,n,1);
        while(m--){
            char s[2]; int l;int r;
            scanf("%s %d %d",s,&l,&r);
            if(s[0]=='Q')
                printf("%d\n",queue(1, n, 1, l, r));
            else
                change(1, n, 1, l, r);
        }
    }
    return 0;
}