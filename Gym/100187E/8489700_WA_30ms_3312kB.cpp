#include<cstdio>
#include<iostream>
using namespace std;
char Map[510][510];
char s[510];
int dp[510][510];
int main(){
	int n,m;scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",Map[i]+1);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='#')
				Map[i][j]='#';
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=m;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++) dp[i][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Map[i][j]=='.'){
				if(i==1){
					if(dp[i][j-1])
						dp[i][j]=1;
				}
				else if(j==1){
					if(dp[i-1][j])
						dp[i][j]=1;
				}
				else if(dp[i-1][j]||dp[i][j-1])
				 	dp[i][j]=1;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%s\n",Map[i]+1);
	if(dp[n][m]) puts("YES");
	else puts("NO");
	return 0;
}