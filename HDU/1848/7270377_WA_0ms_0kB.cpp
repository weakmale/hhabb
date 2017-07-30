#include "cstdio"
using namespace std;
int F[200];
bool vis[1010];
int main(){
    F[0]=1; F[1]=1; F[2]=2; vis[0]=false; vis[1]=true; vis[2]=true; vis[3]=true; vis[4]=false;
    for(int i=3;i<=16;i++)
        F[i]=F[i-1]+F[i-2];
//    printf("%d",F[16]);
    for(int i=5;i<=1000;i++){
        int K=false;int j=1;
        while(F[j]<=i&&!K){
            if(vis[i-F[j]]==false){
                vis[i]=true; K=true;
            }
            j++;
        }
        if(!K)
            vis[i]=false;
    }
    int n,m,k;
    while(scanf("%d %d %d", &n,&m,&k),m||n||k){
        int sum=vis[n]+vis[m]+vis[k];
        if(sum&1){
            printf("Fibo\n");
        }
        else
            printf("Nacci\n");
    }
    return 0;
}