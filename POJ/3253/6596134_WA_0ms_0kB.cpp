#include<cstdio>
#include<algorithm>
using namespace std;
long long a[20111];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		long long sum=0,l=0;
		l=a[0];
		for(int i=1;i<n;i++){
			l+=a[i];
			sum+=l;
		}
		printf("%lld",sum);
	}
	return 0;
}