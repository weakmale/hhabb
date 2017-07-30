#include "cstdio"
int main(){
    int n;
    while(~scanf("%d", &n)){
        int a=n/2;
        n-=a;
        printf("%d\n",a*(a-1)/2+n*(n-1)/2);
    }
}