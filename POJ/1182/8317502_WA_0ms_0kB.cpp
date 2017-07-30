#include "cstdio"
using namespace std;
int F[150010];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
void Union(int x,int y){
    int nx=Found(x),ny=Found(y);
    if(nx!=ny) F[ny]=nx;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int ans=0;
    for(int i=0;i<=n*3;i++) F[i]=i;
    while(k--){
        int a,b,c; scanf("%d %d %d",&c,&a,&b);
        if(a<0||a>=n||b<0||b>=n)
        {
            ans++;
            continue;
        }
        if(c==1){
            if(Found(a)==Found(b+n)||Found(a)==Found(b+2*n)) ans++;
            else
                Union(a, b),Union(a+n, b+n),Union(a+2*n, b+2*n);
        }
        else{
            if(Found(a)==Found(b)||Found(a)==Found(b+2*n)) ans++;
            else
                Union(a, b+n),Union(a+n,b+n+n),Union(a+n+n, b);
        }
    }
    printf("%d\n",ans);
    return 0;
}