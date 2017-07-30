#include "cstdio"
#include "cstring"
int sum[32010];
int star[32010];
int lowbet(int x){
    return x&-x;
}
int Sum(int x){
    int m=0;
    while(x){
        m+=sum[x];
        x-=lowbet(x);
    }
    return m;
}
void add(int x){
    while(x<=32005){
        sum[x]++;
        x+=lowbet(x);
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(star,0,sizeof(star));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            int x,y; scanf("%d %d",&x,&y);
            star[Sum(x+1)]++;
            add(x+1);
        }
        for(int i=0;i<n;i++)
            printf("%d\n",star[i]);
    }
    return 0;
}