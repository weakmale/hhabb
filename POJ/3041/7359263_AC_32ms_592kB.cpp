#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
vector<int>G[510];
bool vis[510];
int hang[510];
bool DFS(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v]){
            vis[v]=true;
            if(hang[v]==0||DFS(hang[v])){
                hang[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=m;++i){
            int a,b; scanf("%d %d",&a,&b); G[a].push_back(b);
        }
        memset(hang, 0, sizeof(hang));
        int sum=0;
        for(int i=1;i<=n;i++){
            memset(vis, false, sizeof(vis));
            sum+=DFS(i);
        }
        printf("%d\n",sum);
    }
    return 0;
}
