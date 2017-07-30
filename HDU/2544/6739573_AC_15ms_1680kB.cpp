#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
int pr[1002][1002];
int n;
int m;
struct node{
	int from;
	int to;
	int vi;
	int next;
}ega[10001*2];
int head[1002];
int l;
//void kalsn(){
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				pr[i][j]=min(pr[i][j],pr[i][k]+pr[k][j]);
//			}
//		}
//	}
//}

void init(){
	memset(head,-1,sizeof(head)); l=0;
}
void join(int u,int v,int w){
	ega[l].from=u;
	ega[l].to=v;
	ega[l].vi=w;
	ega[l].next=head[u];
	head[u]=l++;
}
bool vis[1002];
int dis[1002];
void klsd(){
	memset(vis,false,sizeof(vis));  memset(dis,inf,sizeof(dis));
	dis[1]=0;
//	vis[1]=true;
//	for(int i=head[1];i!=-1;i=ega[i].next)
//		dis[ega[i].to]=ega[i].vi;
	for(int i=0;i<n;i++){
		int MINN=inf;int k=-1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<MINN){
				MINN=dis[j];k=j;
			}
		}
		if(k==-1)
			return ;
		else  vis[k]=true;
		for(int j=head[k];j!=-1;j=ega[j].next){
			int v=ega[j].to;
			if(!vis[v]&&dis[v]>dis[k]+ega[j].vi){
				dis[v]=dis[k]+ega[j].vi;
			}
		}
	}
}
int main(){
	while(scanf("%d %d",&n,&m),m||n){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				pr[i][j]=i==j?0:inf;
//			}
//		}
		init();
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a, &b, &c);
//			if(pr[a][b]>c)
//		 	pr[a][b]=pr[b][a]=c;
			join(a,b,c);
			join(b,a,c);
		}
//		kalsn();
		klsd();
//		cout<<inf<<endl;
		printf("%d\n",dis[n]);
	}
	return 0;
}