#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	double p;
	double h;
}a[1010];
bool cmp(node a,node b){
	return a.p<b.p;
}
int main(){
	int C; scanf("%d",&C);
	while(C--){
		double sum=0;
		double n;
		int m;
		scanf("%lf %d",&n,&m);
		for(int i=0;i<m;i++)
			scanf("%lf%lf",&a[i].p,&a[i].h);
		sort(a,a+m,cmp);
		int i=0;
		while(n>a[i].p){
			while(a[i].h){
				sum++;n-=a[i].p;a[i].h--;
				if(n<a[i].p)
					break;
			}
			if(n<a[i].p&&a[i].h)
					break;
			i++;
		}
		sum+=n/a[i].p;
		printf("%.2lf\n",sum);	
	}
	return 0;
}