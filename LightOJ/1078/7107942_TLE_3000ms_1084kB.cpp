#include "cstdio"
typedef long long LL;
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        LL mod=b%a; LL k=1; b*=10;
        while(mod){
            mod=(b+mod)%a;
            b*=10;
            k++;
        }
        printf("Case %d: %lld\n",kcase++,k);
    }
    return 0;
}