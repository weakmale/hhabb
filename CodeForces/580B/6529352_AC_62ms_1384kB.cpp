#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	long long mny;
	long long fs;
}a[100111];
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
	long long max=0;
	long long sum=0;
	long long l=0;
	for(long long i=0; i<n; i++) {
        sum+=a[i].fs;
        while(a[i].mny>=a[l].mny+d) {
             sum-=a[l].fs;
            l++;
        }
            if(max<sum)
                max=sum;
        }
	printf("%lld\n",max);
	return 0;
} 