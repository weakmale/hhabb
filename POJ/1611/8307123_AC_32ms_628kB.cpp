#include "cstdio"
using namespace std;
int F[40000];
int num[40000];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
void Union(int nx,int ny){
    int x=Found(nx),y=Found(ny);
    if(x!=y) F[y]=x,num[x]+=num[y];
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        for(int i=0;i<=n;i++) F[i]=i,num[i]=1;
        while(m--){
            int x; scanf("%d",&x);
            if(x==0) continue;
            x--;
            int a; scanf("%d",&a);
            while(x--){
                int b; scanf("%d",&b);
                Union(a,b);a=b;
            }
            
        }
        printf("%d\n",num[Found(0)]);
    }
    return 0;
}