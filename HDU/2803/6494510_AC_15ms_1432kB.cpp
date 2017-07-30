#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n;
	long long a[3000];
	while(scanf("%d",&n),n){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		long long sum=0;
		sum=a[n-1]*(2009-n);
		for(int i=n-1;i>=0;i--)
			sum+=a[i];
		printf("%lld\n",sum);
	}
}