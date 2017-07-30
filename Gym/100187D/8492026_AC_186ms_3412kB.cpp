#include<cstdio>
using namespace std;
typedef long long LL;
const LL mod = 1e9+9;
LL jie[200010];
LL Qpow(LL a,int m){
	LL ans=1,base=a;
	while(m){
		if(m&1){
			ans=(ans*base)%mod;
		}
		base = (base*base)%mod;
		m>>=1;
	}
	return ans;
}
LL C(LL n,LL m){
	return jie[n] * Qpow( ( jie[n-m]*jie[m] ) % mod , mod-2 ) % mod;
}
int main(){
	int n; scanf("%d",&n);
	jie[0]=1;
	for(int i=1;i<=n;i++)
		jie[i]=jie[i-1]*i%mod;
	LL num = Qpow(2,mod-2);
	LL summ=0;
	LL sum = 0;
	for(int i=1;i<n;i++){
		if(i+i<=n)
			summ = (summ + C(n,i)*C(n-i,i));
		sum = (sum+C(n,i) * ( Qpow(2,n-i)-1) % mod )%mod;
	}
	sum = (sum)%mod;
	printf("%lld\n",sum);
	return 0;
}