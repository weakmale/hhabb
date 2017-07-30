#include "cstdio"
#include "algorithm"
#include "vector"
#include "set"
using namespace std;
int a[100010];
set<int> ai[100010];
int main(){
    int n,m; scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1; i<=m; i++) {
        int x,y; scanf("%d %d",&x,&y);
        ai[a[x]].insert(a[y]);
        ai[a[y]].insert(a[x]);
    }
    int maxx = 1;
    for(int i=1;i<=n;i++){
        if((int)ai[i].size()>(int)ai[maxx].size())
            maxx = i;
    }
    printf("%d\n",maxx);
    return 0;
}