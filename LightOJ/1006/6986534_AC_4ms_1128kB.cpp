#include "cstdio"
const int mod=10000007;
int a[10100];
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        for(int i=0;i<=5;i++){
            scanf("%d",&a[i]);
            a[i]%=mod;
        }
        scanf("%d",&n);
        for(int i=6;i<=n;i++){
            a[i]=(a[i-1]+a[i-2]+a[i-3]+a[i-4]+a[i-5]+a[i-6])%mod;
        }
        printf("Case %d: %d\n", ++caseno, a[n] % 10000007);
    }
    return 0;
}