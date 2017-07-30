#include "cstdio"
#include "vector"
#include "map"
#include "cstring"
#include "algorithm"
using namespace std;
map<long long,bool>Map;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        Map.clear();
        int n;
        long long m; scanf("%d %lld",&n,&m);
        long long t=1;
        long long maxx = m;
        for(int i=1;i<=n;i++) t*=10;
        while(!Map[m]){
            Map[m]=true;
            maxx = max(maxx,m);
            m=m*m;
            while(m>=t){
                m/=10;
            }
        }
        printf("%lld\n",maxx);
    }
    return 0;
}