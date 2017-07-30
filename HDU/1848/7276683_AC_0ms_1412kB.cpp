#include "cstdio"
#include "cstring"
int F[20]={1,1};
int num[1010];
bool hust[20];
int main(){
    for(int i=2;i<=17;i++)
        F[i]=F[i-1]+F[i-2];
    for(int i=1;i<=1000;i++){
        int j=1;
        memset(hust, false, sizeof(hust));
        while(F[j]<=i){
            hust[num[i-F[j]]]=true;
            j++;
        }
        for(j=0;j<=20;j++){
            if(!hust[j]){
                num[i]=j;
                break;
            }
        }
    }
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k),n||m||k){
        int sum=num[n]^num[m]^num[k];
        if(sum){
            printf("Fibo\n");
        }
        else
            printf("Nacci\n");
    }
    return 0;
}