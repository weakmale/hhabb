#include "cstdio"
using namespace std;
typedef long long LL;
LL fei[1000];
LL a[1000];
int main(){
    LL s;int k; scanf("%lld %d",&s,&k);
    fei[1]=1; fei[2]=1;
    int i=1;
    for(i=3;fei[i-1]<=1e9+1;i++){
        if(i-k>=1)
            fei[i]=2*fei[i-1]-fei[i-k-1];
        else
            fei[i]=2*fei[i-1];
    }
    int t=0;
    for(int j=i-1;s;j--){
        if(s>=fei[j]) {
            s=s-fei[j];
            a[++t]=fei[j];
            //printf("%lld %lld %lld %d\n",s,fei[j],a[t],j);
        }
    }
    int kk=t;
    if(t==1) kk++;
    printf("%d\n",kk);
    for(int j=1;j<=t;j++) printf("%lld ",a[j]);
    if(t==1) puts("0");
    return 0;
}