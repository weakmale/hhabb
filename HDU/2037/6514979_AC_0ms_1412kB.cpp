#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int o;
	int d;
}a[110];
bool cmp(node a,node b){
	return a.d<b.d;
}
int main()
{
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)
			scanf("%d %d",&a[i].o,&a[i].d);
		sort(a,a+n,cmp);
		int cnt=1;
		int t=a[0].d;
		for(int i=1;i<n;i++){
			if(a[i].o>=t){
				cnt++;
				t=a[i].d;
			}
		}
		printf("%d\n",cnt);
		
		
	}
	return 0;
}