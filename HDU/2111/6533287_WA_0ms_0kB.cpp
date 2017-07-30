#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int  pi;
	int  mi;
}a[111];
bool cmp(node a,node b){
	return a.pi>b.pi;
}
int l;
int n;
int main(){
	while(scanf("%d",&l),l){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&a[i].pi,&a[i].mi);
		int sum=0;
		for(int i=0;i<n;i++){
			if(a[i].mi<l){
				l-=a[i].mi;
				sum+=a[i].pi*a[i].mi;
			}
			else{
				sum+=a[i].pi*l;
				break ;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}