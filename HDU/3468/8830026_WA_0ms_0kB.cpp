#include "cstdio"
#include "iostream"
#include "queue"
#include "cstring"
#include "vector"
using namespace std;
int n,m;
struct node {
    int x,y;
}rally[60];
int fa[200*200];
int xi[4]={0,0,1,-1};
int yi[4]={1,-1,0,0};
vector<int>G[60];
bool visi[200*200];
bool vis[200][200];
int dis[60][200*200];
char Map[200][200];
int gold[200*200];
int Num(char s){
    if(s>='A'&&s<='Z') return s-'A'+1;
    if(s>='a'&&s<='z') return s-'a'+27;
    return 0;
}
void BFS(int num,node dian){
    memset(vis, false, sizeof(vis));
    queue<node>Q;
    while (!Q.empty()) Q.pop();
    Q.push(dian);
    int k = dian.x*m+dian.y;
    dis[num][k]=0;
    while(!Q.empty()){
        node u=Q.front();Q.pop();
        for(int i=0;i<4;i++){
            int nx = u.x+xi[i];
            int ny = u.y+yi[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&Map[nx][ny]!='#'&&!vis[nx][ny]){
                vis[nx][ny]=true;
                node v={nx,ny};
                Q.push(v);
                dis[num][nx*m+ny]=dis[num][u.x*m+u.y]+1;
            }
        }
    }
}
bool DFS(int u){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(visi[v]) continue;
        visi[v]=true;
        if(fa[v]==-1||DFS(fa[v])){
            fa[v]=u;
            return true;
        }
        
    }
    return false;
}
void solve(){
    for(int i=0;i<60;i++)G[i].clear();
    int ans=0;int t=0;
    memset(dis,-1, sizeof(dis));
    for(int i=0;i<n;i++){
        scanf("%s",Map[i]);
        for(int j=0;j<m;j++){
            int num = Num(Map[i][j]);
            if(Map[i][j]=='*') gold[++t]=i*m+j;
            if(num)
                rally[num]={i, j},ans= max(ans,num);
        }
    }
    for(int i=1;i<=ans;i++)
        BFS(i,rally[i]);
    if(ans==1){ puts("-1");return; }
    for(int i=1;i<ans;i++){
        int k=rally[i+1].x*m+rally[i+1].y;
        if(dis[i][k]==-1){
            puts("-1");return;
        }
    }
    for(int i=1;i<ans;i++){
        int k=rally[i+1].x*n+rally[i+1].y;
        for(int j=1;j<=t;j++){
            if(dis[i][gold[j]]+dis[i+1][gold[j]]==dis[i][k])
                G[i].push_back(ans+j);
        }
    }
    int num=0;
    memset(fa, -1, sizeof(fa));
    for(int i=1;i<ans;i++){
        if(fa[i]==-1){
            memset(visi, false, sizeof(visi));
            if(DFS(i))
                num++;
        }
    }
    printf("%d\n",num);
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        solve();
    }
    return 0;
}
