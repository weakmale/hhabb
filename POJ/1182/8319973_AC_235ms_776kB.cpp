#include "cstdio"
using namespace std;
int F[50010];
int R[50010];
int Found(int x){
    if(F[x]==x) return x;
    int t=F[x];
    F[x]=Found(F[x]);
    R[x]=(R[t]+R[x])%3;
    return F[x];
}
void Union(int x,int y,int num){
    int nx=Found(x);int ny=Found(y);
    F[ny]=nx;
    R[ny]=(R[x]-R[y]-num+3)%3;
}
int main(){
    int n,k; scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) F[i]=i,R[i]=0;
    int ans=0;
    while(k--){
        int t,a,b; scanf("%d %d %d",&t,&a,&b);
        if(a>n||b>n){ ans++;continue; }
        if(a==b&&t==2){ ans++;continue; }
        int x=Found(a),y=Found(b);
        if(x==y){
            if( (R[a]-R[b]+3)%3 != t-1)
                ans++;
        }
        else
            Union(a, b, t-1);
    }
    printf("%d\n",ans);
    return 0;
}