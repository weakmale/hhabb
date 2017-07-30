#include "cstdio"
#include "map"
#include "iostream"
using namespace std;
map<string ,int>Map;
int main(){
    int n;
    while(~scanf("%d",&n)){
        Map.clear(); string ss;
        int maxx=0;
        for(int i=1;i<=n;i++){
            cin>>ss; Map[ss]++;
            maxx = max(Map[ss],maxx);
        }
        printf("%d\n",maxx);
    }
    return 0;
}