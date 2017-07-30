#include<cstdio>
long long  E(long long mid){
	long long n=1;
	for(int i=0;i<mid;i++)
		n*=10;
	return n; 
}
int main(){
	int T;scanf("%d",&T);int t=1;
	while(T--){
		long long n;
		long long i;
		long long cnt=0;
		scanf("%lld %lld",&n,&i);
		long long sum=1111111111111111111*i;
		long long num=n;
		while(num){
			cnt++;
			num/=10;
		}
		long long m=E(cnt);
		while(sum%m%n!=0){
			cnt++;
			m*=10;
		}
		printf("Case %d: %lld\n",t++,cnt);
	}
	return 0;
}