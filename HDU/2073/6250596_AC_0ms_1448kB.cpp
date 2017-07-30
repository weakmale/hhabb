#include<cstdio>
#include<cmath> 
int main()
{
	int m; scanf("%d",&m);
	while(m--){
		double x1,y1,x2,y2,cnt=0; 
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		if( (x1+y1) > (x2+y2)){
			double t;
			t=x1; x1=x2; x2=t;
			t=y1; y1=y2; y2=t;
		} 
		if( (x1+y1) == (x2+y2) ){
			cnt=fabs(x1-x2)*sqrt(2);
		}
		else{
			for(int i=x1+y1+1;i<=x2+y2;i++){ 
				cnt+=sqrt((i*i )+((i-1)*(i-1))); 
			}
			for(int i=x1+y1+1;i<x2+y2;i++){
				cnt=cnt+(i*sqrt(2));
			}
			cnt=cnt + (y1*sqrt(2)) + (x2*sqrt(2));
		}
		printf("%.3lf\n",cnt);
	}
	return 0;
 } 