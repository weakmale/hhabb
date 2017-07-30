#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	double j;
	double f;
	double cha;
}a[1011];
bool cmp(node a,node b){
	return a.cha>b.cha;
}
double m;
int n;
int main(){
	while(~scanf("%lf %d",&m,&n)){
		if(m==-1&&n==-1)
			break;
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&a[i].j,&a[i].f);
			a[i].cha=a[i].j/a[i].f;
		}
		sort(a,a+n,cmp);
		double sum=0;
		int i=0;
		while(m>0){
			if(m>a[i].f){
				sum+=a[i].j;
				m-=a[i].f;
				i++;
			}
			else{
				sum+=a[i].cha*m;
				m=0;
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}