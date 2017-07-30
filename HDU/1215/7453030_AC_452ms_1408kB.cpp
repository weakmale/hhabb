#include "cstdio"
#include "cmath"
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        int k=sqrt(n);
        int sum=0;
        for(int i=1;i<=k;i++){
            if(n%i==0){
                sum=sum+i;
                if(n/i!=i)
                    sum+=(n/i);
            }
            
        }
        printf("%d\n",sum-n);

    }
    return 0;
}