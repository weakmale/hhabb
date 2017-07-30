#include<cstdio>
long long Counting(long long n){
	long long  cnt=1;
	long long bast=2;
	while(n){
		if(n%2==1){
			cnt*=bast;
		}
		bast*=bast;
		n>>=1;	
	}
	return cnt;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		n--;
		printf("%lld\n",Counting(n)-1);
	}
	return 0;
	
}