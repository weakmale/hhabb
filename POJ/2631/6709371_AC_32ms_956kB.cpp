#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN=10000+10;
struct node{
	int form;
	int to;
	int vi;
	int next;
};
node ega[MAXN*2];
int l;
int head[MAXN];
void init(){
	memset(head,-1,sizeof(head)); l=0;
}
void join(int u,int v,int w){
	ega[l].form=u;
	ega[l].to=v;
	ega[l].vi=w;
	ega[l].next=head[u];
	head[u]=l++;
}
int cnt;
int nod;
bool vis[MAXN];
int vir[MAXN];
void BFS(int s){
	
	memset(vis,false ,sizeof(vis));memset(vir,0,sizeof(vir));
	queue<int >Q;Q.push(s);cnt=0;vis[s]=true; vir[s]=0;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=head[u];i!=-1;i=ega[i].next){
			int v=ega[i].to;
			if(!vis[v]){
				if(vir[v]<vir[u]+ega[i].vi){
					vir[v]=vir[u]+ega[i].vi;
					if(cnt<vir[v]){
						cnt=vir[v];
						nod=v;
					}
					vis[v]=true;
					Q.push(v);
				}
			}
		}
	}
}
int main(){
	int a,b,c;init();
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		join(a,b,c);
		join(b,a,c);
	}
	BFS(1);
	BFS(nod);
	printf("%d\n",cnt);
	return 0;
}