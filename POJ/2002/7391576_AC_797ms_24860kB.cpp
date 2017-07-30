#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
const int MAXX=2500;
int x[1010];
int y[1010];
bool vis[MAXX<<1][MAXX<<1];
int main(){
    int n;
    while(scanf("%d",&n),n){
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x[i],&y[i]);
            vis[x[i]+MAXX][y[i]+MAXX]=true;
        }
        int sum=0;
        for(int i=2;i<=n;i++)
        {
            int x1=x[i];
            int y1=y[i];
            for(int j=1;j<i;j++)
            {
                int x2,x3,x4,y2,y3,y4 ;
                x2=x[j] ;
                y2=y[j] ;
                x3=x1+(y1-y2);
                y3=y1-(x1-x2);
                x4=x2+(y1-y2);
                y4=y2-(x1-x2);
                if(vis[x3+MAXX][y3+MAXX]&&vis[x4+MAXX][y4+MAXX])
                    sum++ ;
                x3=x1-(y1-y2);
                y3=y1+(x1-x2);
                x4=x2-(y1-y2);
                y4=y2+(x1-x2);
                if(vis[x3+MAXX][y3+MAXX]&&vis[x4+MAXX][y4+MAXX])
                    sum++;
            }
        }
        printf("%d\n",sum>>2);
    }
    return 0;
}