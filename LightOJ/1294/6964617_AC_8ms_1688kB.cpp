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
        LL n,m;
        scanf("%lld %lld",&n, &m);
        printf("Case %d: %lld\n",t++,(n/(2*m))*(m*m));
	}
	return 0;
}
