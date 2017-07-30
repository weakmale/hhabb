#include "cstdio"
#include "algorithm"
using namespace std;
int a[10100];
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d",&n);
        int summ=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                int c=a[i]+a[j];
                long k = lower_bound (a+1, a+n+1, c) - a;
                summ+=(k-j-1);
            }
        }
        printf("Case %d: %d\n", ++caseno, summ );
    }
    return 0;
}