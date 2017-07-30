#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int o;
	int d;
	int x;
}a[110];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main()
{
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d %d",&a[i].o,&a[i].d);
			a[i].x=a[i].d-a[i].o;
		}
		int c[24]={0};
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		printf("%d--%d--%d\n",a[i].o,a[i].d,a[i].x);
		int cnt=0;
		for(int i=0;i<n;i++){
			int k=0;
			for(int j=a[i].o+1;j<a[i].d;j++)
			{
				if(c[i]){
					k=1; break;
				}
			}
			if(k)
				continue ;
			else 
			{
				cnt++;
				for(int j=a[i].o;j<a[i].d;j++)
					c[j]=1;
			}
		}
		
		printf("%d\n",cnt);
		
		
	}
	return 0;
}