#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXX=5010;
char s1[MAXX];
char s2[MAXX];
int dp[2][MAXX];
char s[MAXX];
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
        scanf("%s",s1);
        for(int i=0;i<n;++i)
            s2[i]=s1[n-1-i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                }
                else{
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
                }
            }
        }
        printf("%d\n",n-dp[n%2][n]);
	}
	return 0;
}
