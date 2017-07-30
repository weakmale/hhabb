#include "cstdio"
#include "iostream"
using namespace std;
int main(){
    int n,m;scanf("%d %d",&n,&m);
    double a[510];
    double sum=0;
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=1;i<=m;i++){
        int x,y;double z; scanf("%d %d %lf",&x,&y,&z);
        sum=max((a[x]+a[y])/z,sum);
    }
    printf("%.18lf\n",sum);
    return 0;
}