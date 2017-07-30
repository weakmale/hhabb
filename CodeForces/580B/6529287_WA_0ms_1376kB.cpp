#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	long long mny;
	long long fs;
}a[100011];
bool cmp(node a,node b){
	return a.mny<b.mny;
}
long long n;
long long d;
int main(){
	
	scanf("%lld%lld",&n,&d);
	for(long long i=0;i<n;i++)
		scanf("%lld %lld",&a[i].mny,&a[i].fs); 
	sort(a,a+n,cmp);
	int t=a[0].mny;
	long long max=a[0].fs;
	for(long long i=0;i<n;i++){
		long long sum=0;
		long long j=i;
		while(a[j].mny<t+d&&j<n){
			sum+=a[j].fs;j++;
		}
		t=a[i].mny;
		if(sum>max)
			max=sum;
		if(j==n)
			break;
	}
	printf("%lld\n",max);
	return 0;
} 