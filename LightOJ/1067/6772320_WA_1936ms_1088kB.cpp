#include<cstdio>
const int MAXX=1000003;
int main(){
	int T;scanf("%d",&T);
	long long n,k; int t=1;
	while(T--){
		scanf("%lld %lld",&n,&k);
		
//		if(k==0){
//			printf("Case %d: 0\n",t++);
//			continue;
//		}
		if(2*k>n)
			k=n-k;
		long long sum=1;
		long long K=1;
		long long N=1;
		for(long long i=1;i<=k;i++){
			K=K*i%MAXX;
			N=N*n%MAXX;
			sum = N / K % MAXX;
			n--;
		}
		printf("Case %d: %lld\n",t++,sum);
	}
	return 0;
}