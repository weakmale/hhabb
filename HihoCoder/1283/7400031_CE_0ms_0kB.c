#include "cstdio"
using namespace std;
int a[1010];
bool b[1010];
int c[1010];
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int t=0;
    for(int i=1;i<=n;i++){
        b[a[i]]=true;
        t=0; bool K=false;
        for(int j=1;j<=n;j++){
            if(!b[j]){
                c[++t]=j;
            }
        }
        for(int j=1,k=i+1;j<=t;j++,k++)
            if(c[j]!=a[k])
                K=true;
        if(!K) break;
    }
    int K=true;
    for(int i=1;i<=n;i++){
        if(b[a[i]]){
            if(K)
                printf("%d",a[i]),K=false;
            else
                printf(" %d",a[i]);
        }
    }
    puts("");
    return 0;
}