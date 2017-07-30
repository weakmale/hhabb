#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
const int inf=1e7;
int Map[1010][1010];
int dis[1010];
int dis2[1010];
bool vis[1010];
int ans;
void Dijkstra(int x,int n){
    memset(dis2, 0, sizeof(dis2));
    memset(dis,0,sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for(int i=1;i<=n;i++){
        dis[i]=Map[x][i];
        dis2[i]=Map[i][x];
    }
    for(int i=1;i<=n;i++){
        int m=inf; int k=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&m>dis[j])
                m=dis[j],k=j;
        }
        if(k==-1)
            break;
        vis[k]=true;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[k]+Map[k][j]<dis[j]){
                dis[j]=Map[k][j]+dis[k];
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i=1;i<=n;i++){
        int m=inf; int k=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&m>dis2[j])
                m=dis2[j],k=j;
        }
        if(k==-1)
            break;
        vis[k]=true;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis2[k]+Map[j][k]<dis2[j]){
                dis2[j]=Map[k][j]+dis2[k];
            }
        }
    }
    ans=0;
    for(int i=1;i<=n;i++)
        if(dis[i]!=inf&&dis2[i]!=inf)
            ans=max(ans,dis[i]+dis2[i]);
}
int main(){
    int n,m,x;
    while(scanf("%d %d %d",&n,&m,&x)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                Map[i][j]=inf;
            Map[i][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d  %d %d",&a,&b,&c);
            Map[a][b]=min(Map[a][b],c);
        }
        Dijkstra(x, n);
        printf("%d\n",ans);
    }
    return 0;
}