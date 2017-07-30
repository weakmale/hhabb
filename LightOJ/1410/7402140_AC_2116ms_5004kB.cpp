#include "cstdio"
#include "map"
#include "algorithm"
using namespace std;
int x[1000];
int y[1000];
int len[1000*1000];
int main(){
    int T; scanf("%d",&T); int kacse=1;
    while(T--){
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",x+i,y+i);
        int sum=0;
        int t=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                len[t++]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                
            }
        }
        sort(len,len+t);
        sum=int(unique(len, len+t)-len);
        printf("Case %d: %d\n",kacse++,++sum);
    }
    return 0;
}
