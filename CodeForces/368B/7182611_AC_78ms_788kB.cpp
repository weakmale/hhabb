#include "cstdio"
using namespace std;
int a[100010];
bool vis[100010];
int dp[100010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        if(!vis[a[i]]){
            vis[a[i]]=true;
            dp[i]=dp[i+1]+1;
//            printf("%d~%d\n",dp[i],i);

        }
        else
        {
            dp[i]=dp[i+1];
//            printf("%d %d\n",dp[i],i);

        }
            }
    for(int i=1;i<=m;i++){
        int q;
        scanf("%d",&q);
        printf("%d\n",dp[q]);
    }
    return 0;
}