#include "cstdio"
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL a[10010];
LL b[10010];
LL Qpow(LL n,LL m){
    LL ans=1;LL base=n;
    while(m){
        if(m&1)
            ans=ans*base%mod;
        base=base*base%mod;
        m>>=1;
    }
    return ans;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,t,k; scanf("%d %d %d",&n,&t,&k);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        LL ans=Qpow(k,t);
        for(int i=0;i<n;i++){
            b[i]=a[(i-t%n+n)%n]*ans%mod;
            if(i==n-1)
                printf("%lld\n",b[i]);
            else
                printf("%lld ",b[i]);
        }
    }
    return 0;
}