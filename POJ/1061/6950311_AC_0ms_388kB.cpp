#include "cstdio"
typedef long long  LL;
LL p,q;
LL EXGCD(LL a,LL b){
    if(b==0){
        p=1;
        q=0;
        return a;
    }
    LL r=EXGCD(b,a%b);
    LL t=p;
    p=q;
    q=t-a/b*q;
    return r;
}
int main(){
    LL  x,y,m,n,l;
    while(~scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)){
        LL a=n-m;LL b=l;LL c=x-y;
        LL G=EXGCD(a,b);
        if(c%G)
            printf("Impossible\n");
        else{
            a/=G; b/=G; c/=G;
            p*=c;
            if (b<0) b=-b;
            LL t=p%b;
            if(t<=0)
                t+=b;
            printf("%lld\n",t);
        }
    }
    return 0;
}