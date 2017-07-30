#include "cstdio"
using namespace std;
int x[1010],y[1010];
int F[1010];
bool vis[1010];
int n,k;
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
void Union(int a,int b){
    int nx=Found(a),ny=Found(b);
    if(nx!=ny)
        if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=k*k)
            F[ny]=F[nx];
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d %d",x+i,y+i),F[i]=i;
    char s[2];
    while(~scanf("%s",s)){
        if(s[0]=='O'){
            int num;scanf("%d",&num);
            for(int i=1;i<=n;i++)
                if(vis[i])
                    Union(i, num);
            vis[num]=true;
        }
        else{
            int a,b; scanf("%d %d",&a,&b);
            if(Found(a)==Found(b))
                puts("SUCCESS");
            else
                puts("FAIL");
        }
    }
    return 0;
}