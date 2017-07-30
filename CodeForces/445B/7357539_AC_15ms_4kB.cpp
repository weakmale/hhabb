#include "cstdio"
#include "cmath"
#include "iostream"
#include "algorithm"
using namespace std;
int  a[55];
int F[55];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]);}
void Union(int x,int y){
    int nx = Found(x);
    int ny = Found(y);
    if(nx!=ny){
        a[nx]+=a[ny];
        F[ny]=nx;
    }
}
int main(){
    int n,m; scanf("%d %d",&n,&m);
    long long ans=1;
    for(int i=1;i<=n;i++) F[i]=i,a[i]=1;
    for(int i=1;i<=m;i++){
        int a,b; scanf("%d %d",&a,&b);
        Union(a, b);
    }
    long long t=1;
    for(int i=1;i<=n;i++){
        if(F[i]==i){
            ans=ans*(t<<(a[i]-1));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
