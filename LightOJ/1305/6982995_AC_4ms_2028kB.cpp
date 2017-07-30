#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
double dis(double x1,double y1,double x2,double y2){
    return pow(pow(x1-x2,2.0)+pow(y1-y2,2.0),0.5);
}
int main(){
	int T; scanf("%d",&T); int t=1;
	while(T--){
        double ax,ay,bx,by,cx,cy,dx,dy;
        scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);
        dx=cx-(bx-ax);
        dy=cy-(by-ay);
        double a=dis(ax,ay,bx,by);
        double b=dis(bx,by,cx,cy);
        double c=dis(ax,ay,cx,cy);
        double jiao=(a*a+b*b-c*c)/(2*a*b);
        jiao=acos(jiao);
        printf("Case %d: %.0lf %.0lf %.0lf\n",t++,dx,dy,a*b*sin(jiao));

	}

	return 0;
}
