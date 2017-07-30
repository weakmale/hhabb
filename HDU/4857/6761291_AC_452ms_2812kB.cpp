#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<functional>

using namespace std;
const int MAXX=30011;
const int MAXXX=100011;
int n;
int m;
int du[MAXX];
struct node{
	int to;
	int next;
};
node edge[MAXXX];
int num;
int head[MAXX];
void init(){
	void join(int u,int v);
	memset(head,-1,sizeof(head));
	num=0;
	memset(du,0,sizeof(du));
}
void join(int u,int v){
	edge[num].to=v;
	edge[num].next=head[u];
	head[u]=num++;
}
int pi[MAXX];
void topo(){
	priority_queue< int> Q;//, vector< int >, less< int > 
	for(int i=1;i<=n;i++){
		if(du[i]==0){
			Q.push(i);
		}
	}
	int k=0;
	while(!Q.empty()){
		int u=Q.top(); Q.pop();
		du[u]=-1;
		pi[k++]=u;
		for( int i=head[u]; i!=-1; i=edge[i].next ){
			int v=edge[i].to;
			du[v]--;
			if(du[v]==0)
				Q.push(v);
		}
	}
	printf("%d",pi[n-1]);
	for(int i=n-2;i>=0;i--){
		printf(" %d",pi[i]);
	}
	printf("\n");
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		init();
		for(int i=0; i<m; ++i){
			int a,b;
			scanf("%d %d", &a, &b);
			du[a]++;
			join(b,a); 
//			printf("%d~~~%d\n",a,b,du[b]);
		}
		topo();
	}
	return 0;
}