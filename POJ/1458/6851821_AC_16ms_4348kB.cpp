#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXX=1010;
const int inf=0x3f3f3f3f;
char s1[MAXX];
char s2[MAXX];
int dp[MAXX][MAXX];
int main(){
    while(scanf("%s %s",s1,s2)!=EOF){
        int len1=strlen(s1);
        int len2=strlen(s2);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len1;++i){
            for(int j=1;j<=len2;++j){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
