#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char Map[4][510][510];
int vis[510][510];
int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,1,-1};
int sum[4];
int n,m;
void DFS(int x,int y,int num,int step){
	vis[x][y]=true;
	if(x==n&&y==m){
		sum[num] = 1;
		return ;
	}
	for(int i=0;i<3;i++){
		int nx = x +xi[i];
		int ny = y +yi[i];
		if(!vis[nx][ny]&&Map[num][nx][ny]=='.'){
			DFS(nx,ny,num,step+1);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",Map[1][i]+1);
		for(int j=1;j<=m;j++)
			Map[3][i][j]=Map[1][i][j];
	}
	for(int i=1;i<=n;i++){
		scanf("%s",Map[2][i]+1);
		for(int j=1;j<=m;j++){
			if(Map[2][i][j]=='#')
				Map[3][i][j]='#';
		}
	}
	sum[1]=500*600;sum[2]=500*600;sum[3]=0;
//	memset(vis,0,sizeof(vis));
//	DFS(1,1,1,0);
//	memset(vis,0,sizeof(vis));
//	DFS(1,1,2,0);
//	memset(vis,0,sizeof(vis));
	DFS(1,1,3,0);
//	printf("%d %d %d\n",sum[1],sum[2],sum[3]);
	if(sum[3]) puts("YES");
	else puts("NO");
	return 0;
}