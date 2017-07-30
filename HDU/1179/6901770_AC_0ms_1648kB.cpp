#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
vector <int> G[110];
int n;
int m;
int miz[110];
bool vis[110];
bool DFS(int x){
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(!vis[v]){
            vis[v]=true;
            if(miz[v]==-1||DFS(miz[v]))
            {
                miz[v]=x;
                return true;
            }
        }
    }
    return false;
}
void init(){
    for(int i=1;i<=111;i++)
           G[i].clear();
}
int main(){
	while(scanf("%d",&n)!=EOF){
        init();
        int a,b;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&a);
            for(int j=1;j<=a;j++){
                scanf("%d",&b);
                G[b].push_back(i);
            }
        }
        memset(miz,-1,sizeof(miz));
        int sum=0;
        for(int i=1;i<=n;i++){
            memset(vis,false,sizeof(vis));
            sum+=DFS(i);
        }
        printf("%d\n",sum);
	}
	return 0;
}
