#include "cstdio"
int sum[50000<<2];
void Add(int rt){sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
void init(int l,int r,int rt){
    if(l==r){
        scanf("%d",&sum[rt]);
        return ;
    }
    int mid=(l+r)>>1;
    init(l,mid,rt<<1);
    init(mid+1,r,rt<<1|1);
    Add(rt);
}
void Update(int L,int C,int l,int r,int rt){
    if(l==r){
        sum[rt]+=C; return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) Update(L, C, l, mid, rt<<1);
    else Update(L, C, mid+1, r, rt<<1|1);
    Add(rt);
}
int Queue(int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R)
        return sum[rt];
    int ans=0;
    int mid=(l+r)>>1;
    if(L<=mid) ans+=Queue(L, R, l, mid, rt<<1);
    if(mid<R) ans+=Queue(L, R, mid+1, r, rt<<1|1);
    return ans;
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n;scanf("%d",&n);
        init(1,n,1); printf("Case %d:\n",kcase++);
        char s[10]; scanf("%s",s);
        while(s[0]!='E'){
            int a,b; scanf("%d %d",&a,&b);
            if(s[0]=='Q'){
                printf("%d\n",Queue(a, b, 1, n, 1));
            }
            else if(s[0]=='A')
                Update(a, b, 1, n, 1);
            else
                Update(a, -b, 1, n, 1);
            scanf("%s",s);
        }
    }
    return 0;
}