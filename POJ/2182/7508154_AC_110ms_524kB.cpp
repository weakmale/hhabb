#include "cstdio"
using namespace std;
int num[8010<<2];
int a[8010];
int b[8010];
void bulid(int l,int r,int rt){
    num[rt]=r-l+1;
    if(l==r) return;
    int mid=(l+r)>>1;
    bulid(l, mid, rt<<1);
    bulid(mid+1, r, rt<<1|1);
}
int queue(int l,int r,int rt,int ln){
    num[rt]--;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(ln<=num[rt<<1]) return queue(l, mid, rt<<1, ln);
    else return queue(mid+1, r, rt<<1|1, ln-num[rt<<1]);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        a[1]=0;
        for(int i=2;i<=n;i++)
            scanf("%d",a+i);
        bulid(1, n, 1);
        for(int i=n;i>=1;i--)
            b[i]=queue(1, n, 1, a[i]+1);
        for(int i=1;i<=n;i++)
            printf("%d\n",b[i]);
    }
    return 0;
}