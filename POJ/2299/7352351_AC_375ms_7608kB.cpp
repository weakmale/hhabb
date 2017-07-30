#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
typedef long long LL;
int c[500010];
int a[500010];
struct node {
    int v,id;
}P[500010];
bool cmp(node a,node b){
    return a.v<b.v;
}
int lowbet(int x){ return x&-x; }
void Add(int x,int n){
    while(x<=n){
        c[x]++;
        x+=lowbet(x);
    }
}
LL Sum(int x){
    LL sum=0;
    while (x) {
        sum+=c[x];
        x-=lowbet(x);
    }
    return sum;
}
int main(){
    int n;
    while(scanf("%d",&n),n){
        memset(c, 0, sizeof(c));
        for(int i=1;i<=n;i++) scanf("%d",&P[i].v),P[i].id=i;
        sort(P+1,P+1+n,cmp);
        for(int i=1;i<=n;i++)
            a[P[i].id]=i;
        LL ans=0;
        for(int i=1;i<=n;i++){
            Add(a[i],n);
            ans+=(i-Sum(a[i]));

        }
        printf("%lld\n",ans);
    }
    return 0;
}