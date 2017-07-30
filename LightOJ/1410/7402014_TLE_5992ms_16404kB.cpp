#include "cstdio"
#include "map"
using namespace std;
int x[1000];
int y[1000];
map<long long,bool>Map;
int main(){
    int T; scanf("%d",&T); int kacse=1;
    while(T--){
        int n; scanf("%d",&n);
        Map.clear();
        for(int i=1;i<=n;i++)
            scanf("%d %d",x+i,y+i);
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                if(!Map[dis]){
                    sum++;Map[dis]=true;
                }
            }
        }
        printf("Case %d: %d\n",kacse++,++sum);
    }
    return 0;
}