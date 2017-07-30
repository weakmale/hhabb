#include "cstdio"
using namespace std;
int ans[200];
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++){
            int a; scanf("%d",&a);
            ans[a]++;
        }
        int K=1;
        for(int i=1;i<=100;i++){
            while(ans[i]){
                if(K) printf("%d",i),K=0;
                else printf(" %d",i);
                ans[i]--;
            }
        }
        puts("");
    }
    return 0;
}