#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int from;
	int to;
	int vi;
	int next;
};
node ega[5001*2];
int head[5001];
int l;
int init(){
	memset(head,-1,sizeof(head));
	l=0;
}
void join(int u,int v,int w){
	ega[l].from=u;
	ega[l].to=v;
	ega[l].vi=w;
	ega[l].next=head[u];
	head[u]=l++;
}
int vis[5001];
int vir[5002];
void prim(int r){
	int u=r;
	for(int i=head[u];i!=-1;i=ega[i].next){
		int v=ega[i].to;
		if(vir[v]>ega[i].vi&&!vis[v]){
			vir[v]=ega[i].vi;
		}
	}
	
}
int main(){
	int n;
	int a,b,c;
	while(~scanf("%d",&n),n){
	init();	
	for(int i=0;i<n*(n-1)/2;i++){
		scanf("%d %d %d",&a,&b,&c);
		join(a,b,c);
		join(b,a,c);
	}
	int x=1;
	int li=0;
	int sum=0;
	memset(vis,false,sizeof(vis));
	memset(vir,0x3f3f3f,sizeof(vir));
	while(li<n-1){
		vis[x]=true;
		prim(x);
		int minn=0x3f3f3f;
		for(int i=1;i<=n*(n-1)/2;i++){
			if(vir[i]<minn&&!vis[i])
			{
				minn=vir[i];
				x=i;
			}
		}
		li++;
		sum+=minn;
		if(li==n-1)
			break;
	}
	printf("%d\n",sum);
}
	return 0;
}