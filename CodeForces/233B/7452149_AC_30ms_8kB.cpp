#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int main(){
    long long  n; scanf("%lld",&n);
    for(int i=1;i<=162;i++){
        double diti=sqrt((double)(i*i+4*n));
        long long x1=diti;
        if( (double)(x1)==diti ){
            x1=x1-(long long)(i);
            if(x1%2==0){
                x1=x1/2;
                long long sum=0;
                long long ans=x1;
                while(x1){
                    sum+=(x1%10);
                    x1/=10;
                }
                if(sum==i){
                    printf("%lld\n",ans);
                    return 0;
                }
            }
        }
    }
    puts("-1");
    return 0;
}