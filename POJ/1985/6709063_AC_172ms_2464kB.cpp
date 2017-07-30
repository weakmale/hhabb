#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=40000+10;
int n,m;
struct node{
	int from;
	int to;
	int vi;
	int next;
};
int head[MAXN];
node ega[MAXN*2];
int l;
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
int vir[MAXN];
int vis[MAXN];
int nod;
int cnt;
void BFS(int s){
	memset(vir,0,sizeof(vir));memset(vis,false ,sizeof(vis));
	queue<int> Q; Q.push(s); vis[s]=true; vir[s]=0; cnt=0;
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int i=head[u];i!=-1;i=ega[i].next){
			int v=ega[i].to;
			if(!vis[v]){
				if(vir[v]<vir[u]+ega[i].vi){
					vir[v]=vir[u]+ega[i].vi;
					if(cnt<vir[v]){
						cnt=vir[v];
						nod=v;
						
					}
				}
				vis[v]=true;
				Q.push(v);
			}
		}
	}
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		int a,b,c; char s;init();
		for(int i=0;i<m;i++){
			scanf("%d %d %d %c",&a,&b,&c,&s);
			join(a,b,c);
			join(b,a,c);
		}
		BFS(1);
		BFS(nod);
		printf("%d\n",cnt);
	}
	return  0;
}