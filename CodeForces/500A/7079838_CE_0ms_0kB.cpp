#include "vector"
#include "cstdio"
using namespace std;
vector<int> G[3010];
bool vis[3010];
void DFS(int u){
    vis[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v])
            DFS(v);
    }
}
int main(){
    int n,t;
    memset(vis,false,sizeof(vis));
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n-1;i++){
        int a;
        scanf("%d",&a);
        G[i].push_back(a+i);
    }
    DFS(1);
    if(vis[t])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}