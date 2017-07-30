#include "cstdio"
#include "algorithm"
using namespace std;
double dp[10010];
double P[110];
int vi[110];
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        double pi; int sum=0;
        int n; scanf("%lf %d",&pi,&n);
        for(int i=1;i<=n;i++){
            int x; double p;
            scanf("%d %lf",&x,&p);
            vi[i]=x; P[i]=1.0-p;
            sum+=x;
        }
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=sum;j>=vi[i];j--){
                if (dp[j-vi[i]]) {
                    dp[j]=max(dp[j],dp[j-vi[i]]*P[i]);
                }
            }
        }
        for(int i=sum;i>=0;i--){
            if(1-dp[i]<=pi){
                printf("Case %d: %d\n",kcase++,i);
                break;
            }
        }
    }
    return 0;
}