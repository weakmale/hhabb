#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
vector<int>G[210];
bool vis[210];
int Map[210][210];
int male[210];
int cnt[210];
int n,m,k;
bool use[210];
int top;
int tim[210];
bool DFS(int u,int num){
    if(u<=num) return false;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]) continue;
        vis[v]=true;
        if(male[v]==-1||DFS(male[v],num)){
            male[v]=u;
            return true;
        }
    }
    return false;
}
bool ok(int num,int flv){
    if(male[flv]==num) return true;
    int ans=0;
    for(int i=1;i<=n;i++){
        tim[i]=male[i];
        vis[i]=false;
        if(male[i]==num) ans=i;
    }
    int t=male[flv];
    male[flv]=num;
    male[ans]=-1;
    if(DFS(t,num)) return true;
    else{
        for(int i=1;i<=n;i++) male[i]=tim[i];
        return false;
    }

}
bool fina(int num){
    if(num==n+1){
        if(++top==k) return true;
        else return false;
    }
    for(int i=0;i<G[num].size();i++){
        int v=G[num][i];
        if(!use[v]&&ok(num,v)){
            use[v]=true;
            cnt[num]=v;
            if(fina(num+1)) return true;
            use[v]=false;
        }
    }
    return  false;
}
void slove(int kcase){
    scanf("%d %d %d",&n,&m,&k);
    memset(Map, false, sizeof(Map));
    memset(male, -1, sizeof(male));
    for (int i=0; i<n; i++) G[i].clear();
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            int t; scanf("%d",&t);
            Map[j][t]=true;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!Map[i][j]) G[i].push_back(j);
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis, false, sizeof(vis));
        ans+=DFS(i,-1);
    }
    
    printf("Case #%d: ", kcase);
    if(ans!=n){
        puts("-1");return;
    }
    memset(use, false, sizeof(use));
    top=0;
    if(fina(1)){
        printf("%d",cnt[1]);
        for(int i=2;i<=n;i++) printf(" %d",cnt[i]);
        puts("");
    }
    else puts("-1");
}
int main(){
    int kcase=0;
    int T; scanf("%d",&T);
    while(T--){
        
        slove(++kcase);
    }
    return 0;
}