#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
bool Map[110][110];
vector<int> G[110];
int color[110];
bool DFS(int u,int c){
    color[u]=c;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(color[v]!=-1){
            if(color[v]==color[u])
                return false;
        }
        else if(!DFS(v,!c)){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memchr(Map, false, sizeof(0));
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=1;i<=n;i++){
            int t;
            while(scanf("%d",&t),t){
                Map[i][t]=true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!Map[i][j]||!Map[j][i])
                    G[i].push_back(j),G[j].push_back(i);
            }
        }
        bool K=true;
        for(int i=1;i<=n;i++){
            if(color[i]==-1&&!DFS(i,0)){
                K=false; break;
            }
        }
        if(K)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}