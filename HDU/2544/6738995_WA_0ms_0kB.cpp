#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0xffff;
int pr[1002][1002];
int n;
int m;
struct node{
	int from;
	int to;
	int vi;
	int next;
}ega[1002*2];
int head[1002];
int l;
void kalsn(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				pr[i][k]=min(pr[i][k],pr[i][j]+pr[j][k]);
			}
		}
	}
}
//bool vis[1002];
//int dis[1002];
//void klsd(){
//	memset(vis,false,sizeof(vis));  memset(dis,inf,sizeof(dis));
//	dis[1]=0;
//	for(int i=0;i<n;i++){
//		int MINN=inf;int k=-1;
//		for(int j=1;j<=n;j++){
//			if(&vis[j]&&dis[j]<MINN)
//				MINN=dis[j],k=j;
//		}
//		if(k==-1)
//			break;
//		else  vis[k]=true;
//		for(int j=head[k];j!=-1;j=ega[j].next){
//			int v=ega[i].to;
//			if(!vis[v]&&dis[v]>dis[k]+ega[i].vi)
//				dis[v]=dis[k]+ega[i].vi;
//		}
//	}
//}
int main(){
	while(scanf("%d %d",&n,&m),m||n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)
					pr[i][j]=0;
				else
					pr[i][j]=inf;
			}
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a, &b, &c);
			pr[a][b]=c;
			pr[b][a]=c;
//			join(a,b,c);
//			join(b,a,c);
		}
		kalsn();
		printf("%d\n",pr[1][n]);
	}
	return 0;
}