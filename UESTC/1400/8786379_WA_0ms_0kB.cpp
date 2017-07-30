#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int mod = 10007;
int F[100010];
int num[100010];
int main() {
	LL N, mod;
	scanf("%lld%lld", &N, &mod);
	LL ans = N - 1;
	LL res = 1;
	LL res2 = 1;
	for (LL i = 2*(N - 2); i >= 1; i--) {
		res = res*i%mod;
	}
	for (LL i = N - 2; i >= 1; i--) {
		res2 = res2*i%mod;
	}
	printf("%lld\n", res);
	printf("%lld\n", res2);
	ans = ans*(res/2 - res2)%mod;
	printf("%lld\n", ans);
	return 0;
}