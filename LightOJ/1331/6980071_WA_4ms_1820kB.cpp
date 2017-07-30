#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
int main(){
	int T; scanf("%d",&T); int t=1;
	while(T--){
        double r1,r2,r3;
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        double jiao1=r1/(r1+r2+r3)*pi*2;
        double jiao2=r2/(r1+r2+r3)*pi*2;
        double jiao3=r2/(r1+r2+r3)*pi*2;
        double s1=r1*r1/tan(jiao1/2)-r1*r1*pi*(pi-jiao1)/(2*pi);
        double s2=r2*r2/tan(jiao2/2)-r2*r2*pi*(pi-jiao2)/(2*pi);
        double s3=r3*r3/tan(jiao3/2)-r3*r3*pi*(pi-jiao3)/(2*pi);
        printf("Case %d: %.9lf\n",t++,s1+s2+s3);
	}
	return 0;
}