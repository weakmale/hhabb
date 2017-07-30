#include "cstdio"
const int MAXX=1000+10;
int a[MAXX];
int n;
int sum[MAXX];
int maxx;
int main(){
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int maxx=0;
        for(int i=1;i<=n;i++){
            sum[i]=a[i];
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j]&&sum[i]+a[j]>sum[i]){
                    sum[i]=sum[i]+a[i];
                }
            }
            if(sum[i]>maxx)
                maxx=sum[i];
        }
        printf("%d\n",maxx);
    }
    return 0;
}