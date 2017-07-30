#include "cstdio"
typedef long long LL;
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        LL mod=b%a; LL k=1;
        while(mod){
            mod=(mod*10+b)%a;
            k++;
        }
        printf("Case %d: %lld\n",kcase++,k);
    }
    return 0;
}