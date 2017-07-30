#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL a[100010];
int b[100010];
int F[100010];
LL sum[100010];
int n;
bool vis[100010];
void init(int n){
    for(int i=0;i<=n;i++) F[i]=i;
}
int Found(int x)
{
    if(x==F[x]) return x;
    return F[x]=Found(F[x]);
}
void Union(int x,int y){
    if(y>n||y<0) return;
    if(!vis[y]) return;
    int nx=Found(x);
    int ny=Found(y);
    if(nx!=ny){
        F[ny]=nx;
        a[nx]+=a[ny];
        a[ny]=0;
    }
}
int main(){
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    LL maxx=0;
    for(int i=n;i>=1;i--){
        sum[i]=maxx; vis[b[i]]=true;
        Union(b[i],b[i]-1);
        Union(b[i],b[i]+1);
        maxx=max(maxx,a[b[i]]);
    }
    for(int i=1;i<=n;i++)
        cout<<sum[i]<<endl;
    return 0;
}