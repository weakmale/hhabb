#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
int main(){
	int T,t=1; scanf("%d",&T);
	while(T--){
		double ab,ac,bc,x;
		scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&x);
		x=x/(x+1);
		double ad=sqrt(ab*ab*x);
		printf("Case %d: %.8lf\n",t++,ad);
	}
	return 0;
}
