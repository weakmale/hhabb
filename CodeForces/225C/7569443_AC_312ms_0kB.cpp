#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
const int inf = 1e8;
struct node{
    int fir,sec;
}num[1010];
char s[1010];
int dp[3][1010];
int main(){
    memset(num,0,sizeof(num));
    int n,m,x,y; scanf("%d %d %d %d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            if(s[j]=='#') num[j].fir++;
            else num[j].sec++;
        }
    }
    for(int i=1;i<=m;i++){
        dp[0][i]=dp[1][i]=inf;
    }
    dp[0][0]=dp[1][0]=0;
    for(int i=1;i<=m;i++){
        for(int k=x;k<=y&&i-k>=0;k++){
            int sum1=0,sum2=0;
            for(int j=i-k+1;j<=i&&j>0;j++)
                sum1+=num[j].fir,sum2+=num[j].sec;
            dp[0][i]=min(dp[0][i],dp[1][i-k]+sum1);
            dp[1][i]=min(dp[1][i],dp[0][i-k]+sum2);
        }
    }
    printf("%d\n",min(dp[0][m],dp[1][m]));
    return 0;
}