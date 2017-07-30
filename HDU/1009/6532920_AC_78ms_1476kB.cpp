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
int m;
int n;
int main(){
	while(scanf("%d %d",&m,&n)){
		if(m==-1&&n==-1)
			break;
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&a[i].j,&a[i].f);
			a[i].cha=a[i].j/a[i].f;
		}
		sort(a,a+n,cmp);
		double sum=0;
		int i=0;
		for(int i=0;i<n;i++){
			if(m>a[i].f){
				sum+=a[i].j;
				m-=a[i].f;
			}
			else{
				sum+=a[i].cha*m;
				break;
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}