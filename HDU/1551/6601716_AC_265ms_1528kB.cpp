#include<cstdio>
const int MAXN=10011;
int n,k;
double a[MAXN];
bool judge(double m){
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(int)(a[i]/m);
		if(cnt>=k) return true;
	}
	return cnt>=k;
}
int main()
{
	while(~scanf("%d %d",&n,&k),k||n){
		for(int i=0;i<n;i++)
			scanf("%lf",&a[i]);
		double l=0,r=100000;
		int size=100;
		double ans;
		while(size--){
			double mid=(l+r)/2;
			if(judge(mid)){
				ans=mid;
				l=mid;
			}
			else{
				r=mid;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}