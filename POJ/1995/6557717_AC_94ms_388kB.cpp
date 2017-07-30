#include<cstdio>
long long Qpow(long long a,long long n,long long mod){
	long long cnt=1;
	long long base=a%mod;
	while(n){
		if(n&1){
			cnt=(cnt*base)%mod;
		}
		base=(base*base)%mod;
		n>>=1;
	}
	return cnt;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long c;
		int t;
		long long sum=0;
		scanf("%lld%d",&c,&t);
		for(int i=0;i<t;i++){
			long long a,n;
			scanf("%lld%lld",&a,&n);
			sum+=Qpow(a,n,c);
		}
		printf("%d\n",sum%c);
	}
}