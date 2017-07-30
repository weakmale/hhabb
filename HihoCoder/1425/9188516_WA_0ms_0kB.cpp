#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int a[1010];
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int sum=0;
        for(int i=0;i<n;i++){
            int ans=1; int  k=(i+1)%n; int h=a[k]-a[i]; int j=i;
            if(h==0) continue;
            k = (k+1)%n,j = (j+1)%n;
            while(a[k]-a[j]==h&&j!=i){
                k = (k+1)%n,j = (j+1)%n; ans++;
            }
            sum = max(ans,sum);
        }
        printf("%d\n",sum);
    }
    return 0;
}