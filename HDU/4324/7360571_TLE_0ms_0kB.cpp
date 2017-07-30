#include "cstdio"
#include "cstring"
using namespace std;
char Map[2010][2010];
bool vis[2010][2010];
bool K;
void DFS(int u,int fa,int ff,int fff,int n){
//    printf("%d %d %d %d\n",fff,ff,fa,u);
    if(u==fff){
        K=false; return ;
    }
    for(int i=1;i<=n;i++){
        if(Map[u][i]=='1'&&!vis[u][i]){
            vis[u][i]=true;
            DFS(i,u,fa,ff,n);
            if(!K)
                return ;
        }
    }
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s",Map[i]+1);
        K=true; memset(vis,false,sizeof(vis));
        for(int i=1;i<=n&&K;i++){
            for(int j=1;j<=n&&K;j++){
                if(Map[i][j]=='1'&&!vis[i][j]){
                    vis[i][j]=true;
                    DFS(j,i,-1,-1,n);
                }
            }
        }
        printf("Case #%d: ",kcase++);
        if(!K)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}