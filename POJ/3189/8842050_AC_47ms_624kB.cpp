#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int Map[1010][30];
int pi[30][1010];
int n,m;
int l,r;
int num[30];
bool vis[30];
int cnt[30];
int a[30];
bool DFS(int u){
    for(int i=1;i<=m;i++){
        int ans = Map[u][i];
        if(ans<=r&&ans>=l&&!vis[i]){
            vis[i]=true;
            if(cnt[i]<num[i]){
                pi[i][++cnt[i]]=u;
                return true;
            }
            for(int j=1;j<=num[i];j++){
                if(DFS(pi[i][j])){
                    pi[i][j]=u;
                    return true;
                }
            }
        }
    }
    return false;
}
bool judge(){
    memset(pi,0, sizeof(pi));
    memset(cnt, 0, sizeof(cnt));
    for(int i=1;i<=n;i++){
        memset(vis, false, sizeof(vis));
        if(!DFS(i)) return false;
    }
    return true;
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int t; scanf("%d",&t);
                Map[i][t]=j;
            }
        }
        for(int i=1;i<=m;i++) scanf("%d",&num[i]);
        int minn = 1e9;
        l=1,r=1;
        
        while(l<=r&&r<=m){
            int mid = r-l+1;
            if(judge())
                l++,minn=min(minn,mid);
            else
                r++;
        }
        printf("%d\n",minn);
    }
    return 0;
}