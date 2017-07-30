#include "cstdio"
#include "cmath"
#include "cstring"
using namespace std;
typedef long long LL;
LL a[40];
bool v[40];
int main(){
    a[0]=0; a[1]=0; a[2]=1;
    for(int i=3;i<=35;i++){
        LL sum=a[i-1];
        for(int j=0;j<=i-2;j++){
            sum+=(j*(pow(2,i-j-2))+a[i-j-2]);
        }
        a[i]=sum+i-1;
    }
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n; scanf("%d",&n);
        memset(v,false,sizeof(v));
        int t=0;
        while(n){
            if(n&1)
                v[++t]=true;
            else
                v[++t]=false;
            n>>=1;
        }
        LL sum=0;
        for(int i=t;i>=1;i--){
            if(v[i]){
                int m=i;
                sum+=a[i-1]; int j=0;
                while(v[i]){
                    i--; j++;
                }
                for(int k=0;k<=j-2;k++){
                    sum+=(k*(pow(2,m-k-2))+a[m-k-2]);
                }
                sum+=(j-1);
            }
        }
        printf("Case %d: %lld\n",kcase++,sum);
    }
    return 0;
}
