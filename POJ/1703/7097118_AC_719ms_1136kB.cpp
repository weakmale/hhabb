#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
using namespace std;
const int MAXX=1e5+10;
int F[MAXX];
int M[MAXX];
void init(int n){
    for(int i=1;i<=n;i++)
        F[i]=i,M[i]=0;
}
int Found(int x){
    if(x==F[x]) return x;
    int t=Found(F[x]);
    M[x]=(M[F[x]]+M[x])&1;
    return F[x]=t;
}
void Union(int x,int y){
    int nx=Found(x); int ny=Found(y);
    if(nx==ny)
        return ;
    F[ny]=nx;
    M[ny]=(M[x]-M[y]+1)&1;
    
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d %d",&n,&m);init(n);
        while(m--){
            char a[10]; int b,c;
            scanf("%s",a);
            scanf("%d %d",&b,&c);
            if(a[0]=='D')
                Union(b,c);
            else{
                int nx=Found(b); int ny=Found(c);
                if(nx==ny){
                    if(M[b]==M[c]){
                        printf("In the same gang.\n");
                    }
                    else{
                        printf("In different gangs.\n");
                    }
                }
                else{
                    printf("Not sure yet.\n");
                }
            }
        }
    }
    return 0;
}
