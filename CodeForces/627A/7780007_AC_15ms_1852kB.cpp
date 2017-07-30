#include "cstdio"
typedef long long LL;
int main(){
    LL s,x; scanf("%lld %lld",&s,&x);
    LL t=(s-x)>>1;
    LL sum=1;
    if((s-x)&1||s<x){
        puts("0"); return 0;
    }
    LL X=x;
    while(X){
        if(X&1){
            sum<<=1;
            if(t&1){ puts("0"); return 0;}
        }
        X>>=1; t>>=1;
    }
    if(x==s) sum-=2;
    printf("%lld\n",sum);
    return 0;
}