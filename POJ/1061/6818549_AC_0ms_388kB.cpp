#include "cstdio"
long long x,y,m,n,l;
long long p,q,c;
long long GCD(long long a,long long b){
    if(b==0)
        return a;
    return GCD(b,a%b);
}
void EXGCD(long long a,long long b){
    if(b==0){
        p=1;
        q=0;
        return ;
    }
    else{
        EXGCD(b, a%b);
        long long t=p;
        p=q;
        q=t - a / b * q;
    }
}
int main(){
    while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
    {
        long long d=x-y, b=l, a=n-m;
        long long G=GCD(a, b);
        if(d % G){
            printf("Impossible\n");continue;
        }
        else{
            a/=G; b/=G; d/=G;
            EXGCD(a, b);  p*=d;
            p%=b;
            while(p<0)
                p+=b;
            printf("%lld\n",p);
        }
    }
}