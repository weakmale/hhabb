#include "cstdio"
#include "algorithm"
using namespace std;
int dp[110];
int main(){
    int T; scanf("%d",&T);
    while (T--) {
        double m; int n; scanf("%lf %d",&m,&n);
        int mm = m*100;
        for(int i=0;i<=mm;i++) dp[i]=0;
        for(int i=1;i<=n;i++){
            int a,b; scanf("%d %lf",&a,&m);
            b = 100*m;
            for(int j=mm;j>=b;j--)
                dp[j] = max(dp[j-b]+a,dp[j]);
        }
        printf("%d\n",dp[mm]);
    }
    return 0;
}
