#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN=30000+10;
struct node{
	int from;
	int to;
	int v;
	int next;
}ega[MAXN*2];
int head[MAXN];
int l;
void init (){
	memset(head,-1,sizeof(head)); l=0;
}
void join(int a,int b,int c){
	ega[l].from=a;
	ega[l].to=b;
	ega[l].v=c;
	ega[l].next=head[a];
	head[a]=l++;
}
int nod;
int vis[MAXN];
int vir[MAXN];
int cnt;
void BFS(int s){
	memset(vir,0,sizeof(vir));memset(vis,false,sizeof(vis));
	queue< int > Q;Q.push(s);vis[s]=true; vir[s]=0;cnt=0;
	
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		
		for(int i=head[u];i!=-1;i=ega[i].next){
			int v=ega[i].to;
			if(!vis[v]){
				if(vir[v]<vir[u]+ega[i].v){
					vir[v]=vir[u]+ega[i].v;
					if(vir[v]>cnt){
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
void BFS(int s);
int main(){
	int T;int t=1; scanf("%d",&T);
	while(T--){
		int n;
		init();
		scanf("%d",&n);
		int a,b,c;
		for(int i=0;i<n-1;i++){
			scanf("%d %d %d",&a,&b,&c);
			join(a,b,c);
			join(b,a,c);
		}
		BFS(0);
		BFS(nod);
		printf("Case %d: %d\n",t++,cnt);
	}
	return 0;
}