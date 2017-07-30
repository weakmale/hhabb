#include "cstdio"
using namespace std;
typedef long long LL;
LL x,y;
LL EXGCD(LL a,LL b){
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    LL r=EXGCD(b,a%b);
    LL t=x; x=y;
    y=t-a/b*y;
    return r;
}
int main(){
    int k;
    while(~scanf("%d",&k)){
        k--;
        LL x1,y1; scanf("%lld %lld",&x1,&y1);
        LL ans=y1;
        while(k--){
            LL x2,y2; scanf("%lld %lld",&x2,&y2);
            LL a=x1; LL b=x2; LL c=y1-y2;
            LL g=EXGCD(a, b);
        
            if(c%g||ans==-1){
                ans=-1; continue;
            }
            x=x*c/g;
            b=b/g;
            x=(x%b+b)%b;
            x-=b;
            LL K=y1-x*a;
            ans=K;
            x1=a*b;y1=ans;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
