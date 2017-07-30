#include<cstdio>
int main(){
    int n; scanf("%d",&n);
    while(n--){
        long long t,y=1; scanf("%lld",&t);
        long long sum;
        sum=((1+t)*t)/2;
        while(y<=t){
            sum=sum-(2*y);
            y=y*2;
        }
        printf("%lld\n",sum);
    }
    return 0;
}