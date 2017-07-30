#include "cstdio"
long long GCD(long long a,long long b){
    while(a%b==0)
        return b;
    return GCD(b,a%b);
}
void EXGCD(long long a,long long b,long long &x,long long &y){
    while(a%b==0){
        x=1;
        y=0;
        return ;
    }
    EXGCD(a,a%b,x,y);
    long long t=x;
    x=y;
    y=t-(a/b)*y;
    
}
int main(){
    long long x,y,m,n,l;
    while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
    {
        long long a=n-m,b=l,c=n-m;
        long long G=GCD(a,b);
        if(c%G!=0){
            printf("Impossble\n");
            continue;
        }
        long long p,q;
        a/= G, b/= G, c/= G;
        EXGCD( a, b, p, q );
        p *= c;
        long long  t= p% b;
        while(t<0){
            t+=b;
        }
        printf("%lld\n",t);
    }
    return 0;
}