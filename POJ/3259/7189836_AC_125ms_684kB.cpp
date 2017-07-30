#include "cstdio"
#include "vector"
#include "algorithm"
#include "queue"
#include "cstring"
using namespace std;
struct node{
    int from,to,vi,next;
}edge[2510*2+210];
int head[510];
int ln;
int n,m,w;
void init(){
    ln=0; memset(head, -1, sizeof(head));
}
void join(int u,int v,int vi){
    edge[ln].from=u;
    edge[ln].to=v;
    edge[ln].vi=vi;
    edge[ln].next=head[u];
    head[u]=ln++;
}
int vis[510];
int sum[510];
int dis[510];
bool spfa(int t){
    for(int i=1;i<=n;i++)
        dis[i]=1e7;
    memset(vis,false,sizeof(vis));
    memset(sum,0,sizeof(sum));
    dis[t]=0;
    vis[t]=1;
    queue<int>Q;
    Q.push(t);
    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].vi){
                dis[v]=dis[u]+edge[i].vi;
                sum[v]++;
                if(sum[v]>n)
                    return true;
                if(!vis[v]){
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
    return false;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        init();
        scanf("%d %d %d",&n,&m,&w);
        while(m--){
            int a,b,vi;
            scanf("%d %d %d",&a,&b,&vi);
            join(a,b,vi);
            join(b,a,vi);
        }
        while(w--){
            int a,b,vi;
            scanf("%d %d %d",&a,&b,&vi);
            join(a,b,-vi);
        }
        if(spfa(1)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}