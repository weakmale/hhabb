#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
	double x;
	double y;
	bool k;
}a[1011];
bool cmp(node a,node b){
	return a.y>b.y;
}
bool cmp1(node a,node b){
	return a.x<b.x;
}
int main(){
	int n;
	double d;
	int T=0;
	while(scanf("%d %lf",&n,&d)){
		if(n==0&&d==0)
			break ;
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&a[i].x,&a[i].y);
			a[i].k=false;
		}
		sort(a,a+n,cmp);
		if(a[0].y>d)
			printf("Case %d: -1",++T);
		else{
			int i=0;
			int cnt=0;
			while((a[i].y==d||a[i].y==-d)&&i<n){
				double r=a[i].x;
				for(int j=i;j<n;j++){
					if(pow(a[j].x-r,2)+pow(a[j].y,2)<=d*d){
						a[j].k=true;
					}
				
				}
				cnt++;
				i++;
			}
			sort(a,a+n,cmp1);
			for(int l=0;l<n;l++){
				if(a[l].k)
					continue ;
				a[l].x=-a[l].x;
				double r=a[l].x-sqrt(d*d-pow(a[l].y,2));
				r=-r;
				cnt++;
				for(int j=l;j<n;j++){
					if(pow(a[j].x-r,2)+pow(a[j].y,2)<=d*d){
						a[j].k=true;	
					}
					
				}
			}
			printf("Case %d: %d\n",++T,cnt);
		}
	}
	return 0;
}
