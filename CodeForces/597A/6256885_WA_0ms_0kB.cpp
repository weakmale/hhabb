#include<cstdio>
int main(){
    long long k,a,b;
    while(scanf("%lld%lld%lld",&k,&a,&b)!=EOF){
        long long t=0;
        if(a<0){
            a=-a;
            t+=a/k;
            t+=b/k;
            t+=1;
        }
        else{
            if(a%k==0) t++;
            if(b%k==0) t++;
            a=b-a;
            t+=a/k;
        }
        printf("%lld\n",t);
    }
    return 0;
}