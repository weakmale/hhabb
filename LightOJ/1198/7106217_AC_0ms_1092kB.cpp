#include "cstdio"
#include "algorithm"
using namespace std;
int a[55];
int b[55];
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        int sum = 0;
        printf("Case %d: ",kcase++);
        sort(a+1,a+1+n); sort(b+1,b+1+n);
        int al=1;int bl=1; int an=n; int bn=n;
        while(al<=an&&bl<=bn){
            if(a[an]>b[bn]){
                sum+=2; an--; bn--;
            }
            else if(a[al]>b[bl]){
                sum+=2; al++; bl++;
            }
            else if(a[an]==b[bl]){
                sum+=1; an--; bl++;
            }
            else{
                al++; bn--;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}