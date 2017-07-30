#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int inf=0x3f3f3f3f;
const int MAXX=750;
int n,m;
int x[MAXX];
int y[MAXX];
int map[MAXX][MAXX];
bool vis[MAXX];
int dis[MAXX];
int pre[MAXX];
void prim(){
	memset(vis,false,sizeof(vis));  memset(dis,inf,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i]=map[1][i];
		pre[i]=1;
	}
	vis[1]=true;
	int k=-1;
	for(int i=1;i<n;i++){
		int M=inf;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<M){
				k=j; M=dis[j];
			}
		}
		if(map[pre[k]][k])
			printf("%d %d\n",pre[k],k);
		vis[k]=true;
		for(int j=1;j<=n;j++){
			if(dis[j]>map[k][j]){
				dis[j]=map[k][j];
				pre[j]=k;
			}
		}
	}
}


int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			for(int j=1;j<i;j++)
				map[i][j]=map[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			map[i][i]=inf;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			map[a][b]=map[b][a]=0;
		}
		prim();
	}
	return 0;
}