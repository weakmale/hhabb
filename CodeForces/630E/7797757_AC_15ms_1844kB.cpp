#include "cstdio"
using namespace std;
typedef long long LL;
int main(){
    LL x1,x2,y1,y2;
    scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
    LL sum1=0;
    LL sum2=0;
    if((x1%2+2)%2!=(y1%2+2)%2){
        if((x2%2+2)%2!=(y1%2+2)%2){
            sum1= (x2-x1)/2;
            sum2=sum1+1;
            sum1=sum2;
            sum2=sum1-1;
            y1++,y2++;
        }
        else{
            sum1=(x2-x1+1)/2;
            sum2=sum1;
        }
    }
    else{
        if((x2%2+2)%2!=(y1%2+2)%2){
            sum1= (x2-x1+1)/2;
            sum2=sum1;
        }
        else{
            sum1=(x2-x1)/2+1;
            sum2=sum1-1;
        }
    }
    printf("%lld\n",(y2-y1+1)/2*(sum1+sum2)+((y2-y1+1)%2)*sum1);
    return 0;
}
