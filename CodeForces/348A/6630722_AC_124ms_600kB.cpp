#include<cstdio>
#include<algorithm>
using namespace std;
long long n;
long long num[100011];
bool  judge(long long mid){
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		if(num[i]>mid)return false;
		cnt+=mid-num[i];
	}
	return cnt>=mid;
}
int main(){
	long long r=0;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&num[i]);
		r+=num[i];
	}
	long long  l=0;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(judge(mid)) {
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}