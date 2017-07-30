#include "cstdio"
#include "iostream"
#include "cmath"
#include "algorithm"
using namespace std;
typedef long long LL;
LL GCD(LL a,LL b){ return b?GCD(b,a%b):a; }
int main(){
    LL N,M; scanf("%lld %lld",&N,&M);
    LL n=sqrt(N);
    LL m=sqrt(M);
    LL ni=0,mi=0,si=0;
    for(LL i=1;i<=max(n,m)+1;i++){
        if(N%i==0&&i<=n)
            ni+=2;
        if(M%i==0&&i<=m)
            mi+=2;
        if(N%i==0&&M%i==0){
            si++;
            if(N==M)
                si++;
        }
    }
//    if(N==1) ni=1,si=1;
//    if(M==1) mi=1,si=1;
    LL t=GCD(ni*mi ,si);
    printf("%lld %lld\n",ni*mi/t,si/t);
}