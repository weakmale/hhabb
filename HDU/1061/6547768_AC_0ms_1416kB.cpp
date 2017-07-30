#include<cstdio>
long long solve(long long n){
	long long t=1;
	long long b=n%10;
	while(n){
		if(n%2){
			t=t*b;
			t=t%10;
		}
		b*=b;
		b=b%10;
		n/=2;
	}
	return t;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	} 
}