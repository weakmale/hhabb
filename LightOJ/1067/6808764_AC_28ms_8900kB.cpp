#include<cstdio>
const int MAXX=1000003;
long long num[MAXX]={1};
long long qpow( long long n , long long m, long long mod){
	long long ans=1; long long base=n;
	while(m){
		if(m&1)
			ans=(ans*base)%mod;
		base=(base*base)%mod;
		m>>=1;
	
	}
	
	return ans;
}
long long lucas(long long n,long long m,long long p){
	long long ans=1;
	while(n&&m){
		long long a=n%p;
		long long b=m%p;
		if(b>a)
			return 0;
		ans=(ans*num[a]*qpow(num[b]*num[a-b]%p,p-2,p))%p;
		
		m/=p;
		n/=p;
	}
	return ans;
}
int main(){
	for(int i = 1;i <= MAXX; ++i ){
		num[i]=(num[i-1]*i)%MAXX;
	}
	int T; scanf("%d",&T);int t=1;
	while(T--){
		long long m,n;
		scanf("%lld %lld",&m,&n);
		printf("Case %d: %lld\n",t++,lucas(m,n,1000003));
	}
	return 0;
}