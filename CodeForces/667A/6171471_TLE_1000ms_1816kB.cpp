#include<cstdio>
#define PI 3.141592636535
int main()
{
	double d,h,v1,e;
	while(scanf("%lf%lf%lf%lf",&d,&h,&v1,&e))
	{
		double v2=d/2*d/2*PI*e;
		double v=d/2*d/2*PI*h;
		if(v2>=v1)
			printf("NO\n");
		else
			printf("YES\n%lf\n",v/(v1-v2));
	}
	return 0;
 } 