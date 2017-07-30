#include <cstdio>
typedef long long LL;
LL x,y;
LL a[10000];
LL m[10000];
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
    int T; int t=1;scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for (int i=1; i<=n; i++)
            scanf("%lld",&m[i]);
        LL a1,a2,b1,b2;
        a1=a[1]; b1=m[1]; bool K=false;
        for(int i=2;i<=n;i++){
            a2=a[i]; b2=m[i];
            LL d=EXGCD(a1,a2);
            LL c=b2-b1;
            if(c%d){
                K=true; break;
            }
            x=x*(c/d);
            a2/=d;
            x=(x%a2+a2)%a2;
            b1=a1*x+b1;
            a1*=a2;
        }
        if(K)
            printf("Case %d: -1\n",t++);
        else{
            b1=(b1%a1+a1)%a1;
            if(b1==0)  b1=a1;
            printf("Case %d: %lld\n",t++,b1);
        }
    }
    return 0;
}
