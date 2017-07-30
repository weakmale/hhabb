#include "cstdio"
typedef long long  LL;
LL num[101];
LL sum[101];
int n;
void init(){
    num[0]=0;num[1]=1;
    sum[0]=0;sum[1]=1;
    for(int i=2;i<=100;i++){
        num[i]=num[i-1]*2+1;
        sum[i]=sum[i-1]*2+sum[i-1]+1;
    }
}
LL ans=0;
int main(){
    init();
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        int p=0; ans=0; LL cnt=0;
        while(n){
            p=1;
            while(n>num[p])
                ++p;
            --p;
            ans+=sum[p]+num[p]*ans;
            n-=num[p];
            if(n){
                cnt++;
                ans+=cnt;
                n--;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}