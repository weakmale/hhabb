#include "cstdio"
const int MAXX=1000+10;
int a[MAXX];
int dp[MAXX];
int n;
int sum[MAXX];
int maxx;
int main(){
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[1]=1; int maxx=0;
        sum[1]=a[1];
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j]){
                    dp[i]=dp[i-1]+1;
                    sum[i]=sum[i-1]+a[i];
                }
                else{
                    dp[i]=dp[i-1];
                    sum[i]=sum[i-1];
                }
            }
            if(sum[i]>maxx)
                maxx=sum[i];
        }
        printf("%d\n",maxx);
    }
    return 0;
}