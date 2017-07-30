#include "cstdio"
using namespace std;
int F[2010];
int R[2010];
int Found(int x){
    if(F[x]==x) return x;
    int t=F[x];
    F[x]=Found(t);
    R[x]=(R[x]+R[t])%2;
    return F[x];
}
int main(){
    int T,kcase=1; scanf("%d",&T);
    while(T--){
        bool K=true;
        int n,m; scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) F[i]=i,R[i]=0;
        while(m--){
            int a,b; scanf("%d %d",&a,&b);
            if(!K) continue;
            int na=Found(a),nb=Found(b);
            if(na!=nb)
                F[nb]=na,R[nb]=((R[a]-R[b]+1)%2+2)%2;
            else
                if(((R[b]-R[a])%2+2)%2!=1)
                    printf("Scenario #%d:\n",kcase++),
                    puts("Suspicious bugs found!"),
                    K=false;
        }
        if(K)
            printf("Scenario #%d:\n",kcase++),
            puts("No suspicious bugs found!");
        puts("");
    }
    return 0;
}