#include "cstdio"
typedef long long LL;
LL x,y;
LL EXGCD(LL a,LL b){
    if(b==0){
        x=1;y=0;
        return a;
    }
    LL r=EXGCD(b, a%b);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main(){
    LL x1,y1,m,n,L;
    while(scanf("%lld %lld %lld %lld %lld",&x1,&y1,&m,&n,&L)!=EOF){
        LL a=n-m; LL c=x1-y1; LL b=L;
        LL G=EXGCD(a,b);
        if(c%G){
            printf("Impossible\n");
        }
        else{
            a/=G; b/=G; c/=G;
            x*=c;
            if(b<0)b=-b;
            LL t=(x%b+b)%b;
            printf("%lld\n",t);
        }
    }
    return 0;
}