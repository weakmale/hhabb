#include<cstdio>
#include<algorithm>
using namespace std;
long long asd(long long x){
	if(x>0)
		return x;
	else
		return -x;
}
long long a[222222]={0};
int main(){
	long long n;
	scanf("%lld",&n);
	
	long long t;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&t);
		a[t]=i;
	}
	long long sum=0;
	for(long long i=1;i<n;i++){
		sum+=asd(a[i+1]-a[i]);
	}
	printf("%lld\n",sum);
	return 0;
}