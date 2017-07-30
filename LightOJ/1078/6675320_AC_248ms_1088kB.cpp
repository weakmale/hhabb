#include<cstdio>
int main(){
	int T;int t=1;
	scanf("%d",&T);
	while(T--){
		long long n,i;	
		scanf("%lld %lld",&n,&i);
		long long sum=i;
		int cnt=1;
		while(sum%n!=0){//应该是同余定理一方面的（a*b）%c=（a%c）*（b%c）% c 
			sum%=n;
			cnt++;
			sum=sum*10+i; 
		}
		printf("Case %d: %d\n",t++,cnt);
	}
	return 0;
} 