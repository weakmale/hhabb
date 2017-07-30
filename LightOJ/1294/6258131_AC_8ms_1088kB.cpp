#include<cstdio>
int main(){
    int t,k=1; scanf("%d",&t);
    while(t--){
        long long  n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n",k++,m*n/2);
    }
    return 0;
}
