#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	long long may;
	long long how;
	long long ge;
}a[100111];
long long n,k;
bool cmp(node a,node b){
	return a.ge>b.ge;
}
bool judge(long long m){
	long long cnt=k;
	for(long long i=1;i<=n;i++){
		
		if(m>a[i].ge){
			long long q=m-a[i].ge;
			cnt=cnt-q*a[i].how+a[i].may;
		}
		if(cnt<0)
			return false;
	}
	return cnt>=0;
}
int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i].how);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i].may);
		a[i].ge=a[i].may/a[i].how;
		a[i].may=a[i].may%a[i].how;
	}
	sort(a+1,a+n+1,cmp);
	long long l=0,r=k+a[1].ge;
	long long ans = 0;
	int size=5;
	while(l<=r){
		long long mid=(l+r)/2;
		if(judge(mid)){
			ans = mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);	
}