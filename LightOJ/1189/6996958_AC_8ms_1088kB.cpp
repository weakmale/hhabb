#include <cstdio>
typedef long long LL;
int main(){
    LL a[30]; a[0]=1;
    for(int i=1;i<=20;i++){
        a[i]=a[i-1]*i;
    }
    int t; int kcase=1; scanf("%d",&t);
    while(t--){
        LL n;
        int s[30]; int k=0;
        scanf("%lld",&n);
        for(int i=19;i>=0;i--){
            if(n>=a[i]){
                s[++k]=i;
                n-=a[i];
            }
        }
        printf("Case %d: ",kcase++);
        if(n==0){
            for(int i=k;i>1;i--)
                printf("%d!+",s[i]);
            printf("%d!\n",s[1]);
        }
        else
            printf("impossible\n");
    }
    return 0;
}
