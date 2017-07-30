#include<cstdio>
int main(){
    long long k,a,b;
    while(scanf("%lld%lld%lld",&k,&a,&b)!=EOF){
        long long t;
        if(a>0&&b>0){
            t=b/k+(a-1)/k;
        }
        else if(a<0&&b<0)
        {
            a=-a,b=-b;
            t=(a/k)-((b-1)/k);
        }
        else{
            a=-a;
            t=a/k+b/k+1;
        }
        printf("%lld\n",t);
    }
    return 0;
}