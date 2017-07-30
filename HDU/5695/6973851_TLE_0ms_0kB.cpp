#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
vector<int> G[10010];
int du[10010];
int qu[10010];
int n,m;
int k;
void topu(){
    priority_queue< int, vector<int>, less<int> >Q;
    for(int i=1;i<=n;i++)
        if(du[i]==0)
            Q.push(i);
    while(!Q.empty()){
        int u=Q.top(); Q.pop();
        du[u]=-1;
        qu[++k]=u;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            du[v]--;
            if(du[v]==0)
                Q.push(v);
        }
    }
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++)
            G[i].clear();
        memset(du,0,sizeof(du));
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            du[b]++;
        }
        k=0;
        topu();
        int sum=0; int minn=10000000;
        for(int i=1;i<=k;i++){
            if(qu[i]<minn){
                minn=qu[i];
            }
            sum+=minn;
        }
        printf("%d\n",sum);
	}
	return 0;
}
