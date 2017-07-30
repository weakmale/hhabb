#include<cstdio>
#include<cmath>
#define PI 3.141592636535
int n,f;
double  num[100010];
bool judge(double mid){
    int sum=0;
    for(int i=0;i<n;++i){
        sum+=(int)(num[i]/mid);
    }

    return sum>=f;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&f);f++;
		double v=0;
		for(int i=0;i<n;++i){
            scanf("%lf",&num[i]);
            num[i]=num[i]*num[i]*PI;
            v+=num[i];

        }
		double l=0,r=v;
		int size=100;
		while(size--){
			double mid=(l+r)/2;
			if(judge(mid)){
				l=mid;
			}
			else {
				r=mid;
			}
		}
		printf("%.4lf\n",l);
	}
	return 0;
} 