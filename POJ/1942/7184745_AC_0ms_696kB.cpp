#include "cstdio"
#include "cmath"
#include "iostream"
using namespace std;
int main(){
    long long n,m;
    while(~scanf("%lld %lld",&n,&m)){
        if(n==0&&m==0)
            break;
        double x=n; double y=m+n; double sum=1;
        if(n>m)
            x=m;
        long long l=x;
        while(l>0){
            sum*=(y/x);
            x-=1; y-=1;
            l--;
        }
        long long S=sum+0.5;
        printf("%lld\n",S);
    }
    return 0;
}