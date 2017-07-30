#include "cstdio"
using namespace std;
typedef long long LL;
int F[200010];
LL R[200010];
int Found(int x){
    if(F[x]==x) return x;
    int t=F[x];
    F[x]=Found(t);
    R[x]=R[t]+R[x];
    return F[x];
}
int main(){
    int n,m,ans=0; scanf("%d %d", &n,&m);
    for(int i=1;i<=n;i++) F[i]=i,R[i]=0;
    while(m--){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        a--;
        int na=Found(a),nb=Found(b);
        if(na!=nb){
            F[nb]=na;
            R[nb]=R[a]-R[b]+c;
        }
        else if(R[b]-R[a]!=c) ans++;
    }
    printf("%d\n",ans);
    return 0;
}