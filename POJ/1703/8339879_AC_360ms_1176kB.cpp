#include "cstdio"
using namespace std;
int F[200010];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
void Union(int x,int y){
    int nx=Found(x);int ny=Found(y);
    if(nx!=ny) F[ny]=nx;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d %d" ,&n,&m);
        for(int i=1;i<=n*2;i++) F[i]=i;
        while(m--){
            char s[2];int a,b;
            scanf("%s %d %d",s,&a,&b);
            if(s[0]=='A'){
                if(Found(a)==Found(b))
                    puts("In the same gang.");
                else if(Found(a+n)==Found(b))
                    puts("In different gangs.");
                else
                    puts("Not sure yet.");
            }
            else
                Union(a, b+n),Union(a+n, b);
        }
    }
}
