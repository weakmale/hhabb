#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int MAXX=500+10;
vector <int>G[MAXX];
int male[MAXX];
bool vis[MAXX];
int k,m,n;
bool DFS(int x)
{
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(!vis[v])
        {
            vis[v]=true;
            if(male[v]==-1||DFS(male[v]))
            {
                male[v]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d",&k),k)
    {
        for(int i=0;i<=MAXX;i++)
            G[i].clear();
        scanf("%d %d",&m,&n);
        for(int i=1;i<=k;i++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
        }
        memset(male,-1,sizeof(male));
        int sum=0;
        for(int i=1;i<=m;i++){
            memset(vis,false,sizeof(vis));
            sum+=DFS(i);
        }
        printf("%d\n",sum);
    }
	return 0;
}
