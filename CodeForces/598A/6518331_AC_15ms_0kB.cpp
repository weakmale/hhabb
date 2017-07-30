#include<cstdio>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		long long n;
		long long i=1;
		long long k=0;
		scanf("%lld",&n);
		while(i<=n){
			i*=2;
		}
		printf("%lld\n",(n+1)*n/2-i*2+2);
	}
	return 0;
}