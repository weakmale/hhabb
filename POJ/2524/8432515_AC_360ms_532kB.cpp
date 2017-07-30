#include "cstdio"
using namespace std;
int F[50010];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
void Union(int x,int y){
    int nx = Found(x),ny = Found(y);
    if(nx!=ny) F[ny]=nx;
}
int main(){
    int n,m,kcase = 1;
    while (scanf("%d %d",&n,&m),n||m) {
        for(int i=1;i<=n;i++) F[i]=i;
        while(m--){
            int a,b; scanf("%d %d",&a,&b);
            Union(a, b);
        }
        int num=0;
        for(int i=1;i<=n;i++) if(Found(i)==i) num++;
        printf("Case %d: %d\n",kcase++,num);
    }
    return 0;
}
