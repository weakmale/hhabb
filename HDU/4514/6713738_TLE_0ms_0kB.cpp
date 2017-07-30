#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=10000+10;
int n,m;
struct node{
	int from;
	int to;
	int vi;
	int nest;
};
node ega[MAXN*MAXN];
int head[MAXN];
int l;
int F[MAXN];
bool k;

int init(){
	for(int i=1;i<=n;i++){
		F[i]=i;
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
	int r=x;
	while(r!=F[r])
		r=F[r];
	return r;
}
void Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny){
		
		F[ny]=nx;
	}
	else{
		k=true;
	}
}
int vis[MAXN];
int vir[MAXN];
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
					 vis[v] = true;
					 Q.push(v);
				 }
			 }
		 }
	 }
}
int main(){
	while(scanf("%d %d",&n ,&m )!=EOF){
		int a ,b ,c;init();
		for(int i=0;i<m;i++){
			scanf("%d %d %d" ,&a, &b, &c);
			Union(a,b);
			join(a,b,c);
			join(b,a,c);
		}
		if(k){
			printf("YES\n");
			continue;
		}
		BFS(1);
		BFS(nod);
		printf("%d\n",cnt);
	}
	return 0;
}




//3 2
//1 2 1
//2 3 1












