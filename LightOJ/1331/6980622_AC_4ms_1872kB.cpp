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
        double a=r1+r2; double c=r2+r3; double b=r1+r3;
        double jiao1=(a*a+b*b-c*c)/(2*a*b);
        double jiao2=(a*a+c*c-b*b)/(2*a*c);
        double jiao3=(b*b+c*c-a*a)/(2*b*c);
        jiao1=acos(jiao1);
        jiao2=acos(jiao2);
        jiao3=acos(jiao3);
        double s=a*b*sin(jiao1)/2;
        double s1=r1*r1*jiao1/2;
        double s2=r2*r2*jiao2/2;
        double s3=r3*r3*jiao3/2;
        printf("Case %d: %.9lf\n",t++,s-s1-s2-s3);
	}
	return 0;
}
