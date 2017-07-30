#include<cstdio>
typedef long long LL;
const LL mod=1e9+9;
LL Qpow(LL n,LL m){
    LL ans=1; LL base=n;
    while(m){
        if(m&1)
            ans=(ans*base)%mod;
        base=(base*base)%mod;
        m>>=1;
    }
    return ans;
}
int main(){
    LL n,m,k; scanf("%lld %lld %lld",&n,&m,&k);
    LL wa=n-m;
    if(n<k*(wa+1)){
        printf("%lld",m);
    }
    else{
        LL kk=n/k-wa;
        printf("%lld\n",(k*(Qpow(2,kk+1)-2-kk)%mod+m+mod)%mod);
    }
    return 0;
}
