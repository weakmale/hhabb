#include "cstdio"
using namespace std;
const int N = 100010;
int num[N << 2];
int add[N << 2];
void Add(int rt){
    num[rt]=num[rt<<1]+num[rt<<1|1];
}
void pushdown(int rt,int ln,int rn){
    if(add[rt]){
        add[rt<<1]=add[rt<<1|1]=add[rt];
        num[rt<<1]=add[rt]*ln;
        num[rt<<1|1]=add[rt]*rn;
        add[rt]=0;
    }
}
void build(int l,int r,int tr){
    add[tr]=0;
    num[tr]=r-l+1;
    if(l==r){ return ;}
    int mid = (l+r) >> 1;
    build(l, mid, tr<<1);
    build(mid+1,r,tr<<1|1);
}
void change(int l,int r,int tr,int li,int ri,int t){
    if(l>=li&&r<=ri){
        num[tr]=(r-l+1)*t;
        add[tr]=t;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(tr,mid-l+1,r-mid);
    if(li<=mid) change(l, mid, tr<<1, li, ri, t);
    if(ri>mid) change(mid+1, r, tr<<1|1, li, ri, t);
    Add(tr);
}
int main(){
    int T;int kcase=1; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        build(1, n, 1);
        int q; scanf("%d",&q);
        while(q--){
            int a,b,c; scanf("%d %d %d",&a,&b,&c);
            change(1, n, 1, a, b, c);
        }
        
        printf("Case %d: The total value of the hook is %d.\n",kcase++,num[1]);
    }
    return 0;
}