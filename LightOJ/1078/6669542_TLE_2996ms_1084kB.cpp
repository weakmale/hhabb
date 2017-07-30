#include<cstdio>
int main(){
	int T;scanf("%d",&T);int t=1;
	while(T--){
		long long sum;
		long long n;
		long long i;
		scanf("%lld %lld",&n,&i);
		sum=i;
		int cnt=1;
		while(sum%n!=0){
			sum=sum*10+i;
			cnt++;
		}
		printf("Case %d: %d\n",t++,cnt);
	}
	return 0;
}