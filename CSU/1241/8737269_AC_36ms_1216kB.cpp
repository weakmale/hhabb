#include "cstdio"
#include "cstring"
using namespace std;
int F[10010];
int R[10010];
int num[10010];
bool vis[10010];
int Found(int x){
    if(F[x]==x) return F[x];
    int k=F[x];
    F[x]=Found(F[x]);
    R[x] = R[x]+R[k];
    return F[x];
}
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        bool K=0;  memset(vis, false, sizeof(vis));
        for(int i=1;i<=n;i++) F[i]=i,R[i]=0;
        while(m--){
            char s[2]; scanf("%s",s);
            if(s[0]=='B'){
                int a,b,c; scanf("%d %d %d",&a,&b,&c);
                int na = Found(a), nb = Found(b);
                if(na!=nb){
                    F[nb] = na;
                    R[nb] = R[a]-R[b]-c;
                    if(vis[nb]){
                        int x=num[nb]-R[nb];
                        if(!vis[na])
                            num[na]=x,vis[na]=true;
                        else
                            if(num[na]!=x)
                                K=1;
                    }
                }
                else
                    if(R[a]-R[b]!=c) K=1;
            }
            else{
                int a,b; scanf("%d %d",&a,&b);
                int na = Found(a);
                int x = b-R[a];
                if(!vis[na])
                    num[na]=x,vis[na]=true;
                else
                    if(num[na]!=x)
                        K=1;
            }
        }
        if(K) puts("RE");
        else{
            K=0;
            for(int i=1;i<=n;i++)
                if(Found(i)==i&&!vis[i])
                    K=1;
            if(K) puts("WA");
            else  puts("AC");
        }
    }
    return 0;
}