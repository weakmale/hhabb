#include<cstdio>
#include<iostream>
using namespace std;
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
char Map[510][510];
char s[510];
int dp[510][510];
int vis[510][510];
int sum;
int n,m;
void DFS(int x,int y){
	vis[x][y]=true;	
	if(x==n && y==m){
		sum = 1;
		return ;
	}
	for(int i=0;i<3;i++){
		int nx = x + xi[i];
		int ny = y +yi[i];
		if(!vis[nx][ny]&&Map[nx][ny]=='.'&&nx>=1&&nx<=n&&ny>=1&&ny<=m){
			DFS(nx,ny);
		}
	}
	vis[x][y]=false;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",Map[i]+1);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='#')
				Map[i][j]='#';
		}
	}
	sum=0;
	DFS(1,1);
	if(sum) puts("YES");
	else puts("NO");
	return 0;
}