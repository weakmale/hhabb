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
	while(~scanf("%d",&l),l){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].pi,&a[i].mi);
		int sum=0;
		sort(a,a+n,cmp);
		for(int i=0; i<n; i++)
        {
            if(l > a[i].mi)
            {
                sum = sum + a[i].pi*a[i].mi;
                l = l - a[i].mi;
            }
            else
            {
                sum = sum + a[i].pi*l;
                break;
            }
        }
		printf("%d\n",sum);
	}
	return 0;
}