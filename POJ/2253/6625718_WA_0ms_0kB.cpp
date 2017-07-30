#include<cstdio>
#include<cmath>
int main(){
	int n;
	int t=1;
	while(~scanf("%d",&n),n){
		double fdx,fdy,flx,fly,mixx=0;
		scanf("%lf%lf",&fdx,&fdy);
		scanf("%lf%lf",&flx,&fly);
		mixx=pow(pow(fdx-flx,2.0)+pow(fdy-fly,2),1/2.0);
		double x,y;
		for(int i=0;i<n-2;i++){
			scanf("%lf%lf",&x,&y);
			if(mixx>pow(pow(x-flx,2)+pow(y-fly,2),1/2.0))
				mixx=pow(pow(x-flx,2)+pow(y-fly,2),1/2.0);
		}
		printf("Scenario #%d\n",t++);
		printf("Frog Distance = %.3lf\n\n",mixx);
	}
}