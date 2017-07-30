#include<cstdio>
#include<cmath>
double judge(double mid){
	return 8.0*pow(mid,4.0)+7.0*pow(mid,3.0)+2*pow(mid,2.0)+3.0*mid+6;
}
int main(){
	
	int t; scanf("%d",&t);
	while(t--){
		double y;
		scanf("%lf",&y);
		double m=8.0*pow(100.0,4.0)+7.0*pow(100.0,3.0)+2*pow(100.0,2.0)+306.0;
		if(y<6||y>m)
			printf("No solution!\n");
		else{
			double l=0.0,r=100.0;
			int size=50;
			while(size--){
				double mid=(l+r)/2;
				if(judge(mid)<y){
					l=mid;
				}
				else{
					r=mid;
				}
			}
			printf("%.4lf\n",l);
		}
	}
	return 0;
}