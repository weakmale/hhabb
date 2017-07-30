#include "cstdio"
#include "vector"
#include "cstring"
using namespace std;
int Map[111][111];
bool coler[55];
bool Mp[111][111];
bool l[111];
int c[111];
int n,k;
bool DFS(int u){
    for(int i=1;i<=n;i++){
        if(Mp[u][i]&&!l[i]){
            l[i]=true;
            if(!c[i]||DFS(c[i])){
                c[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d %d",&n,&k),n||k){
        memset(coler,false,sizeof(coler));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&Map[i][j]); coler[Map[i][j]]=true;
            }
        }
        bool m=false;
        for(int t=1;t<=50;t++){
            if(coler[t]){
                memset(Mp, false, sizeof(Mp));
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        if(Map[i][j]==t) Mp[i][j]=true;
                int sum=0;
                memset(c, 0, sizeof(c));
                for(int i=1;i<=n;i++){
                    memset(l, false, sizeof(l));
                    sum+=DFS(i);
                }
                if(sum>k){
                    if(!m)
                        printf("%d",t),m=true;
                    else
                        printf(" %d",t);
                }
            }
        }
        if(!m) printf("-1");
        puts("");
    }
    return 0;
}