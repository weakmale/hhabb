#include "cstdio"
#include "queue"
#include "algorithm"
using namespace std;
int main(){
    int n;long long m; scanf("%d %lld",&n,&m);
    long long sum=0;
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a); sum+=a;
    }
    long long ans = sum/m;
    if(sum%m) ans++;
    printf("%lld\n",ans);
    return 0;
}