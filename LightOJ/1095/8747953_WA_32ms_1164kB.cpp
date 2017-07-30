#include "cstdio"
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
LL jie[10010];
LL Qpow(LL n,LL m){
    LL ans=1;
    while(m){
        if(m&1) ans = (ans*n)%mod;
        n=(n*n)%mod;
        m>>=1;
    }
    return ans;
}
LL C(int n,int m){
    return jie[n]*Qpow(jie[n-m]*jie[m]%mod,mod-2)%mod;
}
int main(){
    jie[0]=1;
    for(int i=1;i<=10000;i++) jie[i]=jie[i-1]*i%mod;
    int T; scanf("%d",&T);
    int kcase=1;
    while(T--){
        int n,m,k; scanf("%d %d %d",&n,&m,&k);
        LL ans = C(m,k);
        int t=1;
        LL sum=0;
        int p=m-k;
        for(int i=0;i<=p;i++){
            sum = sum+C(p,i)*jie[n-k-i]*t%mod;
            t*=-1;
        }
        ans = (ans*sum%mod+mod)%mod;
        printf("Case %d: %lld\n",kcase++,ans);
    }
    return 0;
}