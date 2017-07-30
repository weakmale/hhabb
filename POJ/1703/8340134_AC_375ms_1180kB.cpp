#include "cstdio"
using namespace std;
int F[200010];
int R[100010];
int Found(int x){
    if(F[x]==x) return x;
    int t=F[x];
    F[x]=Found(F[x]);
    R[x]=(R[x]+R[t])%2;
    return F[x];
}
void Union(int x,int y){
    int nx=Found(x);int ny=Found(y);
    if(nx!=ny){
        F[ny]=nx;
        R[ny]=(R[x]-R[y]+1+2)%2;
    }
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d %d" ,&n,&m);
        for(int i=1;i<=n;i++) F[i]=i,R[i]=0;
        while(m--){
            char s[2];int a,b;
            scanf("%s %d %d",s,&a,&b);
            if(s[0]=='A'){
                int na=Found(a),nb=Found(b);
                if(na!=nb)
                    puts("Not sure yet.");
                else if(R[a]!=R[b])
                    puts("In different gangs.");
                else
                    puts("In the same gang.");
            }
            else
                Union(a, b);
        }
    }
}
