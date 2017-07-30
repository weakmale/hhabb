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
	long long a,b;
	while(~scanf("%lld %lld",&a,&b)){
		if(a==0&&b==0)
			break;
		printf("%lld\n",Qpow(a,b,1000));		
	}
	return 0;
}