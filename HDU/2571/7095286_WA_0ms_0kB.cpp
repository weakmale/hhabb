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
        M[0][0]=-1e7; M[0][1]=-1e7; M[1][0]=-1e7;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(max(dp[i-1][j]+M[i][j],dp[i][j-1]+M[i][j]),dp[i][j]);
                for(int k=2;k*j<=m;k++){
                    dp[i][j*k]=max(dp[i][j]+M[i][j*k],dp[i][j*k]);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}