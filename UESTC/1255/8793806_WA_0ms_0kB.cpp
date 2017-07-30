#include "cstdio"
#include "queue"
#include "algorithm"
using namespace std;
int main(){
    int n,m; scanf("%d %d",&n,&m);
    long long sum=0;
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a); sum+=a;
    }
    int ans = sum/m;
    if(sum%m) ans++;
    printf("%d\n",ans);
    return 0;
}