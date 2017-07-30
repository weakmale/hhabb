#include "cstdio"
int F(int a,int b,int n){
    if(n==1||n==2)
        return 1;
    return (a*F(a,b,n-1)+b*F(a,b,n-2))%7;
}
int main(){
    int a,b,n;
    while(scanf("%d %d %d",&a,&b,&n),a||b||n){
        printf("%d\n",F(a,b,n%49));
    }
    return 0;
}