#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
char s1[110];
char s2[110];
int dp[110][110];
int vis[110][110];
void OUTPUT(int x,int y){
    if(!x&&!y)
        return ;
    else if(vis[x][y]==0){
        OUTPUT(x-1,y-1);
        printf("%c",s1[x-1]);

    }
    else if(vis[x][y]==1){
        OUTPUT(x-1,y);
        printf("%c",s1[x-1]);

    }
    else {
        OUTPUT(x,y-1);
        printf("%c",s2[y-1]);

    }
}
int main(){
	while(scanf("%s %s",s1,s2)!=EOF){
        int len1=strlen(s1);
        int len2=strlen(s2); memset(dp,0,sizeof(dp));
        for(int i = 0;i<=len1;i++)
            vis[i][0] = 1;
        for(int i = 0;i<=len2;i++)
            vis[0][i] = -1;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    vis[i][j]=0;
                }
                else if(dp[i-1][j]>=dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    vis[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i][j-1];
                    vis[i][j]=-1;
                }
            }
        }
     OUTPUT(len1,len2);
     printf("\n");
	}
	return 0;
}
