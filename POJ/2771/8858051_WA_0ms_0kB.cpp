#include "cstdio"
#include "iostream"
#include "vector"
#include "cstring"
#include "cmath"
using namespace std;
struct node{
    int num,h;
    string mc,sp;
}F[510],M[510];
vector<int>G[510];
int n;  int male[510];
bool vis[510];
bool DFS(int u){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(vis[v]) continue;
        vis[v]=true;
        if(male[v]==-1||DFS(male[v])){
            male[v]=u; return true;
        }
    }
    return false;
}
void slove(){
    int t1=0,t2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        G[i].clear();male[i]=-1;
        int h; scanf("%d",&h);
        string s;cin>>s;
        if(s[0]=='M'){
            M[++t1].h=h; M[t1].num=i;
            cin>>M[t1].mc >>M[t1].sp;
        }
        else{
            F[++t2].h=h; F[t2].num=i;
            cin>>F[t2].mc >>F[t2].sp;
        }
    }
    for(int i=1;i<=t2;i++)
        for(int j=1;j<=t1;j++)
            if(fabs(F[i].h-M[i].h)<=40&&F[i].mc==M[j].mc&&F[i].sp!=M[j].sp)
                G[F[i].num].push_back(M[j].num);
    int ans=0;
    for(int i=1;i<=t2;i++){
        memset(vis, false, sizeof(vis));
        ans+=DFS(F[i].num);
    }
    printf("%d\n",n-ans);
}
int main(){
    int T; scanf("%d",&T);
    while(T--)
        slove();
    return 0;
}