#include "cstdio"
#include "vector"
#include "algorithm"
#include "cstring"
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
int a[2010];
bool vis[2010];
LL sum;
vector<int>edge[2010];
LL DFS(int u,int d,int fa,int root){
    LL ret=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v!=fa&&a[root]>=a[v]&&a[root]-a[v]<=d&&!(a[root]==a[v]&&v>root)){
            ret=ret*(DFS(v,d,u,root)+1)%mod;
        }
    }
    return ret;
}
int main(){
    int n,d; scanf("%d %d",&d,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
//    memset(vis, false, sizeof(vis));
    for(int i=1;i<=n;i++){
        sum=(sum+DFS(i,d,-1,i))%mod;
        vis[i]=true;
    }
    printf("%lld\n",sum);
    return 0;
}
