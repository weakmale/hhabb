#include<cstdio>
#include<algorithm>
using namespace std;
int vi[3500];
int dp[15000];
int wi[3500];
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++)
            scanf("%d %d",&wi[i],&vi[i]);
        for(int i=1;i<=n;i++){
            for(int j=m;j>=wi[i];j--){
                dp[j]=max(dp[j],dp[j-wi[i]]+vi[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
