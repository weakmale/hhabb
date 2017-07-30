#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int num[500055];
bool judge(int mid){
	if(mid>(n+1)/2) return false;
	for(int i=1;i<=mid;i++){
		if(num[i]*2>num[n-mid+i])
			return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	int l=1,r=n;
	int cns=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)) {
			cns=mid;
			l=mid+1;
		}
		else {
			
			r=mid-1;
		}
	}	
	printf("%d",n-cns);
	return 0;
}