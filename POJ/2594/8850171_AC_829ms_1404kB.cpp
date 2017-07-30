#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
int Map[510][510];
bool vis[510];
int male[510];
int n,m;
bool DFS(int u){
    for(int i=1;i<=n;i++){
        if(Map[u][i]&&!vis[i]){
            vis[i]=true;
            if(male[i]==-1||DFS(male[i])){
                male[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d %d",&n,&m),n||m){
        int ans=0;
        memset(male, -1, sizeof(male));
        memset(Map, false, sizeof(Map));
        for(int i=1;i<=m;i++){
            int a,b; scanf("%d %d",&a,&b);
            Map[a][b]=true;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(Map[i][k]&&Map[k][j])
                        Map[i][j]=true;
        for(int i=1;i<=n;i++){
            memset(vis, false, sizeof(vis));
            ans+=DFS(i);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}