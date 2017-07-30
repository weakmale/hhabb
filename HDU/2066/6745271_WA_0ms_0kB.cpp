#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXX=1002;
int map[MAXX][MAXX];
int a[MAXX];
int b[MAXX];
int T,S ,D;
bool vis[MAXX];
int dis[MAXX];
void dijkstra(int x){
	memset(dis,inf,sizeof(dis)); memset(vis ,false, sizeof(vis));
	dis[x]=0;
	for(int i=0;i<MAXX;i++){
		int k=-1; int maxx=inf-1;
		for(int j=1;j<MAXX;j++){
			if(!vis[j]&&maxx>dis[j]){
				maxx=dis[j];
				k=j;
			}
		}
		if(k==-1)
			return ;
		vis[k]=true;
		for(int j=1;j<MAXX;j++){
			if(!vis[j]&&dis[j]>dis[k]+map[k][j]){
				dis[j]=dis[k]+map[k][j];
			}
		}
	}
}
int main(){
	while(scanf("%d %d %d",&T,&S,&D)!=EOF){
		for(int i=1;i<MAXX;i++){
			for(int j=1;j<MAXX;j++){
				map[i][j]=i==j?0:inf;
			}
		}
		for(int i=0;i<T;i++){
			int a,b,c;
			scanf("%d %d %d",&a ,&b, &c);
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;
		}
		for(int i=0;i<S;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<D;i++){
			scanf("%d",&b[i]);
		}
		int time=inf;
		for(int i=0;i<S;i++){
			dijkstra(a[i]);
			for(int j=0;j<S;j++){
				if(dis[b[j]]<time)
					time=dis[b[j]];
			}
		}
		printf("%d\n",time);
	}
	return 0;
}