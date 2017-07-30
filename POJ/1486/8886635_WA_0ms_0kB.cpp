#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
vector<int>G[10010];
struct node{
    int x,xm;
    int y,ym;
}tr[1000];
int kcase;
int n;
int Map[1010][2010];
int male[1010];
bool vis[1010];
int ph[110];
bool DFS(int u){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!vis[v]&&!Map[u][v]){
            vis[v]=true;
            if(male[v]==-1||DFS(male[v])){
                male[v]=u;return true;
            }
        }
    }
    return false;
}
void slove(){
    memset(male, -1, sizeof(male));
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&tr[i].x,&tr[i].xm,&tr[i].y,&tr[i].ym);
        G[i].clear();
    }
    for(int i=1;i<=n;i++){
        int x,y; scanf("%d %d",&x,&y);
        for(int j=1;j<=n;j++)
            if(x>tr[j].x&&x<tr[j].xm&&y>tr[j].y&&y<tr[j].ym)
                G[j].push_back(n+i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis, false, sizeof(vis));
        ans+=DFS(i);
    }
    int K=0;
    printf("Heap %d\n",++kcase);
    if(ans!=n){ puts("none\n"); return;}
    else{
        for(int i=1;i<=n;i++) ph[i]=male[i+n];
        for(int i=1;i<=n;i++){
            Map[ph[i]][i+n]=true;
            ans=0;
            memset(male, -1, sizeof(male));
            for(int i=1;i<=n;i++){
                memset(vis, false, sizeof(vis));
                ans+=DFS(i);
            }
            if(ans!=n){
                if(K)printf(" "); K=1;
                printf("(%c %d)",i-1+'A',ph[i]);
            }
            Map[ph[i]][i+n]=false;
        }
    }
    if(K) puts("\n");
    else puts("none\n");
}
int main(){
    while(scanf("%d",&n),n)
        slove();
    return 0;
}