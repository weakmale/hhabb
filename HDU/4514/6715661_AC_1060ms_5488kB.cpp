#pragma comment(linker, "/STACK:102400000000000000000,1024000000000000000000")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5+3;
int n,m;
struct node{
	int from;
	int to;
	int vi;
	int nest;
};
node ega[N*2*10];
int head[N];
int l;
int vir[N];
bool k;
int init(){
	for(int i=1;i<=n;i++){
		vir[i]=i;
	}
	memset(head,-1,sizeof(head)); k=false;
}
void join(int u,int v,int w){
	ega[l].from=u;
	ega[l].to=v;
	ega[l].vi=w;
	ega[l].nest=head[u];
	head[u]=l++;
}
int  Found(int x){
	while(x!=vir[x])
		x=vir[x];
	return x;
}
void Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny){
		
		vir[ny]=nx;
	}
	else{
		k=true;
	}
}
bool vis[N];
int cnt;
int nod;
void BFS(int s){
	memset(vis ,false ,sizeof(vis) );  memset(vir ,0 ,sizeof(vir) );   cnt = 0;
 	queue< int > Q;  Q.push(s);  vis[s] = true;   vir[s] = 0;
 	while( !Q.empty() ){
 		int u = Q.front();   Q.pop();
 		for( int i = head[u]; i != -1; i = ega[i].nest ){
 			int v = ega[i].to;
 			if( !vis[v] ){
 				if( vir[v] < vir[u] + ega[i].vi ){
 					vir[v] = vir[u] + ega[i].vi;
 					if(vir[v] > cnt){
 						cnt = vir[v];
 						nod = v;
 					}
				 }
				 vis[v] = true;
					 Q.push(v);
			 }
		 }
	 }
}
int main(){
	while(scanf("%d %d",&n ,&m )!=EOF){
		int a ,b ,c;init();
		int x;
		for(int i=0;i<m;i++){
			scanf("%d %d %d" ,&a, &b, &c);
			x=a;
			if(k) 
				continue;
			Union(a,b);
			join(a,b,c);
			join(b,a,c);
		}
		if(k){
			printf("YES\n");
			continue;
		}
		BFS(x);
		BFS(nod);
		printf("%d\n",cnt);
	}
	return 0;
}