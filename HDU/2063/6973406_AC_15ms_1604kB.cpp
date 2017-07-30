#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
vector<int> G[510];
int male[510];
bool vis[510];
bool DFS(int x){
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(!vis[v]){
            vis[v]=true;
            if(male[v]==-1||DFS(male[v])){
                male[v]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int  k,m,n;
	while(scanf("%d",&k),k){
       scanf("%d %d",&n,&m);
        int a,b;
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=1;i<=m;i++)
            male[i]=-1;
        for(int i=1;i<=k;i++){
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
        }
        int  sum=0;
        for(int i=1;i<=n;i++){
            memset(vis,false,sizeof(vis));
            sum+=DFS(i);
        }
        printf("%d\n",sum);
	}
	return 0;
}
