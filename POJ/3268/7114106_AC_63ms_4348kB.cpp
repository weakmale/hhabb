#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
const int inf=1<<29;
int Map[1010][1010];
int dis[1010];
int dis2[1010];
bool vis[1010];
int ans;
void Dijkstra(int x,int n){
    for(int i=1;i<=n;i++){
        vis[i]=false;
        dis[i]=Map[x][i];
        dis2[i]=Map[i][x];
    }
    int k=-1;
    for(int i=1;i<=n;i++){
        int m=inf;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&m>dis[j]){
                m=dis[j];k=j;
            }
        }
        vis[k]=true;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[k]+Map[k][j]<dis[j]){
                dis[j]=Map[k][j]+dis[k];
            }
        }
    }
    for(int i=1;i<=n;i++) vis[i]=false;
    for(int i=1;i<=n;i++){
        int m=inf;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&m>dis2[j])
                m=dis2[j],k=j;
        }
        vis[k]=true;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis2[k]+Map[j][k]<dis2[j]){
                dis2[j]=Map[j][k]+dis2[k];
            }
        }
    }
    ans=-1;
    for(int i=1;i<=n;i++)
        if(ans<dis[i]+dis2[i])
            ans=dis[i]+dis2[i];
}
int main(){
    int n,m,x;
    while(scanf("%d %d %d",&n,&m,&x)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    Map[i][j]=inf;
                else
                    Map[i][i]=0;
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            Map[a][b]=c;
        }
        Dijkstra(x, n);
        printf("%d\n",ans);
    }
    return 0;
}