#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int M[25][1010];
int dp[25][1010];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d %d",&n,&m);
        memset(M,0,sizeof(0));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                scanf("%d",&M[i][j]),dp[i][j]=-1e7;
        }
        for(int i=0;i<=n;i++)
            dp[i][0]=-1e7;
        for(int i=0;i<=m;i++)
            dp[0][i]=-1e7;
        dp[1][0]=0; dp[0][1]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                for(int k = 2; k<=m; k++)
                {
                    if(j%k==0)
                        dp[i][j] = max(dp[i][j],dp[i][j/k]);
                }
                dp[i][j]+=M[i][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}