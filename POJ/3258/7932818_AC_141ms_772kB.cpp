#include "cstdio"
#include "algorithm"
using namespace std;
typedef long long LL;
LL a[50010];
LL l;
int n,m;
bool judge(LL ln){
    int ans=0; LL b=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]-b<ln)
            ans++;
        else
            b=a[i];
    }
    if(ans<=m)
        return true;
    return false;
}
int main(){
    scanf("%lld %d %d",&l,&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1, a+1+n);
    a[n+1]=l;
    LL ll=0,rr=l;
    LL ans=0;
    while(ll<=rr){
        LL mid =(ll+rr)>>1;
//        printf("%lld %lld\n",rr,ll);
        if(judge(mid)) ans=mid,ll=mid+1;
        else rr= mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}