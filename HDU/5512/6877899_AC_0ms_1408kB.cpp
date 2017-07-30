#include "cstdio"
int  GCD(int a,int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}
int n;
int T;
int t;
int a,b;
int main(){
    scanf("%d",&T); t=1;
    while(T--){
        scanf("%d %d %d",&n,&a,&b);
        int g=GCD(a,b);
        int ans=n/g-2;
        if(ans%2==1)
            printf("Case #%d: Yuwgna\n",t++);
        else
            printf("Case #%d: Iaka\n",t++);
    }
    return 0;
}