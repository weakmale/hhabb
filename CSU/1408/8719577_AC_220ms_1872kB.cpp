#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int K = 1e5 + 10;
LL a[K];
int main()
{
    int T;
    LL n,d;
    scanf("%d",&T);
    while(T--){
       scanf("%lld %lld",&n,&d);
       for(int i = 1; i <= n; i++)
            scanf("%lld",&a[i]);
       sort(a + 1,a + 1 + n);
       int num = 0;
       LL pl = a[1];
       for(int i = 2; i <= n ; i++){
            if(a[i] - pl < d) num++;
            else pl = a[i];
       }
       printf("%lld\n",n - num);
    }
    return 0;
}
