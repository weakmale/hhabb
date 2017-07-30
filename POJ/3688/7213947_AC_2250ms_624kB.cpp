#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int n,m;
bool dp[100010][2];
int a[100010];
int main(){
    while(scanf("%d %d",&n,&m),n||m){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
//        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            for(int j=m;j>a[i];j--){
                if(dp[j-a[i]][0]) dp[j][1]=true;
                if(dp[j-a[i]][1]) dp[j][0]=true;
            }
            dp[a[i]][1]=true;
        }
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(dp[i][1]&&!dp[i][0])
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}