#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXX=10000+10;
struct node{
	int from;
	int to;
	int v1;
	int next;
};
int n;
node ega[MAXX*2];
int head[MAXX];
int l;
void init(){
	memset(head,-1,sizeof(head));
	l=0;
}
void join(int u,int v,int w){
	ega[l].from=u;
	ega[l].to=v;
	ega[l].v1=w;
	ega[l].next=head[u];
	head[u]=l++;
}
int vir[MAXX];
int vis[MAXX];
int cnt;
void BFS(int s){
	
	memset(vir,0,sizeof(vir));  memset(vis,false,sizeof(vis));  cnt=0;
	queue< int > Q;  Q.push(s);  vis[s]=true;  vir[s]=0;
	while( !Q.empty() ){
		int u = Q.front();Q.pop();
		for(int i=head[u]; i!=-1 ; i=ega[i].next){
			int v=ega[i].to;
			if(!vis[v]){
				if( vir[v]<vir[u] + ega[i].v1 ){
					vir[v] = vir[u] + ega[i].v1;
					if(vir[v]>cnt){
						cnt=vir[v];
					}
				}
				vis[v]=true;
				Q.push(v);
			}
		}
	}
}
int main(){
	while(scanf("%d",&n)){
		int a,b;   init();
		for(int i=2;i<=n;i++){
			scanf("%d%d",&a,&b);
			join(i,a,b);
			join(a,i,b);
		}
		for(int i=1;i<=n;i++){
			BFS(i);
			printf("%d\n",cnt);
		}
	}
	return 0;
}