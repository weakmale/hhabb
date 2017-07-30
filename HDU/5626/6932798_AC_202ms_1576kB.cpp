#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const long long inf=1e9+10;
long long seed;
int x[1000010];
int y[1000010];
inline long long rand(long long l, long long r) {
  static long long mo=1e9+7, g=78125;
  return l+((seed*=g)%=mo)%(r-l+1);
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        long long x,y,xa=-inf,ya=inf,xb=-inf,yb=inf;
        int n; scanf("%d %lld", &n, &seed);
        for (int i = 0; i < n; i++){
            x = rand(-1000000000, 1000000000),
            y = rand(-1000000000, 1000000000);
            xa=max(xa,x+y);
            ya=min(ya,x+y);
            xb=max(xb,x-y);
            yb=min(yb,x-y);
        }
        long long ans=max(xa-ya,xb-yb);
        printf("%lld\n",ans);
    }
	return 0;
}
