#include<cstdio>
int main(){
    long long k,a,b;
    while(scanf("%lld%lld%lld",&k,&a,&b)!=EOF){
        long long i,t=0;
        for(i=a;i<=b;i++)
            if(i%k==0)
                t++;
        printf("%lld\n",t);
    }
    return 0;
}