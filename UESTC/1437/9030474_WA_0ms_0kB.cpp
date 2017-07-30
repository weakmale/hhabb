#include "cstdio"
#include "vector"
using namespace std;
typedef long long LL;
vector<pair<int, LL>>G[100010];
int first[100010];
int vir[200010];
int vis[100010];
int R[100010];
int dp[200010][40];
LL dis[100010];
int tot;
void DFS(int u,int deep,LL d){
//    if(u==2) printf("%d\n",tot);
    dis[u]=d; vis[u]=true; first[u]=++tot; R[tot]=deep; vir[tot]=u;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].first;
        if(vis[v]) continue;
        DFS(v,deep+1,d+G[u][i].second);
        vir[++tot]=u;R[tot]=deep;
    }
}
void ST(int n){
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            int a = dp[i][j-1],b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = R[a]<R[b]?a:b;
        }
    }
}
int RMQ(int l,int r){
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a = dp[l][k],b = dp[r-(1<<k)+1][k];
    return R[a]<R[b]?a:b;
}
int LCA(int a,int b){
    int x = first[a],y = first[b];
//    printf("%d %d~~%d %d\n",x,y,a,b);
    if(x>y) swap(x, y);
    int r = RMQ(x, y);
    return vir[r];
}
int main(){
    int n,m; scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++){
        int a,b;LL c; scanf("%d %d %lld",&a,&b,&c);
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
//    printf("%d\n",(int)G[1].size());
    tot=0; DFS(1,0,0); ST(2*n-1);
    while(m--){
        int a,b; scanf("%d %d",&a,&b);
        int c = LCA(a, b);
        printf("%lld\n",dis[a]+dis[b]-2*dis[c]);
    }
    return 0;
}