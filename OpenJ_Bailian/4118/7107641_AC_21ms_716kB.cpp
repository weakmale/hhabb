#include "cstdio"
#include "algorithm"
using namespace std;
int a[110];
int b[110];
int dp[110];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,k; scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            int p=0;
            for(int j=1;j<i;j++){
                if(a[i]-a[j]>k)
                    p=max(p,dp[j]);
            }
            dp[i]=b[i]+p;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
            sum=max(dp[i],sum);
        printf("%d\n",sum);
    }
    return 0;
}