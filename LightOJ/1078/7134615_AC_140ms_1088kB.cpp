#include "cstdio"
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        int mod=m%n; int t=1;
        while(mod)
            mod=(mod*10+m)%n,t++;
        printf("Case %d: %d\n",kcase++,t);
    }
    return 0;
}