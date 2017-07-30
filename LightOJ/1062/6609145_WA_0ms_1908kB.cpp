#include<cstdio>
#include<cmath>
#include<iostream>
#define eps 1e-8
using namespace std;
double x,y,c;
double sinx,siny;
double L;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lf %lf %lf",&x,&y,&c);
		double l=0,r=min(x,y);
		int size=100;
		int t=1;
		while(size--){
			double mid=(l+r)/2;
			double rod1=acos(mid/x);
			double rod2=acos(mid/y);
			double d=c/tan(rod1)+c/tan(rod2);
			if(d<mid)
				l=mid+eps;
			else
				r=mid-eps;
		}
		printf("Caes %d: %.7lf\n",t++,l);
	}
	return 0;	
}