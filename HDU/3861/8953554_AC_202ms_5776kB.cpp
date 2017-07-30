#include "cstdio"
#include "vector"
#include "cstring"
#include "stack"
using namespace std;
vector<int>G1[50010];
vector<int>G3[50010];
stack<int>S;
int low[50010],dfn[50010],instack[50010];
int GG[50010];
int male[50010];
bool vis[50010];
int n,m,num,ans;
void init(){
    for(int i=1;i<=n;i++){
        G1[i].clear(),G3[i].clear(); GG[i]=0;
        low[i]=dfn[i]=instack[i]=0; male[i]=-1; vis[i]=false;
    }
    num=0; ans=0;
    while(!S.empty()) S.pop();
}
void DFS(int u){
    low[u]=dfn[u]=++num;
    instack[u]=2; S.push(u);
    for(int i=0;i<G1[u].size();i++){
        int v = G1[u][i];
        if(instack[v]==0)
            DFS(v),low[u]=min(low[u], low[v]);
        else if(instack[v]==2)
            low[u] = min(dfn[v],low[u]);
    }
    if (low[u]==dfn[u]) {
        ans++;
        while (!S.empty()) {
            int v=S.top(); S.pop();
            GG[v]=ans;
            instack[v]=1;
            if(v==u) break;
        }
    }
}
bool DFS1(int u){
    for(int i=0;i<G3[u].size();i++){
        int  v = G3[u][i];
        if(vis[v]) continue;
        vis[v]=true;
        if(male[v]==-1||DFS1(male[v])){
            male[v]=u;return true;
        }
    }
    return false;
}
void slove(){
    scanf("%d %d",&n,&m);
    init();
    while(m--){
        int a,b; scanf("%d %d",&a,&b);
        G1[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) DFS(i);
    for(int i=1;i<=n;i++){
        int u = GG[i];
        for(int j=0;j<G1[i].size();j++){
            int v = GG[G1[i][j]];
            if(v!=u)
                G3[u].push_back(v);
        }
    }
    int ansi=0;
    for(int i=1;i<=ans;i++){
        memset(vis, false, sizeof(vis));
        ansi+=DFS1(i);
    }
    
    printf("%d\n",ans-ansi);
}
int main(){
    int T; scanf("%d",&T);
    while(T--) slove();
}