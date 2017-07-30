#include<cstdio>
int main(){
    int n,a;
    while(scanf("%d%d",&n,&a)!=EOF){
        int cnt=n/2;
        if(a%2==1){
            int x=1,i;
            for( i=0;i<cnt;i++){
                if(x==a) break;
                x=x+2;
            }
            printf("%d\n",i+1);
        }
        else{
            int x=2,i;
            for( i=cnt-1;i>=0;i--){
                if(x==a) break;
                x+=2;
            }
            printf("%d\n",i+1);
        }
    }
    return 0;
}