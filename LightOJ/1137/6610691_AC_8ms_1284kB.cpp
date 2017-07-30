#include<cstdio>
#include<cmath>
int main()
{
	int T;scanf("%d",&T);
	int t=1;
	while(T--){
		double L,n,c;
		scanf("%lf%lf%lf",&L,&n,&c);
		double l1=(1+n*c)*L;
		double l=0,r=acos(-1);
		int size=100;
		while(size--){
			double mid=(l+r)/2;
			if(L*mid/sin(mid)<=l1){
				l=mid;
			}
			else {
				r=mid;
			}
		}
		printf("Case %d: %.7lf\n",t++,0.5*L/sin(l)-0.5*L/tan(l));
	}
}