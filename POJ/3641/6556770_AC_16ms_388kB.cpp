#include<cstdio>
#include<cmath>
long long qpow(long long a,long long b)
{
	__int64 mod=b,ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}
int main(){
	long long q,a;
	while(~scanf("%lld%lld",&q,&a)){
		if(q==0&&a==0)
			break;
		bool k=false;
		for(long long i=2;i*i<q;i++){
			if(q%i==0){
				k=true;break;
			}
		}
		if(k){
			if(qpow(a,q)==a)
				printf("yes\n");
			else
				printf("no\n");
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}