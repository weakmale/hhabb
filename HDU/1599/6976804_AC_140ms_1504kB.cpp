#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int Map1[101][101];
int Map2[101][101];
int ans;
void Floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            Map2[i][j]=Map1[i][j];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&j!=k&&i!=k){
                    ans=min(Map1[i][j]+Map2[j][k]+Map2[k][i],ans);
                   // printf("%d-%d-%d-%d--%d\n",i,j,k,i,ans);
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                Map1[i][j]=min(Map1[i][j],Map1[i][k]+Map1[k][j]);
    }
}
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                if(i==j)
                    Map1[i][j]=0;
                else
                    Map1[i][j]=10000;
            }
        }
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(Map1[a][b]>c)
                Map1[a][b]=Map1[b][a]=c;
        }
        ans=10000;
        Floyd();
        if(ans==10000)
            printf("It's impossible.\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
