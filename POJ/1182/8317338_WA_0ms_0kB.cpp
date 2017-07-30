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
    while(~scanf("%d %d",&n,&k)){
        int ans=0;
        for(int i=1;i<=n;i++) F[i]=i,F[i+n]=i+n,F[n+n+i]=n+n+i;
        while(k--){
            int a,b,c; scanf("%d %d %d",&c,&a,&b);
            if(c==1){
                if(Found(a)==Found(b+n)||Found(b+n)==Found(a)) ans++;
                else
                    Union(a, b),Union(a+n, b+n),Union(a+2*n, b+2*n);
            }
            else{
                if(Found(a)==Found(b)||Found(b+n)==Found(a)) ans++;
                else
                    Union(a+n, b),Union(a+n+n,b+n),Union(a, b+n+n);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}