#include "cstdio"
#include "algorithm"
using namespace std;
int Map[15][15];
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                Map[i][j]=1e7;
            }
            Map[i][i]=0;
        }
        int m=0;
        for(int i=1;i<=n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            Map[a][b]=Map[b][a]=min(Map[a][b],c);
            m=max(max(a,m),b);
        }
        n=m+1;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    Map[i][j]=min(Map[i][j],Map[i][k]+Map[k][j]);
                }
            }
        }
        int ans=1e7; int t=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++)
                if(Map[i][j]!=1e7)
                    sum+=Map[i][j];
            if(ans>sum){
                t=i; ans=sum;
            }
        }
        printf("%d %d\n",t,ans);
    }
    return 0;
}