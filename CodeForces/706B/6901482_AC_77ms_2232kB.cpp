#include "cstdio"
#include "algorithm"
using namespace std;
int main(){
    int n;
    int a[100010];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int vi; scanf("%d",&vi);
        int k=upper_bound(a,a+n,vi)-a;
        printf("%d\n",k);
    }
    return 0;
}