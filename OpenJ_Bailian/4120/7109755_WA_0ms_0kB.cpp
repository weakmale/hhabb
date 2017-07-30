#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
int dp[10010];
int a[210];
int dp1[10010];
int b[210];
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[0]=1; int t=0;
    for(int i=1;i<=n;i++){
        for(int j=x;j>=a[i];j--){
            dp[j]=dp[j]+dp[j-a[i]];
        }
    }
    for(int i=1;i<=n;i++){
        memset(dp1, 0, sizeof(dp1));
        for(int j=0;j<=x;j++){
            if(j<a[i]) dp1[j]=dp[j];
            else dp1[j]=dp[j]-dp1[j-a[i]];
        }
        if(dp1[x]==0) b[++t]=a[i];
    }
    printf("%d\n%d",t,b[1]);
    for(int i=2;i<=t;i++)
        printf(" %d",b[i]);
    printf(" \n");
    return 0;
}