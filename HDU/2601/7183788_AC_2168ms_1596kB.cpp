#include <iostream>
//这里的cmath等价于C的math.h
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int T; scanf("%d",&T);
    while(T--){
        double n;
        scanf("%lf",&n);
        n++;
    //   printf("%lf\n",sqrt(n));
        int t=sqrt(n);
    //  printf("%d~~~\n",t);
        int sum=0;
        long long x=n;
    //  printf("%lld\n",x);
        for(int i=2;i<=t;i++){
            if(x%(long long)i==0)
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
