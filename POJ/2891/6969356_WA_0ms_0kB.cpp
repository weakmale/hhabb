#include "cstdio"
typedef long long  LL;
LL x,y;
LL EXGCD(LL a,LL b){
    if(b==0){
        x=1; y=0; return a;
    }
    LL r=EXGCD(b,a%b);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        LL a1,a2,b1,b2;
        scanf("%lld %lld",&a1,&b1);
        n--; bool K=false;
        while(n--){
            scanf("%lld %lld",&a2,&b2);
            if(K)
                continue;
            LL c=b2-b1;
            LL d=EXGCD(a1,a2);
            if(c%d)
            {
                K=true; continue;
            }
            x=x/d*c;
            a2/=d;
            x=(x%a2+a2)%a2;
            b1=a1*x+b1;
            a1=a1*a2/d;
        }
        if(K)
            printf("-1\n");
        else
            printf("%lld\n",b1);
    }
    return 0;
}