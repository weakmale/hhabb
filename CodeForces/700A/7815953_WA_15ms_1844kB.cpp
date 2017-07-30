#include "cstdio"
using namespace std;
int main(){
    double l,v1,v2;
    int n,k;
    scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);
    int m = n/k;
    if(n%k) m++;
    double t2 = l*(v1+v2)/((m-1)*(2*v2)+v2*(v1+v2));
    double t1 = (l-v2*t2)/v1;
    printf("%.12lf\n",t2+t1);
    return 0;
}