#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[110][110];
char s1[110];
char s2[110];
int LCS(int n){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main(){
    int T; int kcase=1; scanf("%d",&T);
    while(T--){
        scanf("%s",s1);
        int len=strlen(s1);
        for(int i=len-1;i>=0;i--)
            s2[i]=s1[len-i-1];
        int x=LCS(len);
        printf("Case %d: %d\n",kcase++,len-x);
    }
    return 0;
}