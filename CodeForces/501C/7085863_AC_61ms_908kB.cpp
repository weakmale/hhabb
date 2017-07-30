#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int du[100000];
int yihuo[100000];
int main(){
    int n; scanf("%d",&n);
    queue<int> Q;
    int bian=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&du[i],&yihuo[i]);
        if(du[i]==1){
            Q.push(i);
        }
        bian+=du[i];
    }
    printf("%d\n",bian/2);
    while(!Q.empty()){
        int v=Q.front(); Q.pop();
        if(du[v]!=1) continue;
        int u=yihuo[v]; yihuo[u]^=v; du[u]--;
        if(du[u]==1)
            Q.push(u);
        printf("%d %d\n",u,v);

    }
    return 0;
}
