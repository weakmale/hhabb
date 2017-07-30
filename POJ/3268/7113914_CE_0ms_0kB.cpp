/*
Memory 4136K
Time    63MS
*/
#include <iostream>
using namespace std;
#define MAXV 1010
#define inf 1<<29

int map[MAXV][MAXV],d[MAXV],dback[MAXV];
bool vis[MAXV];
int n,m,x;

int dijkstra(){
	
	int i,j,v,mi;
	for(i=1;i<=n;i++){
		vis[i]=0;
		d[i]=map[x][i];
		dback[i]=map[i][x];
	}
	
	for(i=1;i<=n;i++){
		mi=inf;
		for(j=1;j<=n;j++)
			if(!vis[j] && d[j]<mi){
				v=j;
				mi=d[j];
			}
			vis[v]=1;
			
			for(j=1;j<=n;j++){
				if(!vis[j] && map[v][j]+d[v]<d[j])
					d[j]=map[v][j]+d[v];
			}
	}
	
	for(i=1;i<=n;i++) vis[i]=0;
	
	for(i=1;i<=n;i++){
		mi=inf;
		for(j=1;j<=n;j++)
			if(!vis[j] && dback[j]<mi){
				v=j;
				mi=dback[j];
			}
			vis[v]=1;
			
			for(j=1;j<=n;j++){
				if(!vis[j] && map[j][v]+dback[v]<dback[j])
					dback[j]=map[j][v]+dback[v];
			}
	}
	mi=-1;
	for(i=1;i<=n;i++){
		if(d[i]+dback[i]>mi)
			mi=d[i]+dback[i];
	}
	return mi;
}

int main(){
	int i,a,b,c,j;
	while(~scanf("%d%d%d",&n,&m,&x)){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				if(i!=j) map[i][j]=inf;
				else map[i][j]=0;
		}
		
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=c;
		}
		
		printf("%d\n",dijkstra());
	}
	return 0;
}