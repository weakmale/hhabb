#include "cstdio"
#include "algorithm"
using namespace std;
const int MAXX=10000+10;
int map[MAXX][MAXX];
int xa[MAXX];
int xb[MAXX];
int ya[MAXX];
int yb[MAXX];
int xc[MAXX];
int yc[MAXX];
int n,m;
int q;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&m,&q);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        for(int i=1;i<=n;i++) xa[i]=i,xb[i]=i,xc[i]=0;
        for(int i=1;i<=m;i++) ya[i]=i,yb[i]=i,yc[i]=0;
        int a,x,y;
        for(int i=1;i<=q;++i){
            scanf("%d %d %d",&a,&x,&y);
            if(a==1){
                swap(xa[x], xa[y]);
            }
            if(a==2)
                swap(ya[x], ya[y]);
            if(a==3)
                xc[xa[x]]+=y;
            if(a==4)
                yc[ya[x]]+=y;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>1)
                    printf(" ");
                printf("%d",map[xa[i]][ya[j]]+xc[xa[i]]+yc[ya[j]]);
            }
            printf("\n");
        }
    }
    return 0;
}
