#include "cstdio"
#include "algorithm"
using namespace std;
int F[200010];
int R[200010];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        int K= -1e8;
        int maxx; scanf("%d",&maxx);n--;
        while(n--){
            int a; scanf("%d",&a);
            K = max(maxx - a,K);
            maxx = max(maxx,a);
        }
        printf("%d\n",K);
    }
    return 0;
}