#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
int main(){
	int T; int t=1; scanf("%d",&T);
	while(T--){
		LL x;  LL p=1;
		scanf("%lld",&x);LL i=1;
		for( i=1;i<=x;i++)
		{
			if(p>x)
				break;
			p*=2;
		}
		p=p-1;
		printf("%lld\n",x*(x+1)/2-2*p);
	}
	return 0;
}
