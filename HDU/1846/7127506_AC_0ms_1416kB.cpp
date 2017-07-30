#include "cstdio"
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d %d",&n,&m);
        if(n%(m+1))
            printf("first\n");
        else
            printf("second\n");
    }
    return 0;
}