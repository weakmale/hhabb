#include "cstdio"
#include "cmath"
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n),n){
        double gen=sqrt(5.0);
        double x1=(1+gen)/2;
        if(n<=20){
            printf("%.0lf\n",pow(x1, n)/gen);
            continue;
        }
        double t = n*log10(x1)-log10(gen);
        t=t-(long long)t;
        printf("%.0lf\n",pow(10,t)*1000);
    }
    return 0;
}