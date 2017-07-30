#include "cstdio"
#include "algorithm"
using namespace std;

int a[100];
bool cmp(int a,int b){ return  a>b; }
int main(){
    int n,k; scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1, a+1+n, cmp);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%d ",i);
            for(int t=1;t<i;t++)
                printf("%d ",a[t]);
            printf("%d\n",a[j]);
            k--;
            if(k==0) return 0;
        }
    }
    return 0;
}