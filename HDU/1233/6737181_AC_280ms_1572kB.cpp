#include<cstdio>
#include<cstring>
const int MAXX=105;
const int inf=0x3f3f3f;
struct node{
	int from;
	int to;
	int vi;
	int next;
};
node ega[MAXX*MAXX];
int n;
int ans;
int head[MAXX];
int l=0;
void init(){
	l=0;
	memset(head,-1,sizeof(head));
}
void join(int u,int v,int w){
	ega[l].from=u;
	ega[l].to=v;
	ega[l].vi=w;
	ega[l].next=head[u];
	head[u]=l++;
}
int dis[MAXX];

void prim(){
	int vis[MAXX]={0};
	memset(dis,inf,sizeof(dis));
	dis[1]=0;ans=0;
	for(int i=1;i<=n;i++){
		int k=-1,tp=inf;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&tp>dis[j]){
				tp=dis[j]; k=j;
			}
		}
		vis[k]=1;ans+=tp;
		for(int j=head[k];j!=-1;j=ega[j].next){
			int v=ega[j].to;
			if(!vis[v]&&dis[v]>ega[j].vi){
				dis[v]=ega[j].vi;
			}
		}
	}
}
int main(){
	while(~scanf("%d",&n),n){
		int m=n*(n-1)/2;
		int a,b,c;
		init();
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			join(a,b,c);
			join(b,a,c);
		}
		prim();
		printf("%d\n",ans);
	}
	return 0;
}