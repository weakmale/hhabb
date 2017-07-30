#include "cstdio"
int su[1000010];
int main(){
    su[1]=0; int k=1;
    for(int i=2;i<=1000000;i++){
        if(!su[i]){
            su[i]=k;
            for(int j=i+i;j<=1000000;j+=i)
                su[j]=k;
            k++;
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF) {
        printf("%d\n",su[n]);
    }
    return 0;
    
}