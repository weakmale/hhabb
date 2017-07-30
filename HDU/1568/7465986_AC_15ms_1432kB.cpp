#include "cstdio"
#include "cmath"
using namespace std;
double gen=sqrt(5.0);
double x1=(1+gen)*0.5;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<=20){
            printf("%.0lf\n",pow(x1, n)/gen);
            continue;
        }
        double t = n*log10(x1)-log10(gen);
        t-=(long long)t;
        printf("%d\n",(int)(pow(10,t)*1000));
    }
    return 0;
}