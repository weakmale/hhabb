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
        double s1=r1*r1/tan(pi/3)-r1*r1*pi/6;
        double s2=r2*r2/tan(pi/3)-r2*r2*pi/6;
        double s3=r3*r3/tan(pi/3)-r3*r3*pi/6;
        printf("Case %d: %.9lf\n",t++,s1+s2+s3);
	}
	return 0;
}
