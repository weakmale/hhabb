#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long n,m,k;
bool judge(long long mid){
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		cnt+=min(m,mid/i);
	}
	return cnt >= k;
}
int main(){
	scanf( "%lld %lld %lld",&n,&m,&k );
	long long l=1,r=m*n,ans=0;
	while(l<=r){
		long long mid= ( l+r )/2;
		if(judge(mid)) {
			ans=mid;
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}