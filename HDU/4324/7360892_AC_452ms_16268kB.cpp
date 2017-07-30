#include "cstdio"
#include "cstring"
#include "vector"
using namespace std;
char Map[2010][2010];
bool vis[2010];
bool K;
vector<int> G[2010];
void DFS(int u,int fa,int ffa,int fffa,int t){
    if(t==3){
        if(u==fffa)
            K=false;
        return;
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v])
            DFS(v,u,fa,ffa,t+1);
    }
    vis[u]=true;
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n; scanf("%d",&n);
        K=true;
        for(int i=1;i<=n;i++){
            scanf("%s",Map[i]+1);
            G[i].clear(); vis[i]=false;
            for(int j=1;j<=n;j++){
                if(Map[i][j]=='1'){
                    G[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=n&&K;i++){
            DFS(i,-1,-1,-1,0);
        }
        printf("Case #%d: ",kcase++);
        if(!K)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}