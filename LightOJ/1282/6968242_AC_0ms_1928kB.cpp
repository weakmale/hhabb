#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
LL Qpow(int n,int m){
	LL r=1; LL base=n;
	while(m){
		if(m&1){
			r=(r*base)%1000;
		}
		base=base*base%1000;
		m>>=1;
	}
	return r;
}
int main(){
	int T; scanf("%d",&T); int t=1;
	while(T--){
		LL n; LL k;
		scanf("%lld %lld",&n,&k);
		printf("Case %d: ",t++);
		double lp=log10(n);
		lp=lp*(double)k;
		LL kp=(int)lp;
		lp=lp-kp;
		int m = pow( 10.0, lp+2.0);
		printf("%03d ",m);
		LL x=Qpow(n,k);
		printf("%03d\n",x);
	}
	return 0;
}
