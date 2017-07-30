#include "cstdio"
#include "cstring"
using namespace std;
double Map[500][500];
double dp[10][500];
int main(){
    int n;
    while(scanf("%d",&n),n!=-1){
        int m=1<<n;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                scanf("%lf",&Map[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++) dp[0][i]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++)
                    if (( ( (j-1)>>(i-1) )^1)==( (k-1)>>(i-1) ))
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*Map[j][k];
            }
        }
        double ans=0; int cnt=0;
        for(int i=1;i<=m;i++){
            if(dp[n][i]>ans){
                ans=dp[n][i];cnt=i;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
    
}