#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using  namespace std;
const int MAXN=1e5+10;
int dp[MAXN][20];
int F[MAXN][20];
int dis[MAXN];
vector<int> G[MAXN];
void DFS(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        F[v][0]=u;
        dp[v][0]=dis[v];
        for(int j=1;j<18;j++)
            F[v][j]=F[F[v][j-1]][j-1];
        for(int j=1;j<18;j++)
            dp[v][j]=dp[v][j-1];
        DFS(v);
    }
}
int main(){
    int T; scanf("%d",&T);
    int kcase=1;
    while(T--){
        int n,m; scanf("%d %d",&n,&m); for(int i=0;i<n;i++) G[i].clear();
        dis[0]=1;
        for(int i=0;i<18;i++)
            dp[0][i]=dis[0],F[0][i]=0;
        for(int i=1;i<n;i++){
            int a;
            scanf("%d %d",&a,&dis[i]);
            G[a].push_back(i);
        }
        DFS(0);
        printf("Case %d:\n",kcase++);
        while(m--){
            int a,b;scanf("%d %d",&a,&b);
            for(int i=17;i>=0;i--)
                if(dp[F[a][i]][i]>=b)
                    a=F[a][i];
            printf("%d\n",a);
        }
    }
    return 0;
}