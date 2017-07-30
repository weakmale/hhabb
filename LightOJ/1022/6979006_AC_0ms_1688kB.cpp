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
        double r; scanf("%lf",&r);
        double s1=r*r*4;
        double s2=r*r*pi;
        printf("Case %d: %.2lf\n",t++,s1-s2);
	}

	return 0;
}
