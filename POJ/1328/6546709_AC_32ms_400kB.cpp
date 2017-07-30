#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	double left,right;
}a[1001];
bool cmp(node a,node b){
	return a.left < b.left;
}
int main()
{
	double x,y,d,temp;
	int i,cnt,n,k=0;
	bool flag;
	while(scanf("%d%lf",&n,&d)&&!(n==0&&d==0))
	{
		k++;
		flag=false;
		for(i=0;i<n;i++){
			scanf("%lf%lf",&x,&y);
			if(y > d||d<0){
				flag = true;
			}
			a[i].right = x+sqrt(d*d-y*y);
			a[i].left = x-sqrt(d*d-y*y);
		}
		if(flag){
		printf("Case %d: -1\n",k);
			continue;
		}
		sort(a,a+n,cmp);
		temp=a[0].right;
		cnt=1;
			for(i=1;i<n;i++){
			if(a[i].right <= temp){
			temp = a[i].right;
		}	
		else if(a[i].left > temp){
			cnt++;
			temp = a[i].right;
			}
			}
			printf("Case %d: %d\n",k,cnt);
		}
		return 0;
}