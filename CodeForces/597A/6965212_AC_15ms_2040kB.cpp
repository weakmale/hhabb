#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
int main(){
	LL k; LL a; LL b;
	scanf("%lld %lld %lld",&k, &a,&b);
	if(a<0&&b<=0){
		a=-a; b=-b; LL x=a/k-b/k;
		if(b%k==0)
			printf("%lld\n",x+1);
		else
			printf("%lld\n",x);
	}
	else if(a<0&&b>0){
		a=-a;
		printf("%lld\n",a/k+b/k+1);
	}
	else{
		if(a%k==0)
			printf("%lld\n",b/k-a/k+1);
		else
			printf("%lld\n",b/k-a/k);
	}
	return 0;
}
