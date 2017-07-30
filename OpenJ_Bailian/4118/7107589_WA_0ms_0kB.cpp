#include "cstdio"
int a[110];
int b[110];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,k; scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        int sum=b[1]; int di=a[1]; int l=b[1];
        for(int i=2;i<=n;i++){
            if(a[i]-di>k){
                sum+=b[i]; di=a[i]; l=b[i];
            }
            else if(sum-l+b[i]>=sum){
                sum=sum-l+b[i]; di=a[i]; l=b[i];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}