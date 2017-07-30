#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
double pi[110];
int w[110];
double dp[100010];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; double p; scanf("%lf %d",&p,&n);
        p = 1-p;
        int sum = 0;
        memset(dp, 0, sizeof(dp)); dp[0]=1;
        for(int i=1;i<=n;i++)
            scanf("%d %lf",&w[i],pi+i),pi[i] = 1-pi[i],sum+=w[i];
        for(int i=1;i<=n;i++)
            for(int j=sum;j>=w[i];j--)
                dp[j] = max(dp[j],dp[j-w[i]]*pi[i]);
        for(int i=sum;i>=0;i--)
            if(dp[i]>p){
                printf("%d\n",i); break;
            }
    }
    return 0;
}