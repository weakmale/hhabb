#include "cstdio"
#include "algorithm"
using namespace std;
const int inf=1e7;
int Map[1010][1010];
int main(){
    int n,m,x;
    while(scanf("%d %d %d",&n,&m,&x)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                Map[i][j]=inf;
            Map[i][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d  %d %d",&a,&b,&c);
            Map[a][b]=min(Map[a][b],c);
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)
                    Map[i][j]=min(Map[i][j],Map[i][k]+Map[k][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(Map[i][x]!=inf&&Map[x][i]!=inf)
                ans=max(Map[i][x]+Map[x][i],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}