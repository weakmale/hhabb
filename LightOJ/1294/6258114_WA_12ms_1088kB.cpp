#include<cstdio>
int main(){
    int t,k=1; scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("Case %d: %d\n",k++,m*n/2);
    }
    return 0;
}
